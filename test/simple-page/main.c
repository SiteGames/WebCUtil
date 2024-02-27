#include <webcutil/webcutil.h>
#include <sqlite3.h>
#include <curl/curl.h>

void main_page (html *, server *);

int main (){
  server servidor;
	requestUrls requestUrlss;
	//sessions sess;
	servidor.port = 8080;
	servidor.buffer_file = 6096;
	open_server(&servidor);
	ini_get(&requestUrlss);
  //bucle principal de la pagina web
	while(Web_ok){
		//crear y enviar la pagina html
		html page;
		ini_html(&page);
		page_page(&page,&servidor);
		page.send(&servidor,Js_errors_off);
		//imprimir en consola la respuesta del navegador
		printf("%s",servidor.load_buffer());
		save_response("navegador_responses.txt");//Guardar la respuesta en un archivo .txt
		page.resetAllHTML();//Resetiar la pagina para evitar dublicación del html
		/*if(requestUrlss.search_post("username=", '&') != NULL){
			sess.name = "Usuario";
			sess.data = requestUrlss.search_post("username=", '&');
			create_session(&sess);
			usleep(1000*1000);
			destroy_session(&sess);
		}*/
	}
  return 0;
}

void main_page (html * page, server * s){
	page->html_o("lang=\"es\"");
	page->head_o(NULL);
	page->title("WebCUtil test | Login");
	page->meta("charset=\"UTF-8\"");
	page->meta("name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"");
	page->style_src("estilos", s, 0);
	page->head_c();
	page->body_o(NULL);
	page->div_o("class=\"login-container\"");
	page->form_o("method=\"POST\" action=\"\"");
	page->label("for=\"username\"", "Usuario: ");
	page->input("type=\"text\" id=\"username\" name=\"username\" required");
	page->label("for=\"password\"", "Contraceña: ");
	page->input("type=\"password\" id=\"password\" name=\"passwords\" required");
	page->button("type=\"submit\"", "Iniciar Sesión");
	page->form_c();
	page->center_o();
	page->center_c();
	page->div_c();
	page->body_c();
	page->html_c();
	//page->show_html_console();
}

