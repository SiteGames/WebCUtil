# WebCUtil
Esta es una libreria con la idea de usar el lenguaje C en la web como la estructura del servidor donde C se encargaria de todo lo relacionado con el servidor desde el manejo de peticiones GET o POST procesar formularios, manejar base de datos, etc...
Esto es una libreria experimental no es un proyecto serio solo es para experientar. Puedes dar ideas, o ser participe de este proyecto.

## Codigo de muestra
```
#include "webcutil.h"

void index_page (BuildHtml * );
void error_404_page (BuildHtml *);

int main (){
	Server server;
	server.port = 8080;
	server.buffer_file = 6046;
	server.url = "127.0.0.1";
	openServer(&server);
	while(true){
		BuildHtml page;
		buildHtml(&page);
		index_page(&page);
		page.send(&server);
		page.resetAllHTML();
		int res = server.registers_url();
		if(res != OK){
			while(true){
				BuildHtml page2;
				buildHtml(&page2);
				error_404_page(&page2);
				page2.send(&server);
				page2.resetAllHTML();
				if(search_w("index.c",server.load_buffer())){
					break;
				}
			}
		}
		server.saveBuffer("datosTest");
	}
	return 0;
}

void error_404_page (BuildHtml * page){
	page->html_o(EMPTY);
	page->title("Error 404");
	page->head_o(EMPTY);
	page->head_c();
	page->body_o(EMPTY);
	page->center_o();
	page->h1(EMPTY,"Pagina no encontrada: Error 404");
	page->a("href=\"index.c\"","Volver al index");
	page->center_c();
	page->body_c();
	page->html_c();
}

void index_page (BuildHtml * page){
	page->html_o(EMPTY);
	page->title("A tittle");
	page->head_o(EMPTY);
	page->head_c();
	page->body_o(EMPTY);
	page->h1(EMPTY,"Is Empty");
	page->body_c();
	page->html_c();
}
````
## Notas
En **webCUtil** se usan las siguientes librerias:

1.**sqlite3.h**, puedes obtenerlo del sitio web oficial de SQLite en la sección de descargas: https://www.sqlite.org/download.html

2.**curl.h**, puedes obtenerlo del sitio web oficial de cURL en la sección de descargas: https://curl.se/download.html
