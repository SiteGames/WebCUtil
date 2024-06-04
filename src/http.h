#ifndef HTTP_H
#define HTTP_H

static int isset_http (const char *word){
	const char * texto = GET_RESPONSE();
	char *text_copy = strdup(word);
	if (text_copy == EMPTY){
		return ERROR;
	}
	char *line = strtok(text_copy, "\n");
	while (line != EMPTY){
		if (strstr(line, texto) != EMPTY){
			free(text_copy);
			return OK;
		}
		line = strtok(EMPTY, "\n");
	}
	free(text_copy);
	return ERROR;
}

static char * get_isset_http (const char *palabra, char caracterLimite){
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

static int isset_get (const char *word){
	char true_word[1000];
	concatplus(true_word,"GET /%s",word);
	const char * texto = GET_RESPONSE();
	char *text_copy = strdup(true_word);
	if (text_copy == EMPTY){
		return ERROR;
	}
	char *line = strtok(text_copy, "\n");
	while (line != EMPTY){
		if (strstr(line, texto) != EMPTY){
			free(text_copy);
			return OK;
		}
		line = strtok(EMPTY, "\n");
	}
	free(text_copy);
	return ERROR;
}

static int isset_post (const char *word){
	char true_word[1000];
	concatplus(true_word,"POST /%s",word);
	const char * texto = GET_RESPONSE();
	char *text_copy = strdup(true_word);
	if (text_copy == EMPTY){
		return ERROR;
	}
	char *line = strtok(text_copy, "\n");
	while (line != EMPTY){
		if (strstr(line, texto) != EMPTY){
			free(text_copy);
			return OK;
		}
		line = strtok(EMPTY, "\n");
	}
	free(text_copy);
	return ERROR;
}

int _read_img(Server *s){
	FILE *image;
	long img_size;
	char *buffer;
	String rute = searchInResponse("GET /", ' ');
	if (strcmp(rute, " ") == 0){
		return ERROR;
	}
	if (strcmp(rute, "favicon.ico") == 0){
		return ERROR;
	}
	image = fopen(rute, "rb");
	if (!image){
		return ERROR;
	}
	fseek(image, 0, SEEK_END);
	img_size = ftell(image);
	fseek(image, 0, SEEK_SET);
	buffer = malloc(img_size);
	if (!buffer){
		fclose(image);
		return ERROR;
	}
	fread(buffer, 1, img_size, image);
	char response[BUFFER_SIZE];
	sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: image/jpeg\r\n\r\n", img_size);
	send(s->client_socket, response, strlen(response), 0);
	send(s->client_socket, buffer, img_size, 0);
	fclose(image);
	free(buffer);
	return OK;
}

int _read_video(Server *s){
	FILE *image;
	long img_size;
	char *buffer;
	String rute = searchInResponse("GET /", ' ');
	if (strcmp(rute, " ") == 0){
		return ERROR;
	}
	if (strcmp(rute, "favicon.ico") == 0){
		return ERROR;
	}
	image = fopen(rute, "rb");
	if (!image){
		return ERROR;
	}
	fseek(image, 0, SEEK_END);
	img_size = ftell(image);
	fseek(image, 0, SEEK_SET);
	buffer = malloc(img_size);
	if (!buffer){
		fclose(image);
		return ERROR;
	}
	fread(buffer, 1, img_size, image);
	char response[BUFFER_SIZE];
	sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: video/mp4\r\n\r\n", img_size);
	send(s->client_socket, response, strlen(response), 0);
	send(s->client_socket, buffer, img_size, 0);
	fclose(image);
	free(buffer);
	return OK;
}

static char * get_name_get (const char *palabra, char caracterLimite){
	char true_palabra[1000];
	concatplus(true_palabra,"GET /%s",palabra);
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, true_palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(true_palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

static char * get_name_post (const char *palabra, char caracterLimite){
	char true_palabra[1000];
	concatplus(true_palabra,"POST /%s",palabra);
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, true_palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(true_palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

void http (Http * h){
	h->isset = isset_http;
	h->get_isset = get_isset_http;
	h->Get.isset = isset_get;
	h->Get.read_img = _read_img;
	h->Get.read_video = _read_video;
	h->Get.get_name = get_name_get;
	h->Post.isset = isset_post;
	h->Post.post_name = get_name_post;
}

String _contentLength (){
	String palabra = "content-length: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _platform_user (){
	String palabra = "sec-ch-ua-platform: \"";
	char caracterLimite = '"';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _referer (){
	String palabra = "Referer: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _accept_language (){
	String palabra = "Accept-Language: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _host (){
	String palabra = "Host: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _connection (){
	String palabra = "Connection: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _accept (){
	String palabra = "Accept: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _accept_encoding (){
	String palabra = "Accept-Encoding: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _user_agent (){
	String palabra = "User-Agent: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

String _upgrade_insecure_requests (){
	String palabra = "Upgrade-Insecure-Requests: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else{
			return EMPTY;
		}
	}
	else{
		return EMPTY;
	}
}

void response (Response * res){
	res->contentLength = _contentLength;
	res->platform_user = _platform_user;
	res->referer = _referer;
	res->accept_language = _accept_language;
	res->host = _host;
	res->connection = _connection;
	res->accept = _accept;
	res->accept_encoding = _accept_encoding;
	res->user_agent = _user_agent;
	res->upgrade_insecure_requests = _upgrade_insecure_requests;
}

#endif
