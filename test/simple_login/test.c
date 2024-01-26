#include <webcutil/webcutil.h>
#include <sqlite3.h>
#include <curl/curl.h>

void index_page(html *, server *);

int main(){
	server servidor; //variable de la struct server
	//inizializar el port y buffer file
	servidor.port = 8080;
	servidor.buffer_file = 6096; //No obligatorio pero recomendado
	open_server(&servidor); //Abrimos el servidor
	//creamos el bucle principal del servidor
	while (Web_ok){
		/*creamos una varible html para
		enviarla por parametro a una funcion
		que se encargara de crear la pagina html*/
		html index;
		ini_html(&index);	//Se inizializa las funciones de html
		index_page(&index,&servidor); //funcion encargada de crear la pagina html
		index.send(&servidor, Js_errors_off);
		save_response("responses.txt");
		printf("%s", servidor.load_buffer());
	}
	return 0;
}

void index_page(html *index, server * s){
	index->title("WebCUtil Test | login");
	index->html_o("lang=\"es\"");
	index->head_o(NULL);
	index->meta("charset=\"UTF-8\"");
	index->meta("name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"");
	index->style_src("estilos",s,0);
	index->head_c();
	index->body_o(NULL);
	index->div_o("class=\"login-container\"","");
	index->form_o("method=\"post\" action=\"\"");
	index->label("for=\"username\"","Usuario: ");
	index->input("type=\"text\" id=\"username\" name=\"username\" required");
	index->label("for=\"password\"","Contraceña: ");
	index->input("type=\"password\" id=\"password\" name=\"password\" required");
	index->button("type=\"submit\"","Iniciar Sesión");
	index->form_c();
	index->center_o();
	index->a("#","¿No tienes cuenta?");
	index->br();
	index->a("#","¿No tienes cuenta?");
	index->center_c();
	index->div_c();
	index->body_c();
	index->html_c();
	//index->show_html_console();
}
