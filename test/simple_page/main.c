/*Codigo escrito en C para crear una pagina html, css y js
desde codigo C*/
#include <webcutil/webcutil.h>
#include <sqlite3.h>
#include <curl/curl.h>

#include "pages.h"//Incluimos la libreria que tiene la pagina web a mostrar

int main(){
	server servidor;//Creamos una variable server para crear el servidor
	servidor.port = 8080;//inizializamos el puerto
	servidor.buffer_file = 6094;//inizializamos el buffer_file(necesario cuando se prueba con bastante codigo js y css)
	open_server(&servidor);//inizializamos el servidor
	while(Web_ok){//Creamos el bucle principal para mostrar siempre la pagina web
		html index_page;//creamos una variable html para poder crear la pagina però se la envia por parametro a la pagina
        ini_html(&index_page);//se inizializa la variable html(index_page)
        main_page(&index_page);//Se crea la pagina html
        index_page.send(&servidor,Js_errors_on);//se envia la pagina html
        printf("%s",servidor.load_buffer());//se muestra la repuesta del navegador
	}
	return 0;
}
