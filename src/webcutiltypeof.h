#ifndef WEBCUTILTYPEOF_H
#define WEBCUTILTYPEOF_H

typedef signed char results;
typedef char * PAGE_URL;
typedef char * WEB_FILES;
typedef char * String;
typedef int array;
typedef int * ptr;
typedef int jit;

typedef struct {
    int buffer_size_web;
    int server_fd, new_socket, valread, client_socket;
    struct sockaddr_in address, client_address;
    socklen_t client_address_length;
    int opt;
    int addrlen;
    int error;
    int port;
    int buffer_file;
    int buffer_img;
    char cookie_time[30];
    char cookie_file_name[V];
    int cookie_active;
    int (*reset)();
    int (*close)();
    String (*load_buffer)();
    jit (*page_404)(const String, const String);
    String (*requestedURL)();
}server;

typedef struct{
    char smtp_url[V];
    char smtp_user[V];
    char smtp_password[V];
    char mail_from[V];
    char recipient[V];
    char payload_text[SMTP_TEXT];
}email;

typedef struct{
    char current_date[20];
    char hour[9];
}date;

typedef struct{
    struct{
        array range;
        array Array[100];
        array length;
    } Int;
    struct{
        array range;
        char Array[100];
        array length;
    } Char;
    struct{
        array range;
        String Array[100];
        array length;
    } string;
    struct{
        array range;
        results Array[100];
        array length;
    } Result;
    struct{
        array range;
        PAGE_URL Array[100];
        array length;
    } Pages_url;
    struct{
        array range;
        WEB_FILES Array[100];
        array length;
    } Web_files;
    array i;
}Array;

typedef struct {
    int (*open_)(const String , const String, const String);
    String (*load_)();
    void (*close_)();
    int (*send_)();
    int (*send_content_server)(server *);
    int (*open_local)(const String, const String);
    int status;
    String data;
}request;

typedef struct {
    String name_file;
    String type_file;
    String length_file;
    int status_file;
    int len_namefile;
    int len_file;
    int len_typefile;
    String content_file;
    size_t length;
    size_t body_offset;
    String end_of_header;
    int pre;
    FILE * file_down;
    String file_name_down;
}files;

typedef struct {
    SSL_CTX * ctx;
    SSL * ssl;
    BIO * bio;
    int port;
    int ini;
}https;

typedef struct {
    String query;
    String baseData;
}sqlite;

typedef struct {
    int long_html;
    void (*show_html_console)();
    void (*resetAllHTML)();
    void (*view_html)();
    void (*title)(const String);
    void (*html_o)(const String);
    void (*html_c)();
    void (*canvas_o)(const String);
    void (*canvas_c)();
    void (*center_o)();
    void (*center_c)();
    void (*h1)(const String, const String);
    void (*h2)(const String, const String);
    void (*h3)(const String, const String);
    void (*h4)(const String, const String);
    void (*h5)(const String, const String);
    void (*h6)(const String, const String);
    void (*i)(const String, const String);
    void (*b)(const String, const String);
    void (*e)(const String, const String);
    void (*em)(const String, const String);
    void (*button)(const String, const String);
    void (*script)(const String, const String);
    void (*script_src)(const String, int);
    void (*div)(const String);
    void (*div_o)(const String, const String);
    void (*div_c)();
    void (*body_o)(const String);
    void (*body_c)();
    void (*body)();
    void (*head_o)(const String);
    void (*head_c)();
    void (*head)(const String);
    int (*img)(const String);
    int (*a)(const String, const String);
    void (*section_o)(const String);
    void (*section_c)();
    void (*section)(const String);
    void (*article_o)(const String);
    void (*article_c)();
    void (*article)(const String);
    void (*header_o)(const String);
    void (*header_c)();
    void (*header)(const String);
    void (*style)(const String);
    void (*footer)(const String);
    void (*footer_o)(const String);
    void (*footer_c)();
    void (*video)(const String);
    void (*source)(const String);
    void (*form)(const String);
    void (*form_o)(const String);
    void (*form_c)();
    int (*input)(const String);
    int (*meta)(const String);
    int (*link)(const String);
    void (*aside)(const String);
    void (*hr)();
    void (*br)();
    void (*pre)();
    void (*center)();
    void (*textarea)(const String);
    void (*blockquote)(const String);
    void (*ol)(const String);
    void (*ol_o)(const String);
    void (*ol_c)();
    void (*ul)(const String);
    void (*ul_o)(const String);
    void (*ul_c)();
    void (*li)(const String, const String);
    void (*dl)();
    void (*dl_o)(const String);
    void (*dl_c)();
    void (*dt)();
    void (*dt_o)(const String);
    void (*dt_c)();
    void (*dd)();
    void (*dd_o)(const String);
    void (*dd_c)();
    void (*figure)();
    void (*figure_o)(const String);
    void (*figure_c)();
    void (*small)();
    void (*cite)();
    void (*sub)();
    void (*sup)();
    void (*mark)();
    int (*iframe)(const String);
    void (*embed)();
    void (*audio)(const String);
    void (*table)();
    void (*table_o)(const String);
    void (*table_c)();
    void (*tbody)(const String);
    void (*tbody_o)(const String);
    void (*tbody_c)();
    void (*thead)(const String);
    void (*thead_o)(const String);
    void (*thead_c)();
    void (*tfoot)(const String);
    void (*tfoot_o)(const String);
    void (*tfoot_c)();
    int (*tr)(const String, const String);
    int (*td)(const String, const String);
    int (*th)(const String, const String);
    void (*label)(const String, const String);
    void (*select)(const String);
    void (*select_o)(const String);
    void (*select_c)();
    void (*option)(const String);
    void (*option_o)(const String);
    void (*option_c)();
    void (*caption)();
    void (*p)(const String, const String);
    void (*coment_o)();
    void (*coment_c)();
    void (*php_o)();
    void (*php_c)();
    void (*script_o)();
    void (*script_c)();
    void (*style_o)();
    void (*style_c)();
    void (*php)(const String);
    void (*text)(const String);
    int (*send)(server *, int);
}html;

#endif
