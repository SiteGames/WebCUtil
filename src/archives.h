#ifndef ARCHIVES_H
#define ARCHIVES_H

static String _getName(){
	char *resultStr = searchInResponse("filename=\"", '"');
	if (resultStr != EMPTY){
		return resultStr;
	}
	return EMPTY;
}

static String _getSize(){
	char *resultStr = searchInResponse("Content-Length: ", '\0');
	if (resultStr != EMPTY){
		return resultStr;
	}
	return EMPTY;
}

static int _Ok(){
	String text = GET_RESPONSE();
	char *word = "Content-Length";
	char *text_copy = strdup(text);
	char *line = strtok(text_copy, "\n");
	while (line != EMPTY){
		if (strstr(line, word) != EMPTY){
			return OK;
		}
		line = strtok(EMPTY, "\n");
	}
	free(text_copy);
	return ERROR;
}

String _getType(){
	char *resultStr = searchInResponse("Content-Type:", '\0');
	if (resultStr != EMPTY){
		return resultStr;
	}
	return EMPTY;
}

static int _prepare_file(Server *s){
	end_of_header = strstr(buffer, "\r\n\r\n");
	if (end_of_header != EMPTY){
		body_offset = end_of_header + 4 - buffer;
		pre = 1;
		content_file = buffer + body_offset;
		length = s->valread - body_offset;
	}
	else{
		puts("webCUtil: not have content file");
		pre = 0;
		return NOT_FOUND;
	}
}

static int _upload_file(const String s){
	FILE *file = fopen(s, "wb");
	if (pre == 1){
		if (file != EMPTY){
			fwrite(content_file, sizeof(char), length, file);
			fclose(file);
			pre = 0;
			return OK;
		}
		else{
			perror("webCUtil ");
			pre = 0;
			return NOT_FOUND;
		}
	}
	else{
		puts("webCUtil: prepare() not declared");
		pre = 0;
		return OK;
	}
	fclose(file);
}

static void _resetStructData(){
	pre = 0;
	length = 0;
	body_offset = 0;
	memset(content_file, 0, sizeof(content_file));
	memset(end_of_header, 0, sizeof(end_of_header));
}

static int _permission_download_file(Server *Server){
	String fileName = searchInResponse("GET /", ' ');
	FILE *fp = fopen(fileName, "rb");
	size_t bytes_read;
	char r_headers_1[BUFFER_SIZE];
	concatplus(r_headers_1, "HTTP/1.1 200 OK\r\nContent-Disposition: attachment; filename=\"%s\" \r\nContent-Type: text/plain\r\n\r\n", fileName);
	if (fp == EMPTY){
		perror("WebCUtil ");
		return NOT_FOUND;
	}
	else{
		send(Server->client_socket, r_headers_1, strlen(r_headers_1), 0);
		while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0){
			send(Server->client_socket, buffer, bytes_read, 0);
		}
		fclose(fp);
		return OK;
	}
	fclose(fp);
	return NOT_FOUND;
}

static int _send_file(Server *s, const char *filename){
	String filename2 = searchInResponse("GET /", ' ');
	if (strcmp(filename2, filename) == 0){
		FILE *file = fopen(filename, "rb");
		if (file == EMPTY){
			fprintf(stderr, "Error opening file\n");
			return NOT_FOUND;
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
		return OK;
	}
	return NOT_FOUND;
}

static void _create_file (const String nombre, const String data, const String r){
	FILE * fp = fopen(nombre,r);
	if (fp == EMPTY){
		perror("WebCUtil ");
		return;
	}
	fprintf(fp, "%s", data);
	fclose(fp);
}

void archives (Archives *f)
{
	f->name_archive = _getName;
	f->size_archive = _getSize;
	f->type_archive = _getType;
	f->prepare_save = _prepare_file;
	f->save = _upload_file;
	f->isset_archive = _Ok;
	f->upload = _send_file;
	f->create_archive = _create_file;
}

#endif
