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
		page.send(&servidor);
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
