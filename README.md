# WebCUtil
Una libreria para usar el lenguaje C en la web
Esta es una libreria en desarrollo muy temprano tiene como objetivo poder usar el lenguaje C en la web como servidor y podiendo enviar o crear paginas webs desde el codigo C como tambien trabajar con archivos *.htm, *.css y *.js.
Aqui un codigo de ejemplo que encontrara en un archivo llamado **main.c**
## Codigo de muestra
```
#include "webcutil.h"

void index_page (html * );

int main (){
	//creaciòn y inizializaciòn del servidor
	server servidor;
	servidor.port = 8080;
	servidor.buffer_file = 6096;
	open_server(&servidor);
	//bucle principal de la pagina web
	while(Web_ok){
		//crear y enviar la pagina html
		html page;
		ini_html(&page);
		index_page(&page);
		page.send(&servidor,Js_errors_off);
		//imprimir en consola la respuesta del navegador
		printf("%s",servidor.load_buffer());
	}
	return 0;
}

void index_page (html * page){
	page->title("Ciao, mondo!");
	page->html_o(NULL);
	page->head_o(NULL);
	page->head_c();
	page->body_o(NULL);
	page->h1(NULL,"Ciao, mondo!");
	page->body_c();
	page->html_c();
}
````
## Notas
Para usar la libreria necesitara tener instalado estas librerias porque **WebCUtils.h** las utiliza:

1.**sqlite3.h**, puedes obtenerlo del sitio web oficial de SQLite en la sección de descargas: https://www.sqlite.org/download.html

2.**curl.h**, puedes obtenerlo del sitio web oficial de cURL en la sección de descargas: https://curl.se/download.html
