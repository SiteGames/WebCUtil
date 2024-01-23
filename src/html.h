#ifndef HTML_H
#define HTML_H

static char true_html[BUFFER_SIZE_3] = " ";
static char result_html[BUFFER_SIZE_3] = "<html>";
static char _hh[BUFFER_SIZE_3];
static char total_2[BUFFER_SIZE_3];
static char total_html[BUFFER_SIZE_3];

void cat_str(const String texto1, const String texto2, String resultado){
    strcpy(resultado, texto1);
    strcat(resultado, texto2);
}

void _title (const String title){
    char temp[HTML_LONG];
    cat_str("<title>",title, temp);
    cat_str(temp,"</title>\n",result_html);
    cat_str(result_html,"",true_html);
}

static void _canvas_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<canvas>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<canvas ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</canvas>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _html_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<!DOCTYPE html><html>\n","",temp);
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
    cat_str(temp,"</html>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _center_open (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<center>","\n",temp);
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
    cat_str(temp,"</center>\n",temp_2);
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
        cat_str(temp,"</h1>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h1 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h1,temp_5);
        cat_str(temp_5,"</h1>\n",temp_2);
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
        cat_str(temp,"</h2>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h2 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h2,temp_5);
        cat_str(temp_5,"</h2>\n",temp_2);
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
        cat_str(temp,"</h3>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h3 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h3,temp_5);
        cat_str(temp_5,"</h3>\n",temp_2);
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
        cat_str(temp,"</h4>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h4 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h4,temp_5);
        cat_str(temp_5,"</h4>\n",temp_2);
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
        cat_str(temp,"</h5>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h5 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h5,temp_5);
        cat_str(temp_5,"</h5>\n",temp_2);
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
        cat_str(temp,"</h6>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<h6 ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,h6,temp_5);
        cat_str(temp_5,"</h6>\n",temp_2);
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
        cat_str(temp,"</i>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<i ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,i,temp_5);
        cat_str(temp_5,"</i>\n",temp_2);
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
        cat_str(temp,"</b>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<b ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,b,temp_5);
        cat_str(temp_5,"</b>\n",temp_2);
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
        cat_str(temp,"</e>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<e ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,e,temp_5);
        cat_str(temp_5,"</e>\n",temp_2);
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
        cat_str(temp,"</em>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<em ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,em,temp_5);
        cat_str(temp_5,"</em>\n",temp_2);
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
        cat_str(temp,"</p>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<p ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,p,temp_5);
        cat_str(temp_5,"</p>\n",temp_2);
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
        cat_str(temp,"</button>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<button ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,button,temp_5);
        cat_str(temp_5,"</button>\n",temp_2);
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
        cat_str(temp,"</script>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<script ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,script,temp_5);
        cat_str(temp_5,"</script>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    }
}

static void _style (const String style){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<style>",style,temp);
    cat_str(temp,"</style>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _div (const String div){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<div ",div,temp);
    cat_str(temp,"></div>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _div_o (const String attributes, const String t){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        if(t == NULL){
            printf("WebCUtils: the second param is 'NULL'\n");
            return;
        }
        cat_str("<div>",t,temp);
        cat_str(temp,"\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        if(t == NULL){
            printf("WebCUtils: the second param is 'NULL'\n");
            return;
        }
        cat_str("<div ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</div>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _body_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<body>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<body ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</body>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _body (const String body){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<body>",body,temp);
    cat_str(temp,"</body>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _head_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<head>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<head ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</head>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _head (const String head){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<head>",head,temp);
    cat_str(temp,"</head>\n",temp_2);
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
        cat_str(temp,">\n",temp_2);
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
        cat_str(temp_5,"</a>\n",temp_2);
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
    if(attributes == NULL){
        cat_str("<section>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<section ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</section>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _section (const String section){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<section ",section,temp);
    cat_str(temp,"></section>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _article_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<article>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<article ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</article>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _article (const String article){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<article>",article,temp);
    cat_str(temp,"</article>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _header_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<header>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<header ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</header>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _header (const String header){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<header>",header,temp);
    cat_str(temp,"</header>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _footer (const String footer){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<footer>",footer,temp);
    cat_str(temp,"</footer>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _footer_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<footer>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<footer ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</footer>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _video (const String video){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<video>",video,temp);
    cat_str(temp,"</video>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _form (const String from){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<footer>",from,temp);
    cat_str(temp,"</footer>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _form_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<form>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<form ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</form>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static int _input (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        return Html_error;
    } else {
        cat_str("<input ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    if(attributes == NULL){
        return Html_error;
    } else {
        cat_str("<meta ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    if(attributes == NULL){
        return Html_error;
    } else {
        cat_str("<link ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</aside>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void  _hr (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<hr>","\n",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _br (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<br>","\n",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _pre (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<pre>","\n",temp);
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
    cat_str(temp,"</center>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _textarea (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<textarea>","",temp);
        cat_str(temp,"</textarea>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<textarea ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"</textarea>\n",temp_2);
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
    cat_str(temp,"</blockquote>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _ol (const String ol){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<ol>",ol,temp);
    cat_str(temp,"</ol>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _ol_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<ol>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<ol ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</ol>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _ul (const String ul){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<ul>",ul,temp);
    cat_str(temp,"</ul>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _ul_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<ul>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<ul ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</ul>\n",temp_2);
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
        cat_str(temp,"</li>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<li ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,li,temp_5);
        cat_str(temp_5,"</li>\n",temp_2);
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
    cat_str(temp,"</dl>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _dl_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<dl>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<dl ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</dl>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _dt (const String _ddt){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<dt>",_ddt,temp);
    cat_str(temp,"</dt>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _dt_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<dt>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<dt ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</dt>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _dd_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<dd>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<dd ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</dd>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _figure (const String fig){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<figure>",fig,temp);
    cat_str(temp,"</figure>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _figure_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<figure>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<figure ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</figure>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _small (const String sm){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<small>",sm,temp);
    cat_str(temp,"</small>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _cite (const String ci){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<cite>",ci,temp);
    cat_str(temp,"</cite>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _sub (const String su){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<sub>",su,temp);
    cat_str(temp,"</sub>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _sup (const String sup){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<sup>",sup,temp);
    cat_str(temp,"</sup>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _mark (const String mar){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<mark>",mar,temp);
    cat_str(temp,"</mark>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static int _iframe (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        return Html_error;
    } else {
        cat_str("<iframe ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,"</iframe>\n",temp_2);
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
        cat_str(temp,"</embed>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<embed ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
        cat_str(temp,em,temp_5);
        cat_str(temp_5,"</embed>\n",temp_2);
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
        cat_str(temp,"</audio>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<audio ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,au,temp_5);
        cat_str(temp_5,"</audio>\n",temp_2);
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
    cat_str(temp,"</table>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _table_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<table>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<table ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</table>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tbody (const String tb){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<tbody>",tb,temp);
    cat_str(temp,"</tbody>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tbody_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<tbody>\n","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<tbody ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</tbody>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _thead (const String th){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<thead>",th,temp);
    cat_str(temp,"</thead>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _thead_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<thead>\n","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<thead ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</thead>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tfoot (const String tf){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<tfoot>",tf,temp);
    cat_str(temp,"</tfoot>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _tfoot_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<tfoot>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<tfoot ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</tfoot>\n",temp_2);
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
        cat_str(temp,"</tr>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<tr ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
        cat_str(temp,tr,temp_5);
        cat_str(temp_5,"</tr>\n",temp_2);
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
        cat_str(temp,"</td>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<td ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
        cat_str(temp,td,temp_5);
        cat_str(temp_5,"</td>\n",temp_2);
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
        cat_str(temp,"</th>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<th ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
        cat_str(temp,th,temp_5);
        cat_str(temp_5,"</th>\n",temp_2);
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
        cat_str(temp,"</label>\n",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<label ",attributes,temp_4);
        cat_str(temp_4,">",temp);
        cat_str(temp,label,temp_5);
        cat_str(temp_5,"</label>\n",temp_2);
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
    cat_str(temp,"</select>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _select_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<select>","\n",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<select ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</select>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _option (const String ops){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<option>",ops,temp);
    cat_str(temp,"</option>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _php (const String ops){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<?php",ops,temp);
    cat_str(temp,"?>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _option_o (const String attributes){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    if(attributes == NULL){
        cat_str("<option>","",temp);
        cat_str(temp,"",temp_2);
        cat_str(true_html,"",temp_3);
        cat_str(temp_2,"",result_html);
        cat_str(temp_3,result_html,true_html);
    } else {
        cat_str("<option ",attributes,temp_4);
        cat_str(temp_4,">\n",temp);
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
    cat_str(temp,"</option>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void coment_1 (){
	cat_str("<!--","",true_html);
}

static void coment_2 (){
	cat_str("-->\n","",true_html);
}

static void _caption (const String cap){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("<caption>",cap,temp);
    cat_str(temp,"</caption>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _php_o (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    cat_str("<?php","",temp_4);
    cat_str(temp_4,"\n",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _php_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"?>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _script_o (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    cat_str("<script>","",temp_4);
    cat_str(temp_4,"\n",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _script_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</script>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _style_o (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    char temp_4[HTML_LONG];
    cat_str("<style>","",temp_4);
    cat_str(temp_4,"\n",temp);
    cat_str(temp,"",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _style_c (){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("","",temp);
    cat_str(temp,"</style>\n",temp_2);
    cat_str(true_html,"",temp_3);
    cat_str(temp_2,"",result_html);
    cat_str(temp_3,result_html,true_html);
}

static void _text (const String cap){
    char temp[HTML_LONG];
    char temp_2[HTML_LONG];
    char temp_3[HTML_LONG];
    cat_str("",cap,temp);
    cat_str(temp,"\n",temp_2);
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
    html->php_o = _php_o;
    html->php_c = _php_c;
    html->script_o = _script_o;
    html->script_c = _script_c;
    html->style_o = _style_o;
    html->style_c = _style_c;
    html->php = _php;
    html->text = _text;
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
    html->coment_o = coment_1;
    html->coment_c = coment_2;
    html->resetAllHTML = _delete;
}
#endif
