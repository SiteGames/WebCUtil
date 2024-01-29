#ifndef WEBCUTIL_H
#define WEBCUTIL_H

#include <sqlite3.h>
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

#include "def.h"
#include "webcutiltypeof.h"

static int long_buffer_size = BUFFER_SIZE;
char *_post;
char *_get;
char cookie_value[30];
String ob;
char * ress;
String _get;
String _post;
int result_;
String resq;
PAGE_URL pages_request;
String post_params_request;
char buffer[BUFFER_SIZE] = {0};
char buffer_2[BUFFER_SIZE][BUFFER_SIZE];
String Response;

#define GET_RESPONSE() buffer
#include "html.h"

static String load_buffer (){
    return buffer;
}

int ini_ssl (https * s){
    SSL_library_init();
    ERR_load_BIO_strings();
    SSL_load_error_strings();
    s->ini = 1;
    return Web_ok;
}

int contex_ssl (https * s, const String cert, const String key){
    s->ctx = SSL_CTX_new(SSLv23_server_method());
    SSL_CTX_use_certificate_file(s->ctx, cert, SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(s->ctx, key, SSL_FILETYPE_PEM);
    return Web_ok;
}

void server_file_response(int client_socket, const char *content_type, const char *content){
    char response[BUFFER_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\nContent-Type: %s\nContent-Length: %lu\n\n%s", content_type, strlen(content), content);
    write(client_socket, response, strlen(response));
}

void where(const char *condition, void (*func_1)(), void (*func_2)()){
    if (condition){
        func_1();
    }
    else{
        func_2();
    }
}

int create_file(const String name, const String data, const String read){
    FILE * fp = fopen(name,read);
    if(fp == NULL){
        return Error;
    } 
    fprintf(fp,"%s",data);
    fclose(fp);
    return Ok;
}

static int _search (const char * texto){
	char * word = GET_RESPONSE();
	char *text_copy = strdup(word);
    if (text_copy == NULL) {
        return Error;
    }
    char *line = strtok(text_copy, "\n");
    while (line != NULL) {
        if (strstr(line, texto) != NULL) {
            free(text_copy);
            return Ok;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error;
}

char* _get_platform (){
	int limite = 7;
	char * palabra = "sec-ch-ua-platform: \"";
	char * texto = GET_RESPONSE();
	char* encontrado = strstr(texto, palabra);
    if (encontrado != NULL) {
        int posicionFinal = encontrado - texto + strlen(palabra);
        int longitud = limite;
        if (strlen(encontrado) - strlen(palabra) < limite) {
            longitud = strlen(encontrado) - strlen(palabra);
        }
        char* subcadena = (char*)malloc(longitud + 1);
        strncpy(subcadena, texto + posicionFinal, longitud);
        subcadena[longitud] = '\0';
        return subcadena;
    } else {
        return NULL;
    }
}

char * _result_get (){
	char * palabra = "GET /";
	char * texto = GET_RESPONSE();
	char caracterLimite = 'H';
	char* encontrado = strstr(texto, palabra);
    if (encontrado != NULL) {
        size_t posicionFinal = encontrado - texto + strlen(palabra);
        const char* limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != NULL) {
            size_t longitud = limite - (texto + posicionFinal);
            char* subcadena = (char*)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

char * _referer (){
	char * palabra = "Referer: ";
	char * texto = GET_RESPONSE();
	char caracterLimite = '\n';
	char* encontrado = strstr(texto, palabra);
    if (encontrado != NULL) {
        size_t posicionFinal = encontrado - texto + strlen(palabra);
        const char* limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != NULL) {
            size_t longitud = limite - (texto + posicionFinal);
            char* subcadena = (char*)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';

            return subcadena;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

char * _contentLength (){
	char * palabra = "Content-Length: ";
	char * texto = GET_RESPONSE();
	char caracterLimite = '\n';
	char* encontrado = strstr(texto, palabra);
    if (encontrado != NULL) {
        size_t posicionFinal = encontrado - texto + strlen(palabra);
        const char* limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != NULL) {
            size_t longitud = limite - (texto + posicionFinal);
            char* subcadena = (char*)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

char * _search_post (const char * palabra, char caracterLimite){
	char * texto = GET_RESPONSE();
	char* encontrado = strstr(texto, palabra);
    if (encontrado != NULL) {
        size_t posicionFinal = encontrado - texto + strlen(palabra);
        const char* limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != NULL) {
            size_t longitud = limite - (texto + posicionFinal);
            char* subcadena = (char*)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void ini_get (requestUrls * g){
	g->search = _search;
	g->get_platform = _get_platform;
	g->result_get =_result_get;
	g->referer = _referer;
	g->contentLength = _contentLength;
	g->search_post = _search_post;
}

void split_lines(const char *text){
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        printf("%s\n", line);
        line = strtok(NULL, "\n");
    }
    free(text_copy);
}

int search_words(const char *text, const char *word){
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        if (strstr(line, word) != NULL){
            return Ok;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error;
}

int searchWordPost (const char *word){
    const char *text = GET_RESPONSE();
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        if (strstr(line, word) != NULL){
            return Ok;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error;
}

static jit page_404 (const String text, const String word){
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        if (strstr(line, word) != NULL){
            return Ok;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error;
}

Array * create_array_int(Array *Array, ...){
    array *Arra = malloc(Array->Int.range * sizeof(array));
    Array->Int.length = Array->Int.range;
    va_list valist;
    va_start(valist, Array->Int.range);
    for (Array->i = 0; Array->i < Array->Int.range; Array->i++){
        array x = va_arg(valist, array);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Int.range; Array->i++){
        Array->Int.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_results(Array *Array, ...){
    array *Arra = malloc(Array->Result.range * sizeof(array));
    Array->Result.length = Array->Result.range;
    va_list valist;
    va_start(valist, Array->Int.range);
    for (Array->i = 0; Array->i < Array->Result.range; Array->i++){
        results x = va_arg(valist, results);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Result.range; Array->i++){
        Array->Result.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_WEBFILES(Array *Array, ...){
    array *Arra = malloc(Array->Web_files.range * sizeof(array));
    Array->Web_files.length = Array->Web_files.range;
    va_list valist;
    va_start(valist, Array->Web_files.range);
    for (Array->i = 0; Array->i < Array->Web_files.range; Array->i++){
        WEB_FILES x = va_arg(valist, WEB_FILES);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Int.range; Array->i++){
        Array->Web_files.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_page_url(Array *Array, ...){
    array *Arra = malloc(Array->Pages_url.range * sizeof(array));
    Array->Pages_url.length = Array->Pages_url.range;
    va_list valist;
    va_start(valist, Array->Pages_url.range);
    for (Array->i = 0; Array->i < Array->Pages_url.range; Array->i++){
        PAGE_URL x = va_arg(valist, PAGE_URL);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Pages_url.range; Array->i++){
        Array->Pages_url.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_String(Array *Array, ...){
    array *Arra = malloc(Array->string.range * sizeof(array));
    Array->string.length = Array->string.range;
    va_list valist;
    va_start(valist, Array->string.range);
    for (Array->i = 0; Array->i < Array->string.range; Array->i++){
        String x = va_arg(valist, String);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->string.range; Array->i++){
        Array->string.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_Char(Array *Array, ...){
    array *Arra = malloc(Array->Char.range * sizeof(array));
    Array->Char.length = Array->Char.range;
    va_list valist;
    va_start(valist, Array->Char.range);
    for (Array->i = 0; Array->i < Array->Char.range; Array->i++){
        char x = va_arg(valist, char);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Char.range; Array->i++){
        Array->Char.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

int send_content_server (server * server){
    if (listen(server->server_fd, 3) < 0){
        perror("");
        return Status_ok;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Status_error;
    }
    char *response_2[BUFFER_SIZE];
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", ob, response_2);
    write(server->new_socket, response_2, strlen(response_2));
    close(server->new_socket);
}

size_t write_callback(void *buffer, size_t size, size_t nmemb, void *userp) {
    String data = (String)buffer;
    ob = data;
    return size * nmemb;
}

int open_ (const String solicitud, const String params_post, const String page_url){
    _get ="GET";
    _post = "POST";
    if(strcmp(solicitud,_get) == 0){
        result_ = Ini_request;
        resq = "GET";
        pages_request = page_url;
        return Ini_request;
    } else if(strcmp(solicitud,_post) == 0){
        result_ = Ini_request;
        resq = "POST";
        pages_request = page_url;
        if(params_post == NULL){
            printf("WebCUtils : error, post_params is NULL\n");
            return No_ini_request;
        }
        post_params_request = params_post;
        return Ini_request;
    }
    printf("WebCUtils : no ini request\n");
    return No_ini_request;
}

String load_(){
    return ob;
}

void close_ (){
    _get = "GET";
    _post = "POST";
    pages_request = NULL;
    post_params_request = NULL;
    resq = NULL;
    result_ = '\0';
    ob = NULL;
}

int send_ (){
    if(result_ == Ini_request){
        if(strcmp(resq,_get) == 0){
            CURL *curl;
            CURLcode res;
            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, pages_request);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
                res = curl_easy_perform(curl);
                if (res != CURLE_OK) {
                    return Status_error;
                }
                curl_easy_cleanup(curl);
            }
            curl_global_cleanup();
            return Status_ok;
        } else if(resq,_post){
            CURL *curl;
            CURLcode res;
            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, pages_request);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_params_request);
                res = curl_easy_perform(curl);
                if (res != CURLE_OK) {
                    return Status_error;
                }
                curl_easy_cleanup(curl);
            }
            curl_global_cleanup();
            return Status_ok;
        } else {
            return Status_error;
        }
    }
    return Status_error;
}

void prepare_request (request * request){
    request->open_ = open_;
    request->load_ = load_;
    request->close_ = close_;
    request->send_ = send_;
    request->send_content_server = send_content_server;
}

void get_date(date *date){
    time_t tiempo;
    struct tm *tm_info;
    time(&tiempo);
    tm_info = localtime(&tiempo);
    strftime(date->current_date, 20, "%Y-%m-%d", tm_info);
}

void get_time(date *date){
    time_t tiempo;
    struct tm *tm_info;
    time(&tiempo);
    tm_info = localtime(&tiempo);
    strftime(date->hour, 9, "%H:%M:%S", tm_info);
}

int time_cmp(date *date, const String other_hour){
    if (strcmp(date->hour, other_hour)){
        return Web_true;
    }
    return Web_false;
}

int date_cmp(date *date, const String other_date){
    if (strcmp(date->current_date, other_date)){
        return Web_true;
    }
    return Web_false;
}

int date_cmp_func(date *date, const String other_date, void (*func)()){
    if (strcmp(date->current_date, other_date)){
        func();
    }
    return Web_false;
}

int time_cmp_func(date *date, const String other_hour, void (*func)()){
    if (strcmp(date->hour, other_hour)){
        func();
    }
    return Web_false;
}

int execute_query_ (sqlite * g, server * server){
    sqlite3 *db;
    char *errMsg = 0;
    char * msgErrorW[BUFFER_SIZE];
    char msgErrorW2[BUFFER_SIZE];
    char msgErrorW3[BUFFER_SIZE];
    int result = sqlite3_open(g->baseData, &db);
    if (listen(server->server_fd, 3) < 0){
        return Database_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        return Database_error;
    }
    if (result != SQLITE_OK) {
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n","<b><span style=\"color: red\">Error-sqlite</span>: not open sqlite</b>",msgErrorW);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, msgErrorW, strlen(msgErrorW));
        close(server->new_socket);
        fprintf(stderr, "WebCUtils: %s\n", sqlite3_errmsg(db));
        return Database_error;
    }
    result = sqlite3_exec(db, g->query_, 0, 0, &errMsg);
    if (result != SQLITE_OK) {
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n","<b><span style=\"color: red\">Error-sqlite</span>:  ",msgErrorW2);
        cat_str(msgErrorW2,errMsg,msgErrorW3);
        cat_str(msgErrorW3,"</b>",msgErrorW);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, msgErrorW, strlen(msgErrorW));
        close(server->new_socket);
        fprintf(stderr, "WebCUtils: %s\n", errMsg);
        sqlite3_free(errMsg);
        return Database_error;
    } 
    sqlite3_close(db);
    return Database_ok;
}

int execute_query_func (sqlite * g, server * server, int (*callback)()){
    sqlite3 *db;
    char *errMsg = 0;
    char * msgErrorW[BUFFER_SIZE];
    char msgErrorW2[BUFFER_SIZE];
    char msgErrorW3[BUFFER_SIZE];
    int result = sqlite3_open(g->baseData, &db);
    if (listen(server->server_fd, 3) < 0){
        return Database_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        return Database_error;
    }
    if (result != SQLITE_OK) {
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n","<b><span style=\"color: red\">Error-sqlite</span>: not open sqlite</b>",msgErrorW);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, msgErrorW, strlen(msgErrorW));
        close(server->new_socket);
        fprintf(stderr, "WebCUtils: %s\n", sqlite3_errmsg(db));
        return Database_error;
    }
    result = sqlite3_exec(db, g->query, callback, 0, &errMsg);
    if (result != SQLITE_OK) {
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n","<b><span style=\"color: red\">Error-sqlite</span>:  ",msgErrorW2);
        cat_str(msgErrorW2,errMsg,msgErrorW3);
        cat_str(msgErrorW3,"</b>",msgErrorW);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, msgErrorW, strlen(msgErrorW));
        close(server->new_socket);
        fprintf(stderr, "WebCUtils: %s\n", errMsg);
        sqlite3_free(errMsg);
        return Database_error;
    } 
    sqlite3_close(db);
    return Database_ok;
}

int execute_query (sqlite * g, server * server){
    sqlite3 *db;
    char *errMsg = 0;
    char * msgErrorW[BUFFER_SIZE];
    char msgErrorW2[BUFFER_SIZE];
    char msgErrorW3[BUFFER_SIZE];
    int result = sqlite3_open(g->baseData, &db);
    if (listen(server->server_fd, 3) < 0){
        return Database_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        return Database_error;
    }
    if (result != SQLITE_OK) {
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n","<b><span style=\"color: red\">Error-sqlite</span>: not open sqlite</b>",msgErrorW);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, msgErrorW, strlen(msgErrorW));
        close(server->new_socket);
        fprintf(stderr, "WebCUtils: %s\n", sqlite3_errmsg(db));
        return Database_error;
    }
    result = sqlite3_exec(db, g->query, 0, 0, &errMsg);
    if (result != SQLITE_OK) {
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n","<b><span style=\"color: red\">Error-sqlite</span>:  ",msgErrorW2);
        cat_str(msgErrorW2,errMsg,msgErrorW3);
        cat_str(msgErrorW3,"</b>",msgErrorW);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, msgErrorW, strlen(msgErrorW));
        close(server->new_socket);
        fprintf(stderr, "WebCUtils: %s\n", errMsg);
        sqlite3_free(errMsg);
        return Database_error;
    } 
    sqlite3_close(db);
    return Database_ok;
}

int insert_database(const char* name_base, int total_data, const char* sql, const char* insert, ...) {
    sqlite3* db;
    char* err_msg = 0;
    int rc, i;
    char insert_query[100];
    char chonps[1000];
    va_list args;
    rc = sqlite3_open(name_base, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "%s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return Database_error;
    }
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "%s\n", sqlite3_errmsg(db));
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return Database_error;
    }
    va_start(args, insert);
    for (i = 0; i < total_data; i++) {
        String count = va_arg(args, String);
        strcpy(chonps, "some value");
        if (sprintf(insert_query, insert, count) < 0) {
            fprintf(stderr, "Error in sprintf\n");
            sqlite3_close(db);
            return Database_error;
        }
        printf("%s\n",insert_query);
    }
    rc = sqlite3_exec(db, insert_query, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "%s\n", sqlite3_errmsg(db));
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return Database_error;
        }
    va_end(args);
    sqlite3_close(db);
    return Database_ok;
}

int create_cookie(server *server, const char *request, const char *data_cookie){
    recv(server->valread, request, BUFFER_SIZE, 0);
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char response[BUFFER_SIZE];
    FILE *fp = fopen(server->cookie_file_name, "w");
    if (fp == NULL){
        perror("");
        return Web_error;
    }
    else{
        fprintf(fp, "%s", data_cookie);
    }
    close(server->valread);
    fclose(fp);
    server->cookie_active = Is_active;
    return Is_active;
}

int remove_cookie(server *server){
    if (remove(server->cookie_file_name) == Error){
        perror("");
        return Web_error;
    }
    server->cookie_active = Is_no_active;
    return Is_no_active;
}

String read_cookie(server *servidor, const char *request){
    recv(servidor->valread, request, BUFFER_SIZE, 0);
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(servidor->cookie_time, sizeof(servidor->cookie_time), "%Y-%m-%d %H:%M:%S", tm_info);
    char response[BUFFER_SIZE];
    char data[BUFFER_SIZE];
    FILE *cookie = fopen(servidor->cookie_file_name, "r");
    if (cookie == NULL){
        perror("");
        return Web_error;
    }
    else{
        while (feof(cookie) == 0){
            fgets(data, BUFFER_SIZE, cookie);
            snprintf(response, BUFFER_SIZE, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n%s", data);
        }
    }
    close(servidor->valread);
    fclose(cookie);
    return response;
}

String get_referer (){
    String text = GET_RESPONSE();
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    String word = "Referer: http://localhost:8090/";
    int ini = strlen(word);
    int end_index;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        word = "er: http://localhost:8090/";
        ini = strlen(word);
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

String simple_get (){
    String text = GET_RESPONSE();
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    String word = "GET /";
    int ini = strlen(word);
    int end_index;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

String simple_post (){
    String text = GET_RESPONSE();
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    String word = "POST /";
    int ini = strlen(word);
    int end_index;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

char * post (const String word, int ini, int end_index, String save_post){
    String text = GET_RESPONSE();
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                save_post = result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

char * get(const char *text, const char *word, int ini, int end_index, server *server){
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    char response[BUFFER_SIZE];
    size_t bytesRead;
    FILE *fp;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                fp = fopen(result, "r");
                if (fp == NULL){
                    return Web_error;
                }
                while ((bytesRead = fread(response, 1, sizeof(response), fp)) > 0){
                    send(server->client_socket, response, bytesRead, 0);
                }
                fclose(fp);
                close(server->client_socket);
                return Web_ok;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

int send_email(email *email){
    CURL *curl;
    CURLcode res = CURLE_OK;
    curl = curl_easy_init();
    if (curl){
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

int have_file (){
    String text = GET_RESPONSE();
    char * word = "Content-Length";
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        if (strstr(line, word) != NULL){
            return Have_file;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return No_have_file;
}

int getLengthNameFile (files * f){
    String text = GET_RESPONSE();
    char *word = "filename=\"";
    int ini = 9;
    int end_index = 50;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_namefile = strlen(result);
                f->len_namefile = f->len_namefile-1;
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

char *getFileName(files * f, const char *text, int end_index){
    char *word = "filename=\"";
    int ini = 10;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    end_index = end_index - 2;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index-1 <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_namefile = strlen(result);
                f->name_file = result;
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

int getLengthTypeFile (files * f, const String text){
    char *word = "Content-Type: ";
    int ini = 15;
    int end_index = 10;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_typefile = strlen(result);
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

char *getTypeFile(files * f, const char *text, int end_index){
    char *word = "Content-Type:";
    int ini = 13;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_typefile = strlen(result);
                if(f->len_typefile > end_index){
                    f->status_file = Error_length_string_up;
                    return Error_length_string_up;
                } else if(f->len_typefile < end_index){
                    f->status_file = Error_length_string_down;
                    return Error_length_string_down;
                }
                f->type_file = result;
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

int getLengthStringFile (files * f){
    String text = GET_RESPONSE();
    char *word = "Content-Length: ";
    int ini = 15;
    int end_index = 10;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_file = strlen(result);
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

char *getLengthFile(files * f, const char *text, int end_index){
    char *word = "Content-Length: ";
    int ini = 15;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_file = strlen(result);
                if(f->len_file > end_index){
                    f->status_file = Error_length_string_up;
                    return Error_length_string_up;
                } else if(f->len_file < end_index){
                    f->status_file = Error_length_string_down;
                    return Error_length_string_down;
                }
                f->length_file = result;
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

int pre_uploaded_file (files * f, server * server){
    f->end_of_header = strstr(buffer, "\r\n\r\n");
    if (f->end_of_header != NULL) {
        f->body_offset = f->end_of_header  + 4 - buffer;
        f->pre = 1;
        f->content_file = buffer + f->body_offset;
        f->length = server->valread - f->body_offset;
    } else {
        puts("WebCUtils: not have content file");
        return Error_file;
    }
}

int uploaded_file (files * f){
    if(f->pre == 1){
        FILE* file = fopen(f->name_file, "wb");
        if (file != NULL) {
            fwrite(f->content_file, sizeof(char), f->length, file);
            fclose(file);
            f->pre = 0;
            return Ok_file;
        } else {
            perror("WebCUtils ");
            f->pre = 0;
            return Error_file;
        }
    } else {
        puts("WebCUtils: pre_uploaded_file() not declared");
        f->pre = 0;
        return Ok_file;
    }
}

int permission_download_file (files * f, server * server){
    
    f->file_down = fopen(f->file_name_down, "rb");
    size_t bytes_read;
    char r_headers_1[BUFFER_SIZE];
    char r_headers_2[BUFFER_SIZE];
    cat_str("HTTP/1.1 200 OK\r\nContent-Disposition: attachment; filename=\"",f->file_name_down,r_headers_1);
    cat_str(r_headers_1,"archivo.txt\"\r\nContent-Type: text/plain\r\n\r\n",r_headers_2);
    if(f->file_down == NULL){
        perror("WebCUtils ");
        return Error_file;
    } else {
        send(server->client_socket, r_headers_2, strlen(r_headers_2), 0);
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), f->file_down)) > 0) {
            send(server->client_socket, buffer, bytes_read, 0);
        }
        fclose(f->file_down);
        return Ok_file;
    }
    
}

int save_response(const char * namefile){
    FILE *fp = fopen(namefile, "a");
    if (fp == NULL){
        return Web_error;
    }
    fprintf(fp, "%s", GET_RESPONSE());
    fclose(fp);
    return Web_ok;
}

char *get_response(){
    return buffer;
}

int send_simple_response(server *server, const char *response){
    if (listen(server->server_fd, 3) < 0){
        perror("");
        return Web_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Web_error;
    }
    char *response_2[BUFFER_SIZE];
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", response, response_2);
    write(server->new_socket, response_2, strlen(response_2));
    close(server->new_socket);
}

int _response_args(server *server, int total,const char *response, ...){
    int i;
    if (listen(server->server_fd, 3) < 0){
        perror("");
        return Web_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Web_error;
    }
    char *response_2[BUFFER_SIZE], response_total[BUFFER_SIZE];
    if(total < 1){
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", response, response_2);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, response_2, strlen(response_2));
         close(server->new_socket);
         return Ok;
    } else {
        va_list args;
        va_start(args, response);
        for (i = 0; i < total + 1 - 1; i++){
             String count = va_arg(args, String);
             sprintf(response_2, response, count);
        }
        va_end(args);
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n",response_2,response_total);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, response_total, strlen(response_total));
        close(server->new_socket);
    }
}

int send_response_server_view_js(server *server, const char *archivo){
    char response_2[BUFFER_SIZE];
    const String js = "<script>window.onerror = function(message, source, lineno, colno, error) {let errorDiv = document.getElementById('error-log');if (errorDiv) {errorDiv.innerHTML += '<strong>Error:</strong> ' + message + '<br>';}};</script><div id=\"error-log\"></div>";
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Error;
    }
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    FILE *file = fopen(archivo, "r");
    if (file == NULL){
        perror("");
        return Error;
    }
    char html_content[server->buffer_file];
    size_t html_size = fread(html_content, sizeof(char), server->buffer_file, file);
    cat_str(js,html_content,response_2);
    fclose(file);
    server_file_response(server->new_socket, "text/html", response_2);
    close(server->new_socket);
}

int Server_response_variadic(server *server, const char *archivo, int total, ...){
    int i;
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Error;
    }
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    FILE *file = fopen(archivo, "r");
    if (file == NULL){
        perror("");
        return Error;
    }
    char html_content[server->buffer_file];
    size_t html_size = fread(html_content, sizeof(char), server->buffer_file, file);
    fclose(file);
    va_list args;
    va_start(args, html_content);
    char response_2[BUFFER_SIZE];
    for (i = 0; i < total; i++){
          String count = va_arg(args, String);
          sprintf(response_2, html_content, count);
     }
    va_end(args);
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    server_file_response(server->new_socket, "text/html", response_2);
    close(server->new_socket);
}

static String _requestedURL(){
    String text = GET_RESPONSE();
    String word = "Referer: ";
    jit ini = strlen(word);
    jit end_index = Localhost_url_length;
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    while (line != NULL){
        String word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

int open_server(server *server){
    server->opt = 1;
    server->addrlen = sizeof(server->address);
    server->load_buffer = load_buffer;
    server->page_404 = page_404;
    long_buffer_size = server->buffer_size_web;
    server->requestedURL = _requestedURL;
    if ((server->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("");
        return Error;
    }
    if (setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &server->opt, sizeof(server->opt))){
        perror("");
        return Error;
    }
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(server->port);
    if (bind(server->server_fd, (struct sockaddr *)&server->address, sizeof(server->address)) < 0){
        perror("");
        return Error;
    }
    if (listen(server->server_fd, 3) < 0){
        perror("");
        return Error;
    }
}

String getUrl (){
	
}

int send_response_server (server *server, const char *archivo){
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Error;
    }
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    FILE *file = fopen(archivo, "r");
    if (file == NULL){
        perror("");
        return Error;
    }
    char html_content[server->buffer_file];
    size_t html_size = fread(html_content, sizeof(char), server->buffer_file, file);
    fclose(file);
    server_file_response(server->new_socket, "text/html", html_content);
    close(server->new_socket);
}

void ini_simple_server(server *S){
    S->opt = 1;
    S->addrlen = sizeof(S->address);
    S->error = Ok;
}

int config_simple_server(server *S){
    S->error = Error;
    if ((S->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("");
        return S->error;
    }
    if (setsockopt(S->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &S->opt, sizeof(S->opt))){
        perror("");
        return S->error;
    }
    S->address.sin_family = AF_INET;
    S->address.sin_addr.s_addr = INADDR_ANY;
    S->address.sin_port = htons(S->port);
    if (bind(S->server_fd, (struct sockaddr *)&S->address, sizeof(S->address)) < 0){
        perror("");
        return S->error;
    }
}

int send_response_simple_server(server * S, const char *response){
    if (listen(S->server_fd, 3) < 0){
        perror("");
        return S->error;
    }
    if ((S->new_socket = accept(S->server_fd, (struct sockaddr *)&S->address, (socklen_t *)&S->addrlen)) < 0){
        perror("");
        return S->error;
    }
    S->valread = read(S->new_socket, buffer, BUFFER_SIZE);
    write(S->new_socket, response, strlen(response));
    close(S->new_socket);
}

#endif
 