#include <webcutil/webcutil.h>

void index (html * log){
    log->title("Login | WebCUtil");
    log->html_o("lang=\"es\"");
    log->head_o(NULL);
    log->meta("charset=\"UTF-8\"");
    log->meta("http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"");
    log->meta("name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"");
    log->head_c();
    log->body_o(NULL);
    log->form_o("method=\"POST\" action=\"\"");
    log->input("type=\"text\" name=\"texto\" value=\"un texto. . .\"");
    log->button(NULL,"Enviar");
    log->script("main.js","");
    log->form_c();
    log->body_c();
    log->html_c();
}

int main(int argc, char *argv[]){
	server servidor;
	servidor.port = 8080;
	servidor.buffer_file = 6094;
	open_server(&servidor);
	while(Web_ok){
		html index_page;
        ini_html(&index_page);
        index(&index_page);
        index_page.send(&servidor,Js_errors_on);
        printf("%s",servidor.load_buffer());
	}
	return 0;
}
