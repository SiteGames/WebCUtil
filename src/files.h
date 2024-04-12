#ifndef FILES_H
#define FILES_H

typedef struct{
	String (*getName)();
	String (*getSize)();
	String (*getType)();
	int (*prepare_file)(server *);
	int (*upload_file)(const String );
	int (*have_file)();
	int (*send_file)(server *, const char *);
	void (*resetStructData)();
	String name_file;
	String type_file;
	String length_file;
} files;

static String _getName()
{
	char *resultStr = _search_post("filename=\"", '"');
	if (resultStr != NULL)
	{
		return resultStr;
	}
	return NULL;
}

static String _getSize()
{
	char *resultStr = _search_post("Content-Length: ", '\0');
	if (resultStr != NULL)
	{
		return resultStr;
	}
	return NULL;
}

static int _have_file()
{
	String text = GET_RESPONSE();
	char *word = "Content-Length";
	char *text_copy = strdup(text);
	char *line = strtok(text_copy, "\n");
	while (line != NULL)
	{
		if (strstr(line, word) != NULL)
		{
			return Have_file;
		}
		line = strtok(NULL, "\n");
	}
	free(text_copy);
	return No_have_file;
}

String _getType()
{
	char *resultStr = _search_post("Content-Type:", '\0');
	if (resultStr != NULL)
	{
		return resultStr;
	}
	return NULL;
}

static int _prepare_file(server *s)
{
	end_of_header = strstr(buffer, "\r\n\r\n");
	if (end_of_header != NULL)
	{
		body_offset = end_of_header + 4 - buffer;
		pre = 1;
		content_file = buffer + body_offset;
		length = s->valread - body_offset;
	}
	else
	{
		puts("webCUtil: not have content file");
		pre = 0;
		return Error_file;
	}
}

static int _upload_file(const String s)
{
	FILE *file = fopen(s, "wb");
	if (pre == 1)
	{
		if (file != NULL)
		{
			fwrite(content_file, sizeof(char), length, file);
			fclose(file);
			pre = 0;
			return Ok_file;
		}
		else
		{
			perror("webCUtil ");
			pre = 0;
			return Error_file;
		}
	}
	else
	{
		puts("webCUtil: prepare() not declared");
		pre = 0;
		return Ok_file;
	}
	fclose(file);
}

static void _resetStructData()
{
	pre = 0;
	length = 0;
	body_offset = 0;
	memset(content_file, 0, sizeof(content_file));
	memset(end_of_header, 0, sizeof(end_of_header));
}

static int _permission_download_file(server *server)
{
	String fileName = _search_post("GET /", ' ');
	FILE *fp = fopen(fileName, "rb");
	size_t bytes_read;
	char r_headers_1[BUFFER_SIZE];
	concatplus(r_headers_1, "HTTP/1.1 200 OK\r\nContent-Disposition: attachment; filename=\"%s\" \r\nContent-Type: text/plain\r\n\r\n", fileName);
	if (fp == NULL)
	{
		perror("WebCUtil ");
		return Error_file;
	}
	else
	{
		send(server->client_socket, r_headers_1, strlen(r_headers_1), 0);
		while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0)
		{
			send(server->client_socket, buffer, bytes_read, 0);
		}
		fclose(fp);
		return Ok_file;
	}
	fclose(fp);
	return Error_file;
}

static int _send_file(server *s, const char *filename)
{
	String filename2 = _search_post("GET /", ' ');
	if (strcmp(filename2, filename) == 0)
	{
		FILE *file = fopen(filename, "rb");
		if (file == NULL)
		{
			fprintf(stderr, "Error opening file\n");
			return Error_file;
		}
		fseek(file, 0, SEEK_END);
		long file_size = ftell(file);
		fseek(file, 0, SEEK_SET);
		char *file_contents = malloc(file_size);
		fread(file_contents, 1, file_size, file);
		fclose(file);
		char response[1024];
		snprintf(response, sizeof(response),
				 "HTTP/1.1 200 OK\r\n"
				 "Content-Length: %ld\r\n"
				 "Content-Disposition: attachment; filename=\"%s\"\r\n"
				 "Content-Type: application/octet-stream\r\n\r\n",
				 file_size, filename);
	    printf("Content-Length: %ld\nfilename=\"%s\"",file_size, filename);
		send(s->client_socket, response, strlen(response), 0);
		send(s->client_socket, file_contents, file_size, 0);
		free(file_contents);
		return Ok_file;
	}
	return Error_file;
}

void ini_files(files *f)
{
	f->getName = _getName;
	f->getSize = _getSize;
	f->getType = _getType;
	f->prepare_file = _prepare_file;
	f->upload_file = _upload_file;
	f->have_file = _have_file;
	f->send_file = _send_file;
	f->resetStructData = _resetStructData;
}

#endif
