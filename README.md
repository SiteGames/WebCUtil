# WebCUtil
Una libreria para usar el lenguaje C en la web
Esta es una libreria en desarrollo muy temprano tiene como objetivo poder usar el lenguaje C en la web como servidor y podiendo enviar o crear paginas webs desde el codigo C como tambien trabajar con archivos *.htm, *.css y *.js.
Aqui un codigo de ejemplo que encontrara en un archivo llamado **main.c**
## Codigo de muestra

#include <webcutil/webcutil.h>
//Se crea la pagina que se envia como respuesta
void index (html * log){
    log->title("Login | Testqlite");
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
	server servidor;//Se crea una variable server de la estructura server
	servidor.port = 8080;//se asigna un puerto
	servidor.buffer_file = 6094;//se asigna un tamaño de buffer de archivo(opcional)
	open_server(&servidor);//se inicia el servidor
	while(Web_ok){//Se crea un bucle principal para las request
		html index_page;
        ini_html(&index_page);
        index(&index_page);
    index_page.send(&servidor,Js_errors_on);
        printf("%s",servidor.load_buffer());
	}
	return 0;
}

## Notas
Para usar la libreria necesitara tener instalado estas librerias porque **WebCUtils.h** las utiliza:

1.**sqlite3.h**, puedes obtenerlo del sitio web oficial de SQLite en la sección de descargas: https://www.sqlite.org/download.html

2.**curl.h**, puedes obtenerlo del sitio web oficial de cURL en la sección de descargas: https://curl.se/download.html

Hay un discord por aqui: https://discord.com/invite/fwHVT8yTjx
