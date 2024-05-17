#include "webcutil.h"
#include <sqlite3.h>
#include <curl/curl.h>

void index_page(html *);
void page_data(html *, server *);

String nombre_libro, pagina_actual, extra;
bool data;

int main(){
	server servidor;
	servidor.port = 8080;
	files archivos;
	data = false;
	sqlite sq;
	requestUrls res;
	ini_get(&res);
	ini_files(&archivos);
	servidor.url = "127.0.0.1";
	servidor.buffer_file = 6096;
	openServer(&servidor);
	while (Web_ok){
		html page;
		ini_html(&page);
		index_page(&page);
		page.send(&servidor);
		page.resetAllHTML();
		archivos.create_file("server.log", servidor.load_buffer(), "a");
		printf("%s",servidor.load_buffer());
		if (res.search("libros-guardados.c")){
			while (res.search("libros-guardados.c")){
				html local;
				ini_html(&local);
				page_data(&local, &servidor);
				local.send(&servidor);
				local.resetAllHTML();
				archivos.create_file("server.log", servidor.load_buffer(), "a");
				printf("%s",servidor.load_buffer());
			}
		}
		if (res.search("nombre=")){
			if (data != true){
				nombre_libro = res.search_post("nombre=", '&');
				pagina_actual = res.search_post("pagina=", '&');
				extra = res.search_post("extras=", '\0');
				sq.baseData = "Libros.db";
				concatplus(sq.query_, "INSERT INTO Libros (nombre_libro,pagina_actual,notas) VALUES ('%s','%s','%s');", nombre_libro, pagina_actual, extra);
				execute_query_(&sq, &servidor);
				data = true;
			}
		}
	}
	return 0;
}

void page_data(html *page, server *s){
	sqlite3 *db;
	int rc;
	const char *sql;
	sqlite3_stmt *stmt;
	rc = sqlite3_open("Libros.db", &db);
	if (rc){
		fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
		return;
	}
	sql = "SELECT * FROM Libros";
	rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
	if (rc != SQLITE_OK){
		fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
		return;
	}
	page->html_o("lang=\"es\"");
	page->head_o(NULL);
	page->title("Libros leìdos | Base data");
	page->meta("charset=\"UTF-8\"");
	page->style_src("styles", s, 0);
	page->head_c();
	page->body_o(NULL);
	page->nav_o(NULL);
	page->a("href=\"#\"", "Home");
	page->a("href=\"#\"", "About");
	page->a("href=\"#\"", "Base de datos");
	page->nav_c();
	page->div_o("class=\"container\"");
	page->h2(NULL, "Libros en lectura");
	page->table_o("");
	page->thead_o("");
	page->tr_o("");
	page->th("", "Nombre del libro");
	page->th("", "Pagina actual");
	page->th("", "Notas");
	page->tr_c();
	page->thead_c();
	page->tbody_o("");
	while (sqlite3_step(stmt) == SQLITE_ROW){
		page->tr_o("");
		page->td("", (const String)sqlite3_column_text(stmt, 1));
		page->td("", to_str(sqlite3_column_int(stmt, 2)));
		page->td("", (const String)sqlite3_column_text(stmt, 3));
		page->tr_c();
	}
	page->tbody_c();
	page->table_c();
	page->div_c(); 
	page->body_c();
	page->html_c();
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void index_page(html *page){
	char tmp[HTML_LONG];
	String pageHtml = getStringHtml("index");
	concatplus(tmp, pageHtml, "Libros leìdos | HOME");
	page->load_extern_html(tmp);
}
