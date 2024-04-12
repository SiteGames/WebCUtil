#ifndef SERVER_H
#define SERVER_H

enum{
	BAD = -1,
	OK
}ErrorsServer;

static String load_buffer()
{
	return buffer;
}

typedef struct
{
	int buffer_size_web;
	int server_fd, new_socket, valread, client_socket;
	struct sockaddr_in address, client_address;
	socklen_t client_address_length;
	int opt;
	int addrlen;
	int error;
	int port;
	String url;
	int buffer_file;
	int buffer_img;
	char cookie_time[30];
	char cookie_file_name[V];
	int cookie_active;
	int (*reset)();
	int (*close)();
	String (*load_buffer)();
	jit (*page_404)(const String, const String);
	String (*requestedURL)();
	void (*decrypt)(char *, int);
	void (*encrypt)(char *, int);
	char *(*descryptCharURL)(char *);
	int (*saveBuffer)(const String);
} server;

static int _save_response(const char *namefile)
{
	FILE *fp = fopen(namefile, "a");
	if (fp == NULL)
	{
		return Web_error;
	}
	fprintf(fp, "%s", GET_RESPONSE());
	fclose(fp);
	return Web_ok;
}

String to_str (int entero){
	int len = snprintf(NULL, 0, "%d", entero);
	String str = malloc(len + 1);
	snprintf(str, len + 1, "%d", entero);
	return str;
}

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

char *descryptChar(char *txt){
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
	return NULL;
}

void get_date(date *date)
{
	time_t tiempo;
	struct tm *tm_info;
	time(&tiempo);
	tm_info = localtime(&tiempo);
	strftime(date->current_date, 20, "%Y-%m-%d", tm_info);
}

void get_time(date *date)
{
	time_t tiempo;
	struct tm *tm_info;
	time(&tiempo);
	tm_info = localtime(&tiempo);
	strftime(date->hour, 9, "%H:%M:%S", tm_info);
}

int openServer(server *server)
{
	server->opt = 1;
	server->addrlen = sizeof(server->address);
	server->load_buffer = load_buffer;
	server->decrypt = _decrypt;
	server->encrypt = _encrypt;
	server->descryptCharURL = descryptChar;
	server->saveBuffer = _save_response;
	if ((server->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		return BAD;
	}
	if (setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &server->opt, sizeof(server->opt)))
	{
		return BAD;
	}
	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = inet_addr(server->url);
	server->address.sin_port = htons(server->port);
	if (bind(server->server_fd, (struct sockaddr *)&server->address, sizeof(server->address)) < 0)
	{
		return BAD;
	}
	if (listen(server->server_fd, 3) < 0)
	{
		return BAD;
	}
	return OK;
}

int open_server(server *server)
{
	server->opt = 1;
	server->addrlen = sizeof(server->address);
	server->load_buffer = load_buffer;
	server->decrypt = _decrypt;
	server->encrypt = _encrypt;
	if ((server->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		return BAD;
	}
	if (setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &server->opt, sizeof(server->opt)))
	{
		return BAD;
	}
	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = INADDR_ANY;
	server->address.sin_port = htons(server->port);
	if (bind(server->server_fd, (struct sockaddr *)&server->address, sizeof(server->address)) < 0)
	{
		return BAD;
	}
	if (listen(server->server_fd, 3) < 0)
	{
		return BAD;
	}
	return OK;
}

int send_email(email *email)
{
	CURL *curl;
	CURLcode res = CURLE_OK;
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, email->smtp_url);
		curl_easy_setopt(curl, CURLOPT_MAIL_FROM, email->mail_from);
		struct curl_slist *recipients = NULL;
		recipients = curl_slist_append(recipients, email->recipient);
		curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
		curl_easy_setopt(curl, CURLOPT_USERNAME, email->smtp_user);
		curl_easy_setopt(curl, CURLOPT_PASSWORD, email->smtp_password);
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
		curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
		curl_easy_setopt(curl, CURLOPT_READDATA, email->payload_text);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
			fprintf(stderr, "%s\n", curl_easy_strerror(res));

		curl_slist_free_all(recipients);
		curl_easy_cleanup(curl);
	}
	return (int)res;
}

#endif
