#ifndef HTTP_H
#define HTTP_H

typedef struct{
	SSL_CTX *ctx;
	SSL *ssl;
	BIO *bio;
	int port;
	int ini;
} https;

static struct http{
	const int code;
	const char *str;
} http;

struct http status_map[] = {
	{100, "Continue"},
	{101, "Switching Protocols"},
	{200, "OK"},
	{201, "Created"},
	{202, "Accepted"},
	{203, "Non-Authoritative Information"},
	{204, "No Content"},
	{205, "Reset Content"},
	{206, "Partial Content"},
	{300, "Multiple Choices"},
	{301, "Moved Permanently"},
	{302, "Found"},
	{303, "See Other"},
	{304, "Not Modified"},
	{305, "Use Proxy"},
	{307, "Temporary Redirect"},
	{308, "Permanent Redirect"},
	{400, "Bad Request"},
	{401, "Unauthorized"},
	{402, "Payment Required"},
	{403, "Forbidden"},
	{404, "Not Found"},
	{405, "Method Not Allowed"},
	{406, "Not Acceptable"},
	{407, "Proxy Authentication Required"},
	{408, "Request Timeout"},
	{409, "Conflict"},
	{410, "Gone"},
	{411, "Length Required"},
	{412, "Precondition Failed"},
	{413, "Request Entity Too Large"},
	{414, "Request-URI Too Long"},
	{415, "Unsupported Media Type"},
	{416, "Requested Range Not Satisfiable"},
	{417, "Expectation Failed"},
	{426, "Upgrade Required"},
	{428, "Precondition Required"},
	{429, "Too Many Requests"},
	{431, "Request Header Fields Too Large"},
	{451, "Unavailable For Legal Reasons"},
	{500, "Internal Server Error"},
	{501, "Not Implemented"},
	{502, "Bad Gateway"},
	{503, "Service Unavailable"},
	{504, "Gateway Timeout"},
	{505, "HTTP Version Not Supported"},
	{506, "Variant Also Negotiates"},
	{511, "Network Authentication Required"},
	{0, NULL}
};

typedef struct{
	int (*open_)(const String, const String, const String);
	String (*load_)();
	void (*close_)();
	int (*send_)();
	int (*send_content_server)(server *);
	int (*open_local)(const String, const String);
	int status;
	String data;
	const String url;
	struct curl_slist * headers;
	int (*open_url)(const String);
	char * (*connect)(const String, const String, const String, const String, char *);
} request;

struct memoryDataRequest {
    char *memory;
    size_t size;
};

typedef struct{
	int (*search)(const char *);
	char *(*get_platform)();
	char *(*result_get)();
	char *(*referer)();
	char *(*contentLength)();
	char *(*search_post)(const char *, char);
	void (*read_img)();
	void (*read_video)(server *);
	String post;
	String get;
} requestUrls;

static int _search(const char *texto)
{
	char *word = GET_RESPONSE();
	char *text_copy = strdup(word);
	if (text_copy == NULL)
	{
		return Error;
	}
	char *line = strtok(text_copy, "\n");
	while (line != NULL)
	{
		if (strstr(line, texto) != NULL)
		{
			free(text_copy);
			return Ok;
		}
		line = strtok(NULL, "\n");
	}
	free(text_copy);
	return Error;
}

char *_search_post(const char *palabra, char caracterLimite)
{
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != NULL)
	{
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != NULL)
		{
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

int send_content_server(server *server)
{
	if (listen(server->server_fd, 3) < 0)
	{
		perror("");
		return Status_ok;
	}
	if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0)
	{
		perror("");
		return Status_error;
	}
	char *response_2[BUFFER_SIZE];
	server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
	cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", ob, response_2);
	write(server->new_socket, response_2, strlen(response_2));
	close(server->new_socket);
}

size_t write_callback(void *buffer, size_t size, size_t nmemb, void *userp)
{
	String data = (String)buffer;
	ob = data;
	return size * nmemb;
}

int open_(const String solicitud, const String params_post, const String page_url)
{
	_get = "GET";
	_post = "POST";
	if (strcmp(solicitud, _get) == 0)
	{
		result_ = Ini_request;
		resq = "GET";
		pages_request = page_url;
		return Ini_request;
	}
	else if (strcmp(solicitud, _post) == 0)
	{
		result_ = Ini_request;
		resq = "POST";
		pages_request = page_url;
		if (params_post == NULL)
		{
			printf("WebCUtils : error, post_params is NULL\n");
			return No_ini_request;
		}
		post_params_request = params_post;
		return Ini_request;
	}
	printf("WebCUtils : no ini request\n");
	return No_ini_request;
}

String load_()
{
	return ob;
}

void close_()
{
	_get = "GET";
	_post = "POST";
	pages_request = NULL;
	post_params_request = NULL;
	resq = NULL;
	result_ = '\0';
	ob = NULL;
}

int send_()
{
	if (result_ == Ini_request)
	{
		if (strcmp(resq, _get) == 0)
		{
			CURL *curl;
			CURLcode res;
			curl_global_init(CURL_GLOBAL_DEFAULT);
			curl = curl_easy_init();
			if (curl)
			{
				curl_easy_setopt(curl, CURLOPT_URL, pages_request);
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
				res = curl_easy_perform(curl);
				if (res != CURLE_OK)
				{
					return Status_error;
				}
				curl_easy_cleanup(curl);
			}
			curl_global_cleanup();
			return Status_ok;
		}
		else if (resq, _post)
		{
			CURL *curl;
			CURLcode res;
			curl_global_init(CURL_GLOBAL_DEFAULT);
			curl = curl_easy_init();
			if (curl)
			{
				curl_easy_setopt(curl, CURLOPT_URL, pages_request);
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_params_request);
				res = curl_easy_perform(curl);
				if (res != CURLE_OK)
				{
					return Status_error;
				}
				curl_easy_cleanup(curl);
			}
			curl_global_cleanup();
			return Status_ok;
		}
		else
		{
			return Status_error;
		}
	}
	return Status_error;
}

static void __connect (const String url, const String method ,int *(callback)(struct curl_slist *headers)){
	CURL *hnd = curl_easy_init();
	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, method);
    curl_easy_setopt(hnd, CURLOPT_URL, url);
    callback(header);
}

static size_t _callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct memoryDataRequest *mem = (struct memoryDataRequest *)userp;
    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if(ptr == NULL) {
        fprintf(stderr, "webCUtil: No se pudo asignar memoria\n");
        return 0;
    }
    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

static char * _connect (const String url, const String key, const String host, const String method, char * result){
	char test[1024], test2[1024];
	char * dat;
	struct memoryDataRequest chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;
	CURL *hnd = curl_easy_init();
	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, method);
    curl_easy_setopt(hnd, CURLOPT_URL, url);
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, key);
    headers = curl_slist_append(headers, host);
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, _callback);
    CURLcode ret = curl_easy_perform(hnd);
    cat_str(" ",chunk.memory,test);
    concatplus(result,test,"dataResult ");
}

void prepare_request(request *request)
{
	request->headers = NULL;
	request->connect = _connect;
	request->open_ = open_;
	request->load_ = load_;
	request->close_ = close_;
	request->send_ = send_;
	request->send_content_server = send_content_server;
}

char *_get_platform()
{
	int limite = 7;
	char *palabra = "sec-ch-ua-platform: \"";
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != NULL)
	{
		int posicionFinal = encontrado - texto + strlen(palabra);
		int longitud = limite;
		if (strlen(encontrado) - strlen(palabra) < limite)
		{
			longitud = strlen(encontrado) - strlen(palabra);
		}
		char *subcadena = (char *)malloc(longitud + 1);
		strncpy(subcadena, texto + posicionFinal, longitud);
		subcadena[longitud] = '\0';
		return subcadena;
	}
	else
	{
		return NULL;
	}
}

char *_result_get()
{
	char *palabra = "GET /";
	char *texto = GET_RESPONSE();
	char caracterLimite = 'H';
	char *encontrado = strstr(texto, palabra);
	if (encontrado != NULL)
	{
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != NULL)
		{
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

char *_referer()
{
	char *palabra = "Referer: ";
	char *texto = GET_RESPONSE();
	char caracterLimite = '\n';
	char *encontrado = strstr(texto, palabra);
	if (encontrado != NULL)
	{
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != NULL)
		{
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';

			return subcadena;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

char *_contentLength()
{
	char *palabra = "Content-Length: ";
	char *texto = GET_RESPONSE();
	char caracterLimite = '\n';
	char *encontrado = strstr(texto, palabra);
	if (encontrado != NULL)
	{
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != NULL)
		{
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

void _read_video(server *s)
{
	FILE *image;
	long img_size;
	char *buffer;
	String rute = _search_post("GET /", ' ');
	if (strcmp(rute, " ") == 0)
	{
		fprintf(stderr, "\n\n\nError no hay nombre de archivo\n\n\n\n");
		return;
	}
	if (strcmp(rute, "favicon.ico") == 0)
	{
		fprintf(stderr, "\n\n\nEl nombre del archivo es favicon.ico\n\n\n\n");
		return;
	}
	image = fopen(rute, "rb");
	if (!image)
	{
		fprintf(stderr, "\n\n\nError al abrir la imagen: %s\n\n\n\n", rute);
		return;
	}
	fseek(image, 0, SEEK_END);
	img_size = ftell(image);
	fseek(image, 0, SEEK_SET);
	buffer = malloc(img_size);
	if (!buffer)
	{
		fprintf(stderr, "Error al reservar memoria para la imagen\n");
		fclose(image);
		return;
	}
	fread(buffer, 1, img_size, image);
	char response[BUFFER_SIZE];
	sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: video/mp4\r\n\r\n", img_size);
	send(s->client_socket, response, strlen(response), 0);
	send(s->client_socket, buffer, img_size, 0);
	fclose(image);
	free(buffer);
}

void _read_img(server *s)
{
	FILE *image;
	long img_size;
	char *buffer;
	String rute = _search_post("GET /", ' ');
	if (strcmp(rute, " ") == 0)
	{
		fprintf(stderr, "\n\n\nError no hay nombre de archivo\n\n\n\n");
		return;
	}
	if (strcmp(rute, "favicon.ico") == 0)
	{
		fprintf(stderr, "\n\n\nEl nombre del archivo es favicon.ico\n\n\n\n");
		return;
	}
	image = fopen(rute, "rb");
	if (!image)
	{
		fprintf(stderr, "\n\n\nError al abrir la imagen: %s\n\n\n\n", rute);
		return;
	}
	fseek(image, 0, SEEK_END);
	img_size = ftell(image);
	fseek(image, 0, SEEK_SET);
	buffer = malloc(img_size);
	if (!buffer)
	{
		fprintf(stderr, "Error al reservar memoria para la imagen\n");
		fclose(image);
		return;
	}
	fread(buffer, 1, img_size, image);
	char response[BUFFER_SIZE];
	sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: image/jpeg\r\n\r\n", img_size);
	send(s->client_socket, response, strlen(response), 0);
	send(s->client_socket, buffer, img_size, 0);
	fclose(image);
	free(buffer);
}

void ini_get(requestUrls *g)
{
	g->search = _search;
	g->get_platform = _get_platform;
	g->result_get = _result_get;
	g->referer = _referer;
	g->contentLength = _contentLength;
	g->search_post = _search_post;
	g->read_img = _read_img;
	g->read_video = _read_video;
}

#endif
