#ifndef SERVER_H
#define SERVER_H

static void _decrypt(char *message, int shift)
{
	char *ptr = message;
	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr = (*ptr - 'a' - shift + 26) % 26 + 'a';
		}
		else if (*ptr >= 'A' && *ptr <= 'Z')
		{
			*ptr = (*ptr - 'A' - shift + 26) % 26 + 'A';
		}
		ptr++;
	}
}

static void _encrypt(char *message, int shift)
{
	char *ptr = message;
	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr = (*ptr - 'a' + shift) % 26 + 'a';
		}
		else if (*ptr >= 'A' && *ptr <= 'Z')
		{
			*ptr = (*ptr - 'A' + shift) % 26 + 'A';
		}
		ptr++;
	}
}

static String load_buffer()
{
	return buffer;
}

static char *descryptChar(char *txt)
{
	String today[42] = {
		"%25",		 // %
		"%5C",		 //espace
		"+",		 // espacio
		"%7C",		 // |
		"%3D",		 // =
		"%5B",		 // [
		"%5D",		 // ]
		"%3C",		 // <
		"%3E",		 // >
		"%7B",		 // {
		"%7D",		 // }
		"%23",		 // #
		"%E2%82%AC", // €
		"%26",		 // &
		"%28",		 // (
		"%29",		 // )
		"%22",		 // "
		"%27",		 // '
		"%3A",		 // :
		"%3B",		 // ;
		"%21",		 // !
		"%3F",		 // ?
		"%C2%A9",	 // ©
		"%24",		 // $
		"%CF%80",	 // π
		"%40",		 //@
		"%7E",		 //~
		"%60",		 //`
		"%E2%80%A2", //•
		"%E2%88%9A", //√
		"%C3%B7",	 //÷
		"%C3%97",	 //×
		"%C2%A7",	 //§
		"%E2%88%86", //∆
		"%C2%A3",	 //£
		"%C2%A5",	 //¢
		"%C2%A2",	 //^
		"%C2%B0",	 //°
		"%C2%AE",	 //®
		"%E2%84%A2", //™
		"%E2%9C%93", //✓
	};
	if (strcmp(txt, today[0]) == 0)
	{
		return "%";
	}
	if (strcmp(txt, today[1]) == 0)
	{
		return "\\";
	}
	if (strcmp(txt, today[2]) == 0)
	{
		return " ";
	}
	if (strcmp(txt, today[3]) == 0)
	{
		return "|";
	}
	if (strcmp(txt, today[4]) == 0)
	{
		return "=";
	}
	if (strcmp(txt, today[5]) == 0)
	{
		return "[";
	}
	if (strcmp(txt, today[6]) == 0)
	{
		return "]";
	}
	if (strcmp(txt, today[7]) == 0)
	{
		return "<";
	}
	if (strcmp(txt, today[8]) == 0)
	{
		return ">";
	}
	if (strcmp(txt, today[9]) == 0)
	{
		return "{";
	}
	if (strcmp(txt, today[10]) == 0)
	{
		return "}";
	}
	if (strcmp(txt, today[11]) == 0)
	{
		return "#";
	}
	if (strcmp(txt, today[12]) == 0)
	{
		return "€";
	}
	if (strcmp(txt, today[13]) == 0)
	{
		return "&";
	}
	if (strcmp(txt, today[14]) == 0)
	{
		return "(";
	}
	if (strcmp(txt, today[15]) == 0)
	{
		return ")";
	}
	if (strcmp(txt, today[16]) == 0)
	{
		return "\"";
	}
	if (strcmp(txt, today[17]) == 0)
	{
		return "'";
	}
	if (strcmp(txt, today[18]) == 0)
	{
		return ":";
	}
	if (strcmp(txt, today[19]) == 0)
	{
		return ";";
	}
	if (strcmp(txt, today[20]) == 0)
	{
		return "!";
	}
	if (strcmp(txt, today[21]) == 0)
	{
		return "?";
	}
	if (strcmp(txt, today[22]) == 0)
	{
		return "©";
	}
	if (strcmp(txt, today[23]) == 0)
	{
		return "$";
	}
	if (strcmp(txt, today[24]) == 0)
	{
		return "π";
	}
	if (strcmp(txt, today[25]) == 0)
	{
		return "@";
	}
	if (strcmp(txt, today[26]) == 0)
	{
		return "~";
	}
	if (strcmp(txt, today[27]) == 0)
	{
		return "`";
	}
	if (strcmp(txt, today[28]) == 0)
	{
		return "•";
	}
	if (strcmp(txt, today[29]) == 0)
	{
		return "√";
	}
	if (strcmp(txt, today[30]) == 0)
	{
		return "÷";
	}
	if (strcmp(txt, today[31]) == 0)
	{
		return "×";
	}
	if (strcmp(txt, today[32]) == 0)
	{
		return "§";
	}
	if (strcmp(txt, today[33]) == 0)
	{
		return "∆";
	}
	if (strcmp(txt, today[34]) == 0)
	{
		return "£";
	}
	if (strcmp(txt, today[35]) == 0)
	{
		return "¥";
	}
	if (strcmp(txt, today[36]) == 0)
	{
		return "¢";
	}
	if (strcmp(txt, today[37]) == 0)
	{
		return "^";
	}
	if (strcmp(txt, today[38]) == 0)
	{
		return "°";
	}
	if (strcmp(txt, today[39]) == 0)
	{
		return "®";
	}
	if (strcmp(txt, today[40]) == 0)
	{
		return "™";
	}
	if (strcmp(txt, today[41]) == 0)
	{
		return "✓";
	}
	return EMPTY;
}

void concatplus(char *result, const char *format, ...)
{
	va_list args;
	va_start(args, format);
	va_list args_copy;
	va_copy(args_copy, args);
	int length = vsnprintf(EMPTY, 0, format, args_copy);
	va_end(args_copy);
	vsnprintf(result, length + 1, format, args);
	va_end(args);
}

static int _rebuilt_file(const String fp, const String console, int time)
{
	struct stat file_data;
	if (stat(fp, &file_data) == -1)
	{
		perror("WebCUtil ");
		return ERROR;
	}
	time_t last_modified = file_data.st_mtime;
	usleep(time);
	if (stat(fp, &file_data) == -1)
	{
		perror("WebCUtil ");
		return ERROR;
	}
	time_t new_modified = file_data.st_mtime;
	if (last_modified != new_modified)
	{
		return OK;
	}
	else
	{
		system(console);
	}
}

static int _save_response(const char *namefile)
{
	char finalFile[100];
	concatplus(finalFile, "%s.log", namefile);
	FILE *fp = fopen(finalFile, "a");
	if (fp == EMPTY)
	{
		return ERROR;
	}
	fprintf(fp, "%s", GET_RESPONSE());
	fclose(fp);
	return OK;
}

String parseInt(int entero)
{
	int len = snprintf(EMPTY, 0, "%d", entero);
	String str = malloc(len + 1);
	snprintf(str, len + 1, "%d", entero);
	return str;
}

String parseFloat(double flotante)
{
	int len = snprintf(EMPTY, 0, "%.2f", flotante);
	String str = malloc(len + 1);
	snprintf(str, len + 1, "%.2f", flotante);
	return str;
}

int parseStr(String str)
{
	return atoi(str);
}

char *searchInResponse(const char *palabra, char caracterLimite)
{
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY)
	{
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY)
		{
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else
		{
			return EMPTY;
		}
	}
	else
	{
		return EMPTY;
	}
}

char *searchWord(const char *texto, const char *palabra, char caracterLimite)
{
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY)
	{
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY)
		{
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else
		{
			return EMPTY;
		}
	}
	else
	{
		return EMPTY;
	}
}

int search_w(const char *word, const char *texto)
{
	char *text_copy = strdup(word);
	if (text_copy == EMPTY)
	{
		return ERROR;
	}
	char *line = strtok(text_copy, "\n");
	while (line != EMPTY)
	{
		if (strstr(line, texto) != EMPTY)
		{
			free(text_copy);
			return OK;
		}
		line = strtok(EMPTY, "\n");
	}
	free(text_copy);
	return ERROR;
}

int _save(const String fp, const String key, const String value, const String comentarios)
{
	if (fp == EMPTY)
	{
		fprintf(stderr, "Name file is EMPTY\n");
		return EMPTY;
	}
	char tmp[100];
	char data[2024];
	concatplus(tmp, "%s.dat", fp);
	FILE *f = fopen(tmp, "a"), *f2 = fopen(tmp, "r");
	if (f == EMPTY || f2 == EMPTY)
	{
		perror("WebCUtil ");
		fclose(f2);
		fclose(f);
		return ERROR;
	}
	if (key == EMPTY || value == EMPTY)
	{
		fprintf(stderr, "Key or Value is EMPTY\n");
		fclose(f2);
		fclose(f);
		return ERROR;
	}
	fread(data, sizeof(char), 2024, f2);
	int res = search_w(data, key);
	if (res == OK)
	{
		fprintf(stderr, "Key existente\n");
		fclose(f2);
		fclose(f);
		return ERROR;
	}
	if (comentarios == EMPTY)
	{
		fprintf(f, "%s=%s\n", key, value);
	}
	else
	{
		fprintf(f, "/*%s*/\n%s=%s\n", comentarios, key, value);
	}
	fclose(f2);
	fclose(f);
	return OK;
}

String _getValue(const String name, const String key, const String value)
{
	if (name == EMPTY)
	{
		fprintf(stderr, "Name file is EMPTY\n");
		return EMPTY;
	}
	if (key == EMPTY)
	{
		fprintf(stderr, "Key is EMPTY\n");
		return EMPTY;
	}
	char tmp[100];
	char data[2024];
	char tmp2[100];
	String result;
	concatplus(tmp2, "%s=", key);
	concatplus(tmp, "%s.dat", name);
	FILE *fp = fopen(tmp, "r");
	if (fp == EMPTY)
	{
		return EMPTY;
	}
	fread(data, sizeof(char), 2024, fp);
	result = searchWord(data, tmp2, '\n');
	if (strcmp(result, "") == 0)
	{
		result = value;
	}
	if (strcmp(result, " ") == 0)
	{
		result = value;
	}
	fclose(fp);
	return result;
}

String _getDat(const String d)
{
	if (d == NULL)
	{
		fprintf(stderr, "Name file is EMPTY\n");
		return ERROR;
	}
	char tmp[100];
	char data[2024];
	String result;
	concatplus(tmp, "%s.dat", d);
	FILE *fp = fopen(tmp, "r");
	if (fp == NULL)
	{
		perror("WebCUtil ");
		return EMPTY;
	}
	fread(data, sizeof(char), 2024, fp);
	result = data;
	return result;
}

int _quit(const String fp)
{
	if (fp == NULL)
	{
		fprintf(stderr, "Name file is EMPTY\n");
		return ERROR;
	}
	char tmp[100];
	concatplus(tmp, "%s.dat", fp);
	if (remove(tmp) == -1)
	{
		perror("WebCUtil ");
		return ERROR;
	}
	else
	{
		return OK;
	}
}

static const char *getExtension(const char *nombreArchivo)
{
	const char *punto = strrchr(nombreArchivo, '.');
	if (!punto || punto == nombreArchivo)
		return "";
	return punto + 1;
}

int compareExtension(const char *archivo1, const char *archivo2)
{
	const char *extension1 = getExtension(archivo1);
	const char *extension2 = getExtension(archivo2);

	if (strcmp(extension1, extension2) == 0)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

static int _registers_url(){
	char urls[2024];
	int acumulativo_errores = 0, i_ini = 0;;
	FILE *fp = fopen("res/pages.urls", "rb");
	if (fp == EMPTY){
		return ERROR;
	}
	size_t size = fread(urls, sizeof(char), 2024, fp);
	String fileTheGet = searchWord(GET_RESPONSE(), "GET /", ' ');
	String isCExtension = strrchr(fileTheGet,'.c');//search_w(".c", fileTheGet);
	if (isCExtension != EMPTY){
		for (int i = 1; i < size; i++){
			char cat[100];
			concatplus(cat, "#define URL_%s ", parseInt(i));
			String result = searchWord(urls, cat, '\n');
			if (result != EMPTY){
				if(strcmp(fileTheGet,result) == 0){
					return OK;
				} else {
					acumulativo_errores++;
					i_ini = i;
				}
			} else {
				return ERROR;
			}
		}
		if(acumulativo_errores >= i_ini){
			return NOT_FOUND;
		}
	} else{
		return ERROR;
	}
	fclose(fp);
	return OK;
}

void properties(Properties *p)
{
	p->save = _save;
	p->delete = _quit;
	p->getValue = _getValue;
	p->getDat = _getDat;
}

int openServer(Server *server)
{
	server->opt = 1;
	server->addrlen = sizeof(server->address);
	server->load_buffer = load_buffer;
	server->decrypt = _decrypt;
	server->encrypt = _encrypt;
	server->descryptCharURL = descryptChar;
	server->saveBuffer = _save_response;
	server->rebuilt_file = _rebuilt_file;
	server->registers_url = _registers_url;
	if ((server->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		return ERROR;
	}
	if (setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &server->opt, sizeof(server->opt)))
	{
		return ERROR;
	}
	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = inet_addr(server->url);
	server->address.sin_port = htons(server->port);
	if (bind(server->server_fd, (struct sockaddr *)&server->address, sizeof(server->address)) < 0)
	{
		return ERROR;
	}
	if (listen(server->server_fd, 3) < 0)
	{
		return ERROR;
	}
	return OK;
}

int open_server(Server *server)
{
	server->opt = 1;
	server->addrlen = sizeof(server->address);
	server->load_buffer = load_buffer;
	server->decrypt = _decrypt;
	server->encrypt = _encrypt;
	server->descryptCharURL = descryptChar;
	server->saveBuffer = _save_response;
	server->rebuilt_file = _rebuilt_file;
	server->registers_url = _registers_url;
	if ((server->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		return ERROR;
	}
	if (setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &server->opt, sizeof(server->opt)))
	{
		return ERROR;
	}
	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = INADDR_ANY;
	server->address.sin_port = htons(server->port);
	if (bind(server->server_fd, (struct sockaddr *)&server->address, sizeof(server->address)) < 0)
	{
		return ERROR;
	}
	if (listen(server->server_fd, 3) < 0)
	{
		return ERROR;
	}
	return OK;
}

#endif
