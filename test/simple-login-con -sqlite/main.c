#include <webcutil/webcutil.h>
#include <sqlite3.h>
#include <curl/curl.h>

server servidor;//variable de la struct server

//prototipos de las funciones que crean las paginas
void main_page (html *, server *);
void reg_page (html *, server *);
void login_page(html *, server *);
static int callback(void* data, int argc, char** argv, char** azColName);
void cuenta_page (html *, server *, const String, const String, const String, const String, const String, const String);

int main(){
	requestUrls requestUrlss;
	PAGE_URL index = "index.c", page_login = "login.c", page_reg = "registro.c";
	date fecha;
	get_date(&fecha);
	char a[500],b[500],c[500],d[500],e[500],f[500],g[500],j[500],k[500],l[500],m[500];
	sqlite sqlites;
	sqlites.baseData = "users_test_webcutil.db";//nombre de la base de datos sqlite
	ini_get(&requestUrlss);
	//inizializar el port y buffer file
	servidor.port = 8080;
	servidor.buffer_file = 6096; //No obligatorio pero recomendado
	open_server(&servidor); //Abrimos el servidor
	//creamos el bucle principal del servidor
	while (Web_ok){
		/*creamos una varible html para
		enviarla por parametro a una funcion
		que se encargara de crear la pagina html*/
		html indexx;
		ini_html(&indexx);//Se inizializa las funciones de html
		main_page(&indexx,&servidor); //funcion encargada de crear la pagina html
		indexx.send(&servidor, Js_errors_off);
		//codigo para cambiar de paginas
		if(requestUrlss.search(page_login) == Ok){//Ir a la pagina de login
			while(requestUrlss.search(page_login) == Ok){
				html i;
				ini_html(&i);
			    login_page(&i,&servidor);
			    i.send(&servidor,Js_errors_off);
			    printf("%s",servidor.load_buffer());
			    if(requestUrlss.search_post("username=",'&') != NULL){
			    	sqlites.query = "SELECT * FROM Users;";
			    	execute_query_func(&sqlites,&servidor,callback);
			    }
			    if(requestUrlss.search(index) == Ok){
			    	main();
			    }
			}
		}
		if(requestUrlss.search(page_reg) == Ok){//Ir a la pagina de registro
			while(requestUrlss.search(page_reg) == Ok){
				html i;
				ini_html(&i);
			    reg_page(&i,&servidor);
			    i.send(&servidor,Js_errors_off);
			    printf("%s",servidor.load_buffer());
			    if(requestUrlss.search_post("username=",'&') != NULL){
			    	cat_str("INSERT INTO Users (username, password, fecha, edad, nombres, apellidos) VALUES ('",requestUrlss.search_post("username=",'&'), a);
			    	cat_str(a,"','",b);
			    	cat_str(b,requestUrlss.search_post("passwords=",'&'),c);
			    	cat_str(c,"','",d);
			    	cat_str(d,fecha.current_date,e);
			    	cat_str(e,"','",f);
			    	cat_str(f,requestUrlss.search_post("edad=",'\0'),g);
			    	cat_str(g,"','",j);
			    	cat_str(j,requestUrlss.search_post("nombre=",'&'),k);
			    	cat_str(k,"','",l);
			    	cat_str(l,requestUrlss.search_post("apellido=",'&'),m);
			    	cat_str(m,"');",sqlites.query_);
			    	execute_query_(&sqlites,&servidor);
			    }
			    if(requestUrlss.search(index) == Ok){
			    	main();
			    	break;
			    }
			}
		}
		save_response("responses.txt");//guardar las respuestas enviadas por el navegador en un archivo *.txt
	}
	return 0;
}

static int callback(void* data, int argc, char** argv, char** azColName) {
    int i,u = 1;
    String username, pass, dates, edad, nombres, apellidos;
    //requestUrls requestUrlsss;
    for (i = 0; i < argc; i++) {
        if(strcmp("username",azColName[i]) == 0){
        	username = argv[i] ? argv[i] : "NULL";
        }
        if(strcmp("password",azColName[i]) == 0){
        	pass = argv[i] ? argv[i] : "NULL";
        }
        if(strcmp("fecha",azColName[i]) == 0){
        	dates = argv[i] ? argv[i] : "NULL";
        }
        if(strcmp("edad",azColName[i]) == 0){
        	edad = argv[i] ? argv[i] : "NULL";
        }
        if(strcmp("nombres",azColName[i]) == 0){
        	nombres = argv[i] ? argv[i] : "NULL";
        }
        if(strcmp("apellidos",azColName[i]) == 0){
        	apellidos = argv[i] ? argv[i] : "NULL";
        }
    }
    while(u){
    	html o;
	    ini_html(&o);
	    cuenta_page(&o,&servidor,username,nombres,apellidos,dates,pass,edad);
	    o.send(&servidor,Js_errors_off);
	    printf("%s",servidor.load_buffer());
	    /*if(requestUrlsss.search("index.c") == Ok){
			  u = 0;
	    }*/
    }
    return 0;
}

void main_page (html * index, server * s){
	index->title("WebCUtil test | Home");
	index->html_o("lang=\"es\"");
	index->head_o(NULL);
	index->meta("charset=\"UTF-8\"");
	index->meta("name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"");
	index->style_src("home",s,0);
	index->head_c();
	index->body_o(NULL);
	index->header_o("");
	index->h1("","WebCUtil");
	index->header_c();
	index->main_o(NULL);
	index->section_o("class=\"options\"");
	index->a("href=\"login.c\" class=\"login\"","Login");
	index->a("href=\"registro.c\" class=\"register\"","Registro");
	index->section_c();
	index->main_c();
	index->body_c();
	index->html_c();
}

void reg_page (html * index, server * s){
	index->title("WebCUtil test | Registro");
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
	index->label("for=\"username\"","Nombres: ");
	index->input("type=\"text\" id=\"nombre\" name=\"nombre\" required");
	index->label("for=\"username\"","Apellidos: ");
	index->input("type=\"text\" id=\"apellido\" name=\"apellido\" required");
	index->label("for=\"password\"","Contraceña: ");
	index->input("type=\"password\" id=\"password\" name=\"passwords\" required");
	index->label("for=\"password\"","Edad: ");
	index->input("type=\"text\" id=\"edad\" name=\"edad\" required");
	index->button("type=\"submit\"","¡Registrarse!");
	index->form_c();
	index->center_o();
	index->a("href=\"index.c\"","¡Volver al inicio!");
	index->br();
	index->center_c();
	index->div_c();
	index->body_c();
	index->html_c();
}

void login_page(html *index, server * s){
	index->title("WebCUtil requestUrlss | login");
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
	index->input("type=\"password\" id=\"password\" name=\"passwords\" required");
	index->button("type=\"submit\"","Iniciar Sesión");
	index->form_c();
	index->center_o();
	index->a("href=\"index.c\"","¡Volver al inicio!");
	index->center_c();
	index->div_c();
	index->body_c();
	index->html_c();
}

void cuenta_page (html * index, server * s, const String user, const String nombre, const String apellido, const String fecha_, const String password, const String edadd){
	index->title("WebCUtil test | Cuenta");
	index->html_o("lang=\"es\"");
	index->head_o(NULL);
	index->meta("charset=\"UTF-8\"");
	index->meta("name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"");
	index->style_src("cuenta",s,0);
	index->head_c();
	index->body_o(NULL);
	index->header_o("");
	index->h1(NULL,"Mi cuenta");
	index->header_c();
	index->main_o(NULL);
	index->section_o("class=\"user-info\"");
	index->div_o("class=\"info-item\"","");
	index->label(NULL,"Usuario: ");
	index->p("id=\"username\"",user);
	index->div_c();
	index->div_o("class=\"info-item\"","");
	index->label(NULL,"Nombre: ");
	index->p("id=\"nombre\"",nombre);
	index->div_c();
	index->div_o("class=\"info-item\"","");
	index->label(NULL,"Apellido: ");
	index->p("id=\"apellido\"",apellido);
	index->div_c();
	index->div_o("class=\"info-item\"","");
	index->label(NULL,"Fecha de registro");
	index->p("id=\"fecha\"",fecha_);
	index->div_c();
	index->div_o("class=\"info-item\"","");
	index->label(NULL,"Contraceña");
	index->p("id=\"contrasena\"",password);
	index->div_c();
	index->div_o("class=\"info-item\"","");
	index->label(NULL,"Edad: ");
	index->p("id=\"edad\"",edadd);
	index->div_c();
	index->a("href=\"index.c\" class=\"login\"","Volver al inicio");
	index->section_c();
	index->main_c();
	index->center_o();
	index->footer("Webcutil");
	index->center_c();
	index->body_c();
	index->html_c();
}
