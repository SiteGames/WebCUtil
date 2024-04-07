#ifndef SQLITE_H
#define SQLITE_H

typedef struct{
	char *query;
	String baseData;
	char query_[1000];
} sqlite;

int execute_query_(sqlite *g, server *server)
{
	sqlite3 *db;
	char *errMsg = 0;
	char *msgErrorW[BUFFER_SIZE];
	char msgErrorW2[BUFFER_SIZE];
	char msgErrorW3[BUFFER_SIZE];
	int result = sqlite3_open(g->baseData, &db);
	if (listen(server->server_fd, 3) < 0)
	{
		return Database_error;
	}
	if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0)
	{
		return Database_error;
	}
	if (result != SQLITE_OK)
	{
		cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", "<b><span style=\"color: red\">Error-sqlite</span>: not open sqlite</b>", msgErrorW);
		server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
		write(server->new_socket, msgErrorW, strlen(msgErrorW));
		close(server->new_socket);
		fprintf(stderr, "WebCUtils: %s\n", sqlite3_errmsg(db));
		return Database_error;
	}
	result = sqlite3_exec(db, g->query_, 0, 0, &errMsg);
	if (result != SQLITE_OK)
	{
		cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", "<b><span style=\"color: red\">Error-sqlite</span>:  ", msgErrorW2);
		cat_str(msgErrorW2, errMsg, msgErrorW3);
		cat_str(msgErrorW3, "</b>", msgErrorW);
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

int execute_query_func(sqlite *g, server *server, int (*callback)())
{
	sqlite3 *db;
	char *errMsg = 0;
	char *msgErrorW[BUFFER_SIZE];
	char msgErrorW2[BUFFER_SIZE];
	char msgErrorW3[BUFFER_SIZE];
	int result = sqlite3_open(g->baseData, &db);
	if (listen(server->server_fd, 3) < 0)
	{
		return Database_error;
	}
	if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0)
	{
		return Database_error;
	}
	if (result != SQLITE_OK)
	{
		cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", "<b><span style=\"color: red\">Error-sqlite</span>: not open sqlite</b>", msgErrorW);
		server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
		write(server->new_socket, msgErrorW, strlen(msgErrorW));
		close(server->new_socket);
		fprintf(stderr, "WebCUtils: %s\n", sqlite3_errmsg(db));
		return Database_error;
	}
	result = sqlite3_exec(db, g->query, callback, 0, &errMsg);
	if (result != SQLITE_OK)
	{
		cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", "<b><span style=\"color: red\">Error-sqlite</span>:  ", msgErrorW2);
		cat_str(msgErrorW2, errMsg, msgErrorW3);
		cat_str(msgErrorW3, "</b>", msgErrorW);
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

int execute_query(sqlite *g, server *server)
{
	sqlite3 *db;
	char *errMsg = 0;
	char *msgErrorW[BUFFER_SIZE];
	char msgErrorW2[BUFFER_SIZE];
	char msgErrorW3[BUFFER_SIZE];
	int result = sqlite3_open(g->baseData, &db);
	if (listen(server->server_fd, 3) < 0)
	{
		return Database_error;
	}
	if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0)
	{
		return Database_error;
	}
	if (result != SQLITE_OK)
	{
		cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", "<b><span style=\"color: red\">Error-sqlite</span>: not open sqlite</b>", msgErrorW);
		server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
		write(server->new_socket, msgErrorW, strlen(msgErrorW));
		close(server->new_socket);
		fprintf(stderr, "WebCUtils: %s\n", sqlite3_errmsg(db));
		return Database_error;
	}
	result = sqlite3_exec(db, g->query, 0, 0, &errMsg);
	if (result != SQLITE_OK)
	{
		cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", "<b><span style=\"color: red\">Error-sqlite</span>:  ", msgErrorW2);
		cat_str(msgErrorW2, errMsg, msgErrorW3);
		cat_str(msgErrorW3, "</b>", msgErrorW);
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

#endif
