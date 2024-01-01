#ifndef WEBCUTIL_H
#define WEBCUTIL_H

#include <sqlite3.h>
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

#include "def.h"
#include "webcutiltypeof.h"

static int long_buffer_size = BUFFER_SIZE;
char *_post;
char *_get;
char cookie_value[30];
String ob;
char * ress;
String _get;
String _post;
int result_;
String resq;
PAGE_URL pages_request;
String post_params_request;
static char true_html[BUFFER_SIZE_3] = " ";
static char result_html[BUFFER_SIZE_3] = "<html>";
static char _hh[BUFFER_SIZE_3];
static char total_2[BUFFER_SIZE_3];
static char total_html[BUFFER_SIZE_3];
char buffer[BUFFER_SIZE] = {0};
char buffer_2[BUFFER_SIZE][BUFFER_SIZE];
String Response;

#define GET_RESPONSE() buffer

static String load_buffer (){
    return buffer;
}

int ini_ssl (https * s){
    SSL_library_init();
    ERR_load_BIO_strings();
    SSL_load_error_strings();
    s->ini = 1;
    return Web_ok;
}

int contex_ssl (https * s, const String cert, const String key){
    s->ctx = SSL_CTX_new(SSLv23_server_method());
    SSL_CTX_use_certificate_file(s->ctx, cert, SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(s->ctx, key, SSL_FILETYPE_PEM);
    return Web_ok;
}

void cat_str(const String texto1, const String texto2, String resultado){
    strcpy(resultado, texto1);
    strcat(resultado, texto2);
}

void _title (const String title){
    char temp[HTML_LONG];
    cat_str("<title>",title, temp);
    cat_str(temp,"</title>",result_html);
    cat_str(result_html,"",true_html);
}

static void _canvas_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<canvas>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<canvas ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _canvas_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</canvas>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _html_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<!DOCTYPE html><html>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<!DOCTYPE html><html ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _html_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</html>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _center_open (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<center>","",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _center_close (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</center>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _h1 (const String attributes, const String h1){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<h1>",h1,temp);
        cat_str(temp,"</h1>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h1 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h1,temp_5);
        cat_str(temp_5,"</h1>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _h2 (const String attributes, const String h2){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<h2>",h2,temp);
        cat_str(temp,"</h2>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h2 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h2,temp_5);
        cat_str(temp_5,"</h2>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _h3 (const String attributes, const String h3){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<h3>",h3,temp);
        cat_str(temp,"</h3>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h3 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h3,temp_5);
        cat_str(temp_5,"</h3>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _h4 (const String attributes, const String h4){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<h4>",h4,temp);
        cat_str(temp,"</h4>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h4 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h4,temp_5);
        cat_str(temp_5,"</h4>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _h5 (const String attributes, const String h5){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<h5>",h5,temp);
        cat_str(temp,"</h5>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h5 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h5,temp_5);
        cat_str(temp_5,"</h5>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _h6 (const String attributes, const String h6){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<h6>",h6,temp);
        cat_str(temp,"</h6>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h6 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h6,temp_5);
        cat_str(temp_5,"</h6>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _i (const String attributes, const String i){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<i>",i,temp);
        cat_str(temp,"</i>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<i ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,i,temp_5);
        cat_str(temp_5,"</i>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}
static void _b (const String attributes, const String b){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<b>",b,temp);
        cat_str(temp,"</b>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<b ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,b,temp_5);
        cat_str(temp_5,"</b>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}
static void _e (const String attributes, const String e){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<e>",e,temp);
        cat_str(temp,"</e>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<e ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,e,temp_5);
        cat_str(temp_5,"</e>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}
static void _em (const String attributes, const String em){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<em>",em,temp);
        cat_str(temp,"</em>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<em ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,em,temp_5);
        cat_str(temp_5,"</em>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _p (const String attributes, const String p){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<p>",p,temp);
        cat_str(temp,"</p>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<p ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,p,temp_5);
        cat_str(temp_5,"</p>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _button (const String attributes, const String button){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<button>",button,temp);
        cat_str(temp,"</button>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<button ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,button,temp_5);
        cat_str(temp_5,"</button>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _script (const String attributes, const String script){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<script>",script,temp);
        cat_str(temp,"</script>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<script ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,script,temp_5);
        cat_str(temp_5,"</script>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

/*Nuevas etiquetas html*/
static void _style (const String style){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<style>",style,temp);
    cat_str(temp,"</style>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _div (const String div){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<div ",div,temp);
    cat_str(temp,"></div>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _div_o (const String attributes, const String t){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        if(t == NULL){
            printf("WebCUtils: the second param is 'NULL'\n");
            return;
        }
        cat_str("<div>",t,temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        if(t == NULL){
            printf("WebCUtils: the second param is 'NULL'\n");
            return;
        }
        cat_str("<div ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,t,temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _div_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</div>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _body_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<body>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<body ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}
static void _body_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</body>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _body (const String body){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<body>",body,temp);
    cat_str(temp,"</body>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _head_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<head>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<head ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _head_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</head>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _head (const String head){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<head>",head,temp);
    cat_str(temp,"</head>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static int _img (const String attributes){
    if(attributes == NULL){
        return Html_error;
    } else {
        char temp[HTML_LONG];
        char temp_2[HTML_LONG];
        char temp_3[HTML_LONG];
        cat_str("<img ",attributes,temp);
        cat_str(temp,">",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static int _a (const String attributes, const String a){
    if (attributes == NULL){
        return Html_error;
    } else {
        char temp[HTML_LONG];
        char temp_2[HTML_LONG];
        char temp_3[HTML_LONG];
        char temp_4[HTML_LONG];
        char temp_5[HTML_LONG];
        cat_str("<a ",attributes,temp);
        cat_str(temp,">",temp_4);
        cat_str(temp_4,a,temp_5);
        cat_str(temp_5,"</a>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _section_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<section>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<section ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _section_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</section>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _section (const String section){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<section ",section,temp);
    cat_str(temp,"></section>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _article_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<article>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<article ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _article_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</article>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _article (const String article){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<article>",article,temp);
    cat_str(temp,"</article>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _header_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<header>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<header ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _header_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</header>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _header (const String header){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<header>",header,temp);
    cat_str(temp,"</header>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _footer (const String footer){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<footer>",footer,temp);
    cat_str(temp,"</footer>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _footer_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<footer>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<footer ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _footer_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</footer>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _video (const String video){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<footer>",video,temp);
    cat_str(temp,"</footer>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _form (const String from){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<footer>",from,temp);
    cat_str(temp,"</footer>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _form_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<form>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<form ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _form_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</form>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static int _input (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        return Html_error;
    } else {
        cat_str("<input ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static int _meta (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        return Html_error;
    } else {
        cat_str("<meta ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static int _link (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        return Html_error;
    } else {
        cat_str("<link ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _aside (const String aside){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<aside>",aside,temp);
    cat_str(temp,"</aside>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void  _hr (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<hr>","",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _br (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<br>","",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _pre (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<pre>","",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _center (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<center>","",temp);
    cat_str(temp,"</center>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _textarea (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<textarea>","",temp);
        cat_str(temp,"</textarea>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<textarea ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"</textarea>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _blockquote (const String block){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<blockquote>",block,temp);
    cat_str(temp,"</blockquote>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _ol (const String ol){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<ol>",ol,temp);
    cat_str(temp,"</ol>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _ol_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<ol>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<ol ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _ol_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</ol>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _ul (const String ul){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<ul>",ul,temp);
    cat_str(temp,"</ul>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _ul_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<ul>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<ul ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _ul_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</ul>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _li (const String attributes, const String li){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<li>",li,temp);
        cat_str(temp,"</li>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<li ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,li,temp_5);
        cat_str(temp_5,"</li>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _dl (const String _ddl){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<dl>",_ddl,temp);
    cat_str(temp,"</dl>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _dl_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<dl>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<dl ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _dl_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</dl>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _dt (const String _ddt){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<dt>",_ddt,temp);
    cat_str(temp,"</dt>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _dt_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<dt>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<dt ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _dt_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</dt>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _dd_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<dd>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<dd ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _dd_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</dd>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _figure (const String fig){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<figure>",fig,temp);
    cat_str(temp,"</figure>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _figure_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<figure>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<figure ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _figure_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</figure>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _small (const String sm){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<small>",sm,temp);
    cat_str(temp,"</small>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _cite (const String ci){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<cite>",ci,temp);
    cat_str(temp,"</cite>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _sub (const String su){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<sub>",su,temp);
    cat_str(temp,"</sub>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _sup (const String sup){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<sup>",sup,temp);
    cat_str(temp,"</sup>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _mark (const String mar){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<mark>",mar,temp);
    cat_str(temp,"</mark>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static int _iframe (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        return Html_error;
    } else {
        cat_str("<iframe ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"</iframe>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _embed (const String attributes, const String em){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<embed>",em,temp);
        cat_str(temp,"</embed>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<embed ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,em,temp_5);
        cat_str(temp_5,"</embed>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _audio (const String attributes, const String au){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<audio>",au,temp);
        cat_str(temp,"</audio>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<audio ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,au,temp_5);
        cat_str(temp_5,"</audio>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _table (const String t){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<table>",t,temp);
    cat_str(temp,"</table>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _table_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<table>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<table ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _table_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</table>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tbody (const String tb){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<tbody>",tb,temp);
    cat_str(temp,"</tbody>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tbody_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<tbody>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<tbody ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _tbody_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</tbody>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _thead (const String th){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<thead>",th,temp);
    cat_str(temp,"</thead>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _thead_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<thead>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<thead ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _thead_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</thead>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tfoot (const String tf){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<tfoot>",tf,temp);
    cat_str(temp,"</tfoot>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tfoot_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<tfoot>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<tfoot ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _tfoot_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</tfoot>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tr (const String attributes, const String tr){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<tr>",tr,temp);
        cat_str(temp,"</tr>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<tr ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,tr,temp_5);
        cat_str(temp_5,"</tr>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _td (const String attributes, const String td){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<td>",td,temp);
        cat_str(temp,"</td>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<td ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,td,temp_5);
        cat_str(temp_5,"</td>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _th (const String attributes, const String th){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<th>",th,temp);
        cat_str(temp,"</th>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<th ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,th,temp_5);
        cat_str(temp_5,"</th>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _label (const String attributes, const String label){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<label>",label,temp);
        cat_str(temp,"</label>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<label ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,label,temp_5);
        cat_str(temp_5,"</label>",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _select (const String sec){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<select>",sec,temp);
    cat_str(temp,"</select>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _select_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<select>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<select ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _select_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</select>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _option (const String ops){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<option>",ops,temp);
    cat_str(temp,"</option>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _option_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    char temp_5[HTML_LONG];
    if(attributes == NULL){
        cat_str("<option>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<option ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _option_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</option>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _caption (const String cap){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<caption>",cap,temp);
    cat_str(temp,"</caption>",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static int _send_html (server * server, int js_on){
    if (listen(server->server_fd, 3) < 0){
        return Html_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        return Html_error;
    }
    char *response_2[BUFFER_SIZE];
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    if(js_on == Js_errors_on){
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<script>window.onerror = function(message, source, lineno, colno, error) {let errorDiv = document.getElementById('error-log');if (errorDiv) {errorDiv.innerHTML += '<strong style=\"color:red;\">Error:</strong> ' + message + '<br>';}};</script><div id=\"error-log\"></div>", true_html, response_2);
    } else if(js_on == Js_errors_off){
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", true_html, response_2);
    }
    write(server->new_socket, response_2, strlen(response_2));
    close(server->new_socket);
    return Html_ok;
}

void _delete (){
    memset(true_html, 0, sizeof(true_html));
}

void viewHtml (){
    printf("%s\n",true_html);
}

void _show_html_console (){
    printf("HTML send(length: %ld): %s\n",strlen(true_html),true_html);
}

void ini_html (html * html){
    html->show_html_console = _show_html_console;
    html->view_html = viewHtml;
    html->title = _title;
    html->html_o = _html_o;
    html->html_c = _html_c;
    html->canvas_o = _canvas_o;
    html->canvas_c = _canvas_c;
    html->h1 = _h1;
    html->h2 = _h2;
    html->h3 = _h3;
    html->h4 = _h4;
    html->h5 = _h5;
    html->h6 = _h6;
    html->p = _p;
    html->button = _button;
    html->script = _script;
    html->center_o = _center_open;
    html->center_c = _center_close;
    html->send = _send_html;
    html->div = _div;
    html->div_o = _div_o;
    html->div_c = _div_c;
    html->style = _style;
    html->body_o = _body_o;
    html->body_c = _body_c;
    html->body = _body;
    html->head_o = _head_o;
    html->head_c = _head_c;
    html->head = _head;
    html->img = _img;
    html->a = _a;
    html->section_o = _section_o;
    html->section_c = _section_c;
    html->section = _section;
    html->article_o = _article_o;
    html->article_c = _article_c;
    html->article = _article;
    html->header_o = _header_o;
    html->header_c = _header_o;
    html->header = _header;
    html->footer = _footer;
    html->footer_o = _footer_o;
    html->footer_c = _footer_c;
    html->video = _video;
    html->form = _form;
    html->form_o = _form_o;
    html->form_c = _form_c;
    html->input = _input;
    html->meta = _meta;
    html->link = _link;
    html->aside = _aside;
    html->hr = _hr;
    html->br = _br;
    html->pre = _pre;
    html->center = _center;
    html->textarea = _textarea;
    html->blockquote = _blockquote;
    html->ol = _ol;
    html->ol_o = _ol_o;
    html->ol_c = _ol_c;
    html->ul = _ul;
    html->ul_o = _ul_o;
    html->ul_c = _ul_c;
    html->li = _li;
    html->dl = _dl;
    html->dl_o = _dl_o;
    html->dl_c = _dl_c;
    html->dt = _dt;
    html->dt_o = _dt_o;
    html->dt_c = _dt_c;
    html->dd_o = _dd_o;
    html->dd_c = _dd_c;
    html->figure = _figure;
    html->figure_o = _figure_o;
    html->figure_c = _figure_c;
    html->small = _small;
    html->cite = _cite;
    html->sub = _sub;
    html->sup = _sup;
    html->mark = _mark;
    html->iframe = _iframe;
    html->embed = _embed;
    html->audio = _audio;
    html->table = _table;
    html->table_o = _table_o;
    html->table_c = _table_c;
    html->tbody = _tbody;
    html->tbody_o = _tbody_o;
    html->tbody_c = _tbody_c;
    html->thead = _thead;
    html->thead_o = _thead_o;
    html->thead_c = _thead_c;
    html->tfoot = _tfoot;
    html->tfoot_o = _tfoot_o;
    html->tfoot_c = _tfoot_c;
    html->tr = _tr;
    html->td = _td;
    html->th = _th;
    html->label = _label;
    html->select = _select;
    html->select_o = _select_o;
    html->select_c = _select_c;
    html->option = _option;
    html->option_o = _option_o;
    html->option_c = _option_c;
    html->caption = _caption;
    html->i = _i;
    html->b = _b;
    html->e = _e;
    html->em = _em;
    html->resetAllHTML = _delete;
}

void server_file_response(int client_socket, const char *content_type, const char *content){
    char response[BUFFER_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\nContent-Type: %s\nContent-Length: %lu\n\n%s", content_type, strlen(content), content);
    write(client_socket, response, strlen(response));
}

void where(const char *condition, void (*func_1)(), void (*func_2)()){
    if (condition){
        func_1();
    }
    else{
        func_2();
    }
}

int create_file(const String name, const String data, const String read){
    FILE * fp = fopen(name,read);
    if(fp == NULL){
        return Error;
    } 
    fprintf(fp,"%s",data);
    fclose(fp);
    return Ok;
}

void split_lines(const char *text){
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        printf("%s\n", line);
        line = strtok(NULL, "\n");
    }
    free(text_copy);
}

int search_words(const char *text, const char *word){
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        if (strstr(line, word) != NULL){
            return Ok;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error;
}

int searchWordPost (const char *word){
    const char *text = GET_RESPONSE();
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        if (strstr(line, word) != NULL){
            return Ok;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error;
}

static jit page_404 (const String text, const String word){
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        if (strstr(line, word) != NULL){
            return Ok;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error;
}

Array * create_array_int(Array *Array, ...){
    array *Arra = malloc(Array->Int.range * sizeof(array));
    Array->Int.length = Array->Int.range;
    va_list valist;
    va_start(valist, Array->Int.range);
    for (Array->i = 0; Array->i < Array->Int.range; Array->i++){
        array x = va_arg(valist, array);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Int.range; Array->i++){
        Array->Int.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_results(Array *Array, ...){
    array *Arra = malloc(Array->Result.range * sizeof(array));
    Array->Result.length = Array->Result.range;
    va_list valist;
    va_start(valist, Array->Int.range);
    for (Array->i = 0; Array->i < Array->Result.range; Array->i++){
        results x = va_arg(valist, results);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Result.range; Array->i++){
        Array->Result.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_WEBFILES(Array *Array, ...){
    array *Arra = malloc(Array->Web_files.range * sizeof(array));
    Array->Web_files.length = Array->Web_files.range;
    va_list valist;
    va_start(valist, Array->Web_files.range);
    for (Array->i = 0; Array->i < Array->Web_files.range; Array->i++){
        WEB_FILES x = va_arg(valist, WEB_FILES);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Int.range; Array->i++){
        Array->Web_files.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_page_url(Array *Array, ...){
    array *Arra = malloc(Array->Pages_url.range * sizeof(array));
    Array->Pages_url.length = Array->Pages_url.range;
    va_list valist;
    va_start(valist, Array->Pages_url.range);
    for (Array->i = 0; Array->i < Array->Pages_url.range; Array->i++){
        PAGE_URL x = va_arg(valist, PAGE_URL);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Pages_url.range; Array->i++){
        Array->Pages_url.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_String(Array *Array, ...){
    array *Arra = malloc(Array->string.range * sizeof(array));
    Array->string.length = Array->string.range;
    va_list valist;
    va_start(valist, Array->string.range);
    for (Array->i = 0; Array->i < Array->string.range; Array->i++){
        String x = va_arg(valist, String);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->string.range; Array->i++){
        Array->string.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

Array * create_array_Char(Array *Array, ...){
    array *Arra = malloc(Array->Char.range * sizeof(array));
    Array->Char.length = Array->Char.range;
    va_list valist;
    va_start(valist, Array->Char.range);
    for (Array->i = 0; Array->i < Array->Char.range; Array->i++){
        char x = va_arg(valist, char);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->Char.range; Array->i++){
        Array->Char.Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
}

int send_content_server (server * server){
    if (listen(server->server_fd, 3) < 0){
        perror("");
        return Status_ok;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Status_error;
    }
    char *response_2[BUFFER_SIZE];
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", ob, response_2);
    write(server->new_socket, response_2, strlen(response_2));
    close(server->new_socket);
}

size_t write_callback(void *buffer, size_t size, size_t nmemb, void *userp) {
    String data = (String)buffer;
    ob = data;
    return size * nmemb;
}

int open_ (const String solicitud, const String params_post, const String page_url){
    _get ="GET";
    _post = "POST";
    if(strcmp(solicitud,_get) == 0){
        result_ = Ini_request;
        resq = "GET";
        pages_request = page_url;
        return Ini_request;
    } else if(strcmp(solicitud,_post) == 0){
        result_ = Ini_request;
        resq = "POST";
        pages_request = page_url;
        if(params_post == NULL){
            printf("WebCUtils : error, post_params is NULL\n");
            return No_ini_request;
        }
        post_params_request = params_post;
        return Ini_request;
    }
    printf("WebCUtils : no ini request\n");
    return No_ini_request;
}

String load_(){
    return ob;
}

void close_ (){
    _get = "GET";
    _post = "POST";
    pages_request = NULL;
    post_params_request = NULL;
    resq = NULL;
    result_ = '\0';
    ob = NULL;
}

int send_ (){
    if(result_ == Ini_request){
        if(strcmp(resq,_get) == 0){
            CURL *curl;
            CURLcode res;
            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, pages_request);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
                res = curl_easy_perform(curl);
                if (res != CURLE_OK) {
                    return Status_error;
                }
                curl_easy_cleanup(curl);
            }
            curl_global_cleanup();
            return Status_ok;
        } else if(resq,_post){
            CURL *curl;
            CURLcode res;
            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, pages_request);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_params_request);
                res = curl_easy_perform(curl);
                if (res != CURLE_OK) {
                    return Status_error;
                }
                curl_easy_cleanup(curl);
            }
            curl_global_cleanup();
            return Status_ok;
        } else {
            return Status_error;
        }
    }
    return Status_error;
}

void prepare_request (request * request){
    request->open_ = open_;
    request->load_ = load_;
    request->close_ = close_;
    request->send_ = send_;
    request->send_content_server = send_content_server;
}

void get_date(date *date){
    time_t tiempo;
    struct tm *tm_info;
    time(&tiempo);
    tm_info = localtime(&tiempo);
    strftime(date->current_date, 20, "%Y-%m-%d", tm_info);
}

void get_time(date *date){
    time_t tiempo;
    struct tm *tm_info;
    time(&tiempo);
    tm_info = localtime(&tiempo);
    strftime(date->hour, 9, "%H:%M:%S", tm_info);
}

int time_cmp(date *date, const String other_hour){
    if (strcmp(date->hour, other_hour)){
        return Web_true;
    }
    return Web_false;
}

int date_cmp(date *date, const String other_date){
    if (strcmp(date->current_date, other_date)){
        return Web_true;
    }
    return Web_false;
}

int date_cmp_func(date *date, const String other_date, void (*func)()){
    if (strcmp(date->current_date, other_date)){
        func();
    }
    return Web_false;
}

int time_cmp_func(date *date, const String other_hour, void (*func)()){
    if (strcmp(date->hour, other_hour)){
        func();
    }
    return Web_false;
}

int execute_query (sqlite * g, server * server){
    sqlite3 *db;
    char *errMsg = 0;
    char * msgErrorW[BUFFER_SIZE];
    char msgErrorW2[BUFFER_SIZE];
    char msgErrorW3[BUFFER_SIZE];
    int result = sqlite3_open(g->baseData, &db);
    if (listen(server->server_fd, 3) < 0){
        return Database_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        return Database_error;
    }
    if (result != SQLITE_OK) {
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n","<b><span style=\"color: red\">Error-sqlite</span>: not open sqlite</b>",msgErrorW);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, msgErrorW, strlen(msgErrorW));
        close(server->new_socket);
        fprintf(stderr, "WebCUtils: %s\n", sqlite3_errmsg(db));
        return Database_error;
    }
    result = sqlite3_exec(db, g->query, 0, 0, &errMsg);
    if (result != SQLITE_OK) {
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n","<b><span style=\"color: red\">Error-sqlite</span>:  ",msgErrorW2);
        cat_str(msgErrorW2,errMsg,msgErrorW3);
        cat_str(msgErrorW3,"</b>",msgErrorW);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, msgErrorW, strlen(msgErrorW));
        close(server->new_socket);
        fprintf(stderr, "WebCUtils: %s\n", errMsg);
        sqlite3_free(errMsg);
        return Database_error;
    } 
    sqlite3_close(db);
    return Database_ok;
}

int insert_database(const char* name_base, int total_data, const char* sql, const char* insert, ...) {
    sqlite3* db;
    char* err_msg = 0;
    int rc, i;
    char insert_query[100];
    char chonps[1000];
    va_list args;
    rc = sqlite3_open(name_base, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "%s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return Database_error;
    }
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "%s\n", sqlite3_errmsg(db));
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return Database_error;
    }
    va_start(args, insert);
    for (i = 0; i < total_data; i++) {
        String count = va_arg(args, String);
        strcpy(chonps, "some value");
        if (sprintf(insert_query, insert, count) < 0) {
            fprintf(stderr, "Error in sprintf\n");
            sqlite3_close(db);
            return Database_error;
        }
        printf("%s\n",insert_query);
    }
    rc = sqlite3_exec(db, insert_query, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "%s\n", sqlite3_errmsg(db));
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return Database_error;
        }
    va_end(args);
    sqlite3_close(db);
    return Database_ok;
}

int create_cookie(server *server, const char *request, const char *data_cookie){
    recv(server->valread, request, BUFFER_SIZE, 0);
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char response[BUFFER_SIZE];
    FILE *fp = fopen(server->cookie_file_name, "w");
    if (fp == NULL){
        perror("");
        return Web_error;
    }
    else{
        fprintf(fp, "%s", data_cookie);
    }
    close(server->valread);
    fclose(fp);
    server->cookie_active = Is_active;
    return Is_active;
}

int remove_cookie(server *server){
    if (remove(server->cookie_file_name) == Error){
        perror("");
        return Web_error;
    }
    server->cookie_active = Is_no_active;
    return Is_no_active;
}

String read_cookie(server *servidor, const char *request){
    recv(servidor->valread, request, BUFFER_SIZE, 0);
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(servidor->cookie_time, sizeof(servidor->cookie_time), "%Y-%m-%d %H:%M:%S", tm_info);
    char response[BUFFER_SIZE];
    char data[BUFFER_SIZE];
    FILE *cookie = fopen(servidor->cookie_file_name, "r");
    if (cookie == NULL){
        perror("");
        return Web_error;
    }
    else{
        while (feof(cookie) == 0){
            fgets(data, BUFFER_SIZE, cookie);
            snprintf(response, BUFFER_SIZE, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n%s", data);
        }
    }
    close(servidor->valread);
    fclose(cookie);
    return response;
}

String get_referer (){
    String text = GET_RESPONSE();
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    String word = "Referer: http://localhost:8090/";
    int ini = strlen(word);
    int end_index;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        word = "er: http://localhost:8090/";
        ini = strlen(word);
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

String simple_get (){
    String text = GET_RESPONSE();
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    String word = "GET /";
    int ini = strlen(word);
    int end_index;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

String simple_post (){
    String text = GET_RESPONSE();
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    String word = "POST /";
    int ini = strlen(word);
    int end_index;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

char * post (const String word, int ini, int end_index, String save_post){
    String text = GET_RESPONSE();
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                save_post = result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

char * get(const char *text, const char *word, int ini, int end_index, server *server){
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    char response[BUFFER_SIZE];
    size_t bytesRead;
    FILE *fp;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                fp = fopen(result, "r");
                if (fp == NULL){
                    return Web_error;
                }
                while ((bytesRead = fread(response, 1, sizeof(response), fp)) > 0){
                    send(server->client_socket, response, bytesRead, 0);
                }
                fclose(fp);
                close(server->client_socket);
                return Web_ok;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

String getPlatform (){
    String text = GET_RESPONSE();
    String word = "sec-ch-ua-platform: ";
    int ini = 20;
    int end_index = 10;
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    while (line != NULL){
        String word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

int send_email(email *email){
    CURL *curl;
    CURLcode res = CURLE_OK;
    curl = curl_easy_init();
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, email->smtp_url);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, email->mail_from);
        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, email->recipient);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_USERNAME, email->smtp_user);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, email->smtp_password);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, email->payload_text);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "%s\n", curl_easy_strerror(res));
            
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    return (int)res;
}

int have_file (){
    String text = GET_RESPONSE();
    char * word = "Content-Length";
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        if (strstr(line, word) != NULL){
            return Have_file;
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return No_have_file;
}

int getLengthNameFile (files * f){
    String text = GET_RESPONSE();
    char *word = "filename=\"";
    int ini = 9;
    int end_index = 50;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_namefile = strlen(result);
                f->len_namefile = f->len_namefile-1;
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

char *getFileName(files * f, const char *text, int end_index){
    char *word = "filename=\"";
    int ini = 10;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    end_index = end_index - 2;
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index-1 <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_namefile = strlen(result);
                f->name_file = result;
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

int getLengthTypeFile (files * f, const String text){
    char *word = "Content-Type: ";
    int ini = 15;
    int end_index = 10;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_typefile = strlen(result);
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

char *getTypeFile(files * f, const char *text, int end_index){
    char *word = "Content-Type:";
    int ini = 13;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_typefile = strlen(result);
                if(f->len_typefile > end_index){
                    f->status_file = Error_length_string_up;
                    return Error_length_string_up;
                } else if(f->len_typefile < end_index){
                    f->status_file = Error_length_string_down;
                    return Error_length_string_down;
                }
                f->type_file = result;
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

int getLengthStringFile (files * f){
    String text = GET_RESPONSE();
    char *word = "Content-Length: ";
    int ini = 15;
    int end_index = 10;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_file = strlen(result);
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

char *getLengthFile(files * f, const char *text, int end_index){
    char *word = "Content-Length: ";
    int ini = 15;
    char *text_copy = strdup(text);
    char *line = strtok(text_copy, "\n");
    while (line != NULL){
        char *word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                char *result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                f->len_file = strlen(result);
                if(f->len_file > end_index){
                    f->status_file = Error_length_string_up;
                    return Error_length_string_up;
                } else if(f->len_file < end_index){
                    f->status_file = Error_length_string_down;
                    return Error_length_string_down;
                }
                f->length_file = result;
                return Ok_file;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Error_file;
}

int pre_uploaded_file (files * f, server * server){
    f->end_of_header = strstr(buffer, "\r\n\r\n");
    if (f->end_of_header != NULL) {
        f->body_offset = f->end_of_header  + 4 - buffer;
        f->pre = 1;
        f->content_file = buffer + f->body_offset;
        f->length = server->valread - f->body_offset;
    } else {
        puts("WebCUtils: not have content file");
        return Error_file;
    }
}

int uploaded_file (files * f){
    if(f->pre == 1){
        FILE* file = fopen(f->name_file, "wb");
        if (file != NULL) {
            fwrite(f->content_file, sizeof(char), f->length, file);
            fclose(file);
            f->pre = 0;
            return Ok_file;
        } else {
            perror("WebCUtils ");
            f->pre = 0;
            return Error_file;
        }
    } else {
        puts("WebCUtils: pre_uploaded_file() not declared");
        f->pre = 0;
        return Ok_file;
    }
}

int permission_download_file (files * f, server * server){
    
    f->file_down = fopen(f->file_name_down, "rb");
    size_t bytes_read;
    char r_headers_1[BUFFER_SIZE];
    char r_headers_2[BUFFER_SIZE];
    cat_str("HTTP/1.1 200 OK\r\nContent-Disposition: attachment; filename=\"",f->file_name_down,r_headers_1);
    cat_str(r_headers_1,"archivo.txt\"\r\nContent-Type: text/plain\r\n\r\n",r_headers_2);
    if(f->file_down == NULL){
        perror("WebCUtils ");
        return Error_file;
    } else {
        send(server->client_socket, r_headers_2, strlen(r_headers_2), 0);
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), f->file_down)) > 0) {
            send(server->client_socket, buffer, bytes_read, 0);
        }
        fclose(f->file_down);
        return Ok_file;
    }
    
}

int save_response(const char *data, const char * namefile){
    FILE *fp = fopen(namefile, "a");
    if (fp == NULL){
        return Web_error;
    }
    fprintf(fp, "%s", data);
    fclose(fp);
    return Web_ok;
}

char *get_response(){
    return buffer;
}

int send_simple_response(server *server, const char *response){
    if (listen(server->server_fd, 3) < 0){
        perror("");
        return Web_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Web_error;
    }
    char *response_2[BUFFER_SIZE];
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", response, response_2);
    write(server->new_socket, response_2, strlen(response_2));
    close(server->new_socket);
}

int _response_args(server *server, int total,const char *response, ...){
    int i;
    if (listen(server->server_fd, 3) < 0){
        perror("");
        return Web_error;
    }
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Web_error;
    }
    char *response_2[BUFFER_SIZE], response_total[BUFFER_SIZE];
    if(total < 1){
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", response, response_2);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, response_2, strlen(response_2));
         close(server->new_socket);
         return Ok;
    } else {
        va_list args;
        va_start(args, response);
        for (i = 0; i < total + 1 - 1; i++){
             String count = va_arg(args, String);
             sprintf(response_2, response, count);
        }
        va_end(args);
        cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n",response_2,response_total);
        server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
        write(server->new_socket, response_total, strlen(response_total));
        close(server->new_socket);
    }
}

int send_response_server_view_js(server *server, const char *archivo){
    char response_2[BUFFER_SIZE];
    const String js = "<script>window.onerror = function(message, source, lineno, colno, error) {let errorDiv = document.getElementById('error-log');if (errorDiv) {errorDiv.innerHTML += '<strong>Error:</strong> ' + message + '<br>';}};</script><div id=\"error-log\"></div>";
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Error;
    }
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    FILE *file = fopen(archivo, "r");
    if (file == NULL){
        perror("");
        return Error;
    }
    char html_content[server->buffer_file];
    size_t html_size = fread(html_content, sizeof(char), server->buffer_file, file);
    cat_str(js,html_content,response_2);
    fclose(file);
    server_file_response(server->new_socket, "text/html", response_2);
    close(server->new_socket);
}

int Server_response_variadic(server *server, const char *archivo, int total, ...){
    int i;
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Error;
    }
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    FILE *file = fopen(archivo, "r");
    if (file == NULL){
        perror("");
        return Error;
    }
    char html_content[server->buffer_file];
    size_t html_size = fread(html_content, sizeof(char), server->buffer_file, file);
    fclose(file);
    va_list args;
    va_start(args, html_content);
    char response_2[BUFFER_SIZE];
    for (i = 0; i < total; i++){
          String count = va_arg(args, String);
          sprintf(response_2, html_content, count);
     }
    va_end(args);
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    server_file_response(server->new_socket, "text/html", response_2);
    close(server->new_socket);
}

static String _requestedURL(){
    String text = GET_RESPONSE();
    String word = "Referer: ";
    jit ini = strlen(word);
    jit end_index = Localhost_url_length;
    String text_copy = strdup(text);
    String line = strtok(text_copy, "\n");
    while (line != NULL){
        String word_position = strstr(line, word);
        if (word_position != NULL){
            size_t start_index = word_position + ini - line;
            if (start_index + end_index <= strlen(line)){
                String result = malloc(end_index + 1);
                strncpy(result, line + start_index, end_index);
                result[end_index] = '\0';
                free(text_copy);
                return result;
            }
        }
        line = strtok(NULL, "\n");
    }
    free(text_copy);
    return Web_error;
}

int open_server(server *server){
    server->opt = 1;
    server->addrlen = sizeof(server->address);
    server->load_buffer = load_buffer;
    server->page_404 = page_404;
    long_buffer_size = server->buffer_size_web;
    server->requestedURL = _requestedURL;
    if ((server->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("");
        return Error;
    }
    if (setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &server->opt, sizeof(server->opt))){
        perror("");
        return Error;
    }
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(server->port);
    if (bind(server->server_fd, (struct sockaddr *)&server->address, sizeof(server->address)) < 0){
        perror("");
        return Error;
    }
    if (listen(server->server_fd, 3) < 0){
        perror("");
        return Error;
    }
}

int send_response_server (server *server, const char *archivo){
    if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0){
        perror("");
        return Error;
    }
    server->valread = read(server->new_socket, buffer, BUFFER_SIZE);
    FILE *file = fopen(archivo, "r");
    if (file == NULL){
        perror("");
        return Error;
    }
    char html_content[server->buffer_file];
    size_t html_size = fread(html_content, sizeof(char), server->buffer_file, file);
    fclose(file);
    server_file_response(server->new_socket, "text/html", html_content);
    close(server->new_socket);
}

void ini_simple_server(server *S){
    S->opt = 1;
    S->addrlen = sizeof(S->address);
    S->error = Ok;
}

int config_simple_server(server *S){
    S->error = Error;
    if ((S->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("");
        return S->error;
    }
    if (setsockopt(S->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &S->opt, sizeof(S->opt))){
        perror("");
        return S->error;
    }
    S->address.sin_family = AF_INET;
    S->address.sin_addr.s_addr = INADDR_ANY;
    S->address.sin_port = htons(S->port);
    if (bind(S->server_fd, (struct sockaddr *)&S->address, sizeof(S->address)) < 0){
        perror("");
        return S->error;
    }
}

int send_response_simple_server(server * S, const char *response){
    if (listen(S->server_fd, 3) < 0){
        perror("");
        return S->error;
    }
    if ((S->new_socket = accept(S->server_fd, (struct sockaddr *)&S->address, (socklen_t *)&S->addrlen)) < 0){
        perror("");
        return S->error;
    }
    S->valread = read(S->new_socket, buffer, BUFFER_SIZE);
    write(S->new_socket, response, strlen(response));
    close(S->new_socket);
}

#endif
 
