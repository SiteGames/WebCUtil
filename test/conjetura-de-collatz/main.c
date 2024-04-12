#include <webcutil.h>
#include <sqlite3.h>
#include <curl/curl.h>

String numUser;
bool data;

void index_page(html *, server *);

int main(){
	server servidor;
	requestUrls res;
	servidor.port = 8080;
	servidor.url = "127.0.0.2";
	servidor.buffer_file = 6096;
	openServer(&servidor);
	ini_get(&res);
	data = false;
	while (WEB_TRUE){
		html page;
		ini_html(&page);
		index_page(&page, &servidor);
		page.send(&servidor);
		page.resetAllHTML();
		servidor.showBuffer();
		servidor.saveBuffer("testServer.dat");
		if (res.search_post("num=", '\0')){
			data = true;
			numUser = res.search_post("num=", '\0');
		}
	}
	return 0;
}

void index_page(html *page, server *s){
	int num, isPar;
	page->html_o(NULL);
	page->head_o(NULL);
	page->title("CONGETTURA DI COLLATZ");
	page->meta("charset=\"UTF-8\"");
	page->style_src("styles", s, 0);
	page->head_c();
	page->body_o(NULL);
	page->div_o("class=\"container\"");
	page->h1(NULL, "Ecuacione 3x+1: CONGETTURA DI COLLATZ");
	page->br();
	page->p(NULL, "La congettura di Collatz asserisce che questo algoritmo giunge sempre a termine, indipendentemente dal valore di partenza. Sarà questo vero?");
	page->br();
	page->form_o("method=\"POST\" action=\"\"");
	page->input("type=\"text\" placeholder=\"Escribe el numero. . .\" name=\"num\"");
	page->button("type=\"submit\"", "Enviar");
	page->form_c();
	page->br();
	if (data == true){
		num = atoi(numUser);
		if (num < 4){
			page->script_o();
			page->text("alert('Error el numero ingresado es menor que 4');");
			page->script_c();
		}
		else{
			page->center_o();
			page->h2(NULL, "Resultado: ");
			page->center_c();
			page->div_o("class=\"scroll-section\"");
			page->center_o();
			while (num != 1){
				isPar = num % 2;
				if (isPar == 0){
					num = num / 2;
					String str = to_str(num);
					page->p(NULL, str);
				}
				else{
					num = (num * 3) + 1;
					String str = to_str(num);
					page->p(NULL, str);
				}
			}
		}
		page->center_c();
		page->div_c();
	}
	page->div_c();
	page->body_c();
	page->html_c();
}
