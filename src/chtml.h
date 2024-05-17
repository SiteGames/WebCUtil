#ifndef CHTML_H
#define CHTML_H

typedef struct {
	void (*prepare)(const String);
	int (*send)(server *);
	void (*reset_tmp)();
	void (*show_code)();
	void (*show_html)();
}Chtml;

char code_chtml[BUFFER_SIZE_3] = " ";
char temporal_chtml[BUFFER_SIZE_3] = " ";

static char * buscar(const char *texto, const char *palabra, const char *limite)
{
	const char *inicio = strstr(texto, palabra);
	if (inicio == NULL)
	{
		return NULL;
	}
	const char *inicio_copia = inicio + strlen(palabra);
	if (*inicio_copia != '\0')
	{
		inicio_copia++;
	}
	const char *fin_copia = strstr(inicio_copia, limite);
	if (fin_copia == NULL)
	{
		fin_copia = inicio_copia + strlen(inicio_copia); // Si el limite no se encuentra, copiar hasta el final del texto
	}
	size_t longitud = fin_copia - inicio_copia;
	char *texto_copiado = (char *)malloc(longitud + 1);
	if (texto_copiado == NULL)
	{
		return NULL;
	}
	strncpy(texto_copiado, inicio_copia, longitud);
	texto_copiado[longitud] = '\0';
	return texto_copiado;
}

static int buscar_palabra(const char* palabra, const char* texto) {
    const char* encontrado = strstr(texto, palabra);
    if (encontrado != NULL) {
        return 1;
    } else {
        return -1;
    }
}

static void _prepare (const String name_file){
	char tmp[100];
	concatplus(tmp, "%s.chtml", name_file);
	FILE *fp = fopen(tmp, "r");
	if (fp == NULL)
	{
		perror("WebCUtil ");
		return;
	}
	char data[2024];
	fread(data,sizeof(char),2024,fp);
	char tmp1[HTML_LONG];
	int res = buscar_palabra("#include \"html.h\"\n",data);
	if(res != -1){
		char * result1 = buscar(data,"html main (){","};");
		if(result1 != NULL){
			free(result1);
		} else {
			fprintf(stderr, "No se encuentra 'html main' en '%s.chtml'\n",name_file);
		    exit(1);
		}
		char * result2 = buscar(data,"html style (){","};\n}");
		if(result2 != NULL){
			free(result2);
		} else {
			fprintf(stderr, "No se encuentra 'html style' en '%s.chtml'\n",name_file);
		    exit(1);
		}
		char * result3 = buscar(data,"html script (){","};");
		if(result3 != NULL){
			concatplus(temporal_chtml,"<!DOCTYPE html>\n<html>\n<style>\n%s\n</style>\n%s\n<script>\n%s\n</script>\n</html>",result2,result1,result3);
			concatplus(code_chtml,"%s",data);
			free(result3);
		} else {
			fprintf(stderr, "No se encuentra 'html script' en '%s.chtml'\n",name_file);
		    exit(1);
		}
	} else {
		fprintf(stderr, "No se encuentra el '#include \"html.h\"' en '%s.chtml'\n",name_file);
		exit(1);
	}
	fclose(fp);
}

static int _send_chtml (server * server){
	if(strcmp(temporal_chtml," ") == 0 || temporal_chtml == NULL){
		fprintf(stderr, "No existe ningun archivo");
		exit(1);
	}
	if (listen(server->server_fd, 3) < 0){
        return Html_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        return Html_error;
    }
    char *response_2[BUFFER_SIZE];
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", temporal_chtml, response_2);
    write(server->new_socket, response_2, strlen(response_2));
    close(server->new_socket);
    return Html_ok;
}

static void _reset_chtml (){
	memset(temporal_chtml, 0, sizeof(temporal_chtml));
}

static void _show_code (){
	printf("chtml len (%ld):\n%s\n",strlen(code_chtml),code_chtml);
}

static void _show_html (){
	printf("html len (%ld):\n%s\n",strlen(temporal_chtml),temporal_chtml);
}

void chtml(Chtml * ch){
	ch->prepare = _prepare;
	ch->send = _send_chtml;
	ch->reset_tmp = _reset_chtml;
	ch->show_code = _show_code;
	ch->show_html = _show_html;
}

#endif
