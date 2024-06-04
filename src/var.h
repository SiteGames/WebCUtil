#ifndef VAR_H
#define VAR_H

typedef const char * String;

#define ERROR 500
#define OK 200
#define NOT_FOUND 404
#define EMPTY NULL
#define V 200
#define PAGE String
#define BUFFER_SIZE 100096
#define BUFFER_SIZE_3 10096
#define HTML_LONG 10096
char buffer[BUFFER_SIZE] = {0};
#define GET_RESPONSE() buffer

char true_html[BUFFER_SIZE_3] = " ";
char result_html[BUFFER_SIZE_3] = "<html>";
int pre = 0;
String content_file;
size_t length;
size_t body_offset;
String end_of_header;

enum {
	false,
	true
}boolean;

typedef struct{
	int buffer_size_web;
	int server_fd, new_socket, valread, client_socket;
	struct sockaddr_in address, client_address;
	socklen_t client_address_length;
	int opt;
	int addrlen;
	int error;
	int port;
	String url;
	int buffer_file;
	int buffer_img;
	char cookie_time[30];
	char cookie_file_name[V];
	int cookie_active;
	int (*reset)();
	int (*close)();
	String (*load_buffer)();
	int (*page_404)(const String, const String);
	String (*requestedURL)();
	void (*decrypt)(char *, int);
	void (*encrypt)(char *, int);
	char *(*descryptCharURL)(char *);
	int (*saveBuffer)(const String);
	void (*showBuffer)();
	String (*convertJsonData)(String [], String []);
	int (*rebuilt_file)(const String, const String, int);
	int (*registers_url)();
}Server;

typedef struct {
	int (*save)(const String, const String, const String, const String);
	int (*delete)(const String);
	char dat[2024];
	String nameData;
	String (*getValue)(const String, const String, const String);
	void (*resetData)(const String);
	String (*getDat)(const String);
}Properties;

typedef struct{
	char current_date[20];
	char hour[9];
} date;

typedef struct{
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
	void (*script_src)(const String, Server *, int);
	void (*div)(const String);
	void (*div_o)(const String);
	void (*div_c)();
	void (*body_o)(const String);
	void (*body_c)();
	void (*body)();
	void (*head_o)(const String);
	void (*head_c)();
	void (*head)(const String);
	int (*img)(const String);
	int (*a)(const String, const String);
	void (*main_o)(const String);
	void (*main_c)();
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
	void (*nav_o)(const String);
	void (*nav_c)();
	void (*nav)();
	void (*script_o)();
	void (*script_c)();
	void (*style_o)();
	void (*style_c)();
	void (*style_src)(const String, Server *, int);
	void (*php)(const String);
	void (*text)(const String);
	int (*send)(Server *);
	void (*tr_o)(const String);
	void (*tr_c)();
	void (*load_extern_html)(const String);
}BuildHtml;

typedef struct{
	String (*name_archive)();
	String (*size_archive)();
	String (*type_archive)();
	int (*prepare_save)(Server *);
	int (*save)(const String );
	int (*isset_archive)();
	int (*upload)(Server *, const char *);
	void (*create_archive)(const String, const String, const String);
	String name;
	String type;
	String length;
}Archives;

typedef struct {
	struct{
		int (*isset)(const String);
		char * (*get_name)(const char *, char);
		int (*read_img)(Server *);
	    int (*read_video)(Server *);
	}Get;
	struct{
		int (*isset)(const String);
		char * (*post_name)(const char *, char);
	}Post;
	const int code;
	const char *str;
    int (*isset)(const String);
    char * (*get_isset)(const char *, char);
}Http;

typedef struct{
	String (*contentLength)();
	String (*platform_user)();
	String (*referer)();
	String (*accept_language)();
	String (*host)();
	String (*connection)();
	String (*accept)();
	String (*accept_encoding)();
	String (*user_agent)();
	String (*upgrade_insecure_requests)();
}Response;

typedef struct{
	int (*open_)(const String, const String, const String);
	String (*load_)();
	void (*close_)();
	int (*send_)();
	int (*send_content_server)(Server *);
	int (*open_local)(const String, const String);
	int status;
	String data;
	const String url;
	struct curl_slist * headers;
	int (*open_url)(const String);
	char * (*connect)(const String, const String, const String, const String, char *);
}Connect;

Http status_map[] = {
	{100, "Continue"},
	{101, "Switching Protocols"},
	{200, "OK"},
	{201, "Created"},
	{202, "Accepted"},
	{203, "Non-Authoritative Information"},
	{204, "No Content"},
	{205, "Reset Content"},
	{206, "Partial Content"},
	{300, "Multiple Choices"},
	{301, "Moved Permanently"},
	{302, "Found"},
	{303, "See Other"},
	{304, "Not Modified"},
	{305, "Use Proxy"},
	{307, "Temporary Redirect"},
	{308, "Permanent Redirect"},
	{400, "Bad Request"},
	{401, "Unauthorized"},
	{402, "Payment Required"},
	{403, "Forbidden"},
	{404, "Not Found"},
	{405, "Method Not Allowed"},
	{406, "Not Acceptable"},
	{407, "Proxy Authentication Required"},
	{408, "Request Timeout"},
	{409, "Conflict"},
	{410, "Gone"},
	{411, "Length Required"},
	{412, "Precondition Failed"},
	{413, "Request Entity Too Large"},
	{414, "Request-URI Too Long"},
	{415, "Unsupported Media Type"},
	{416, "Requested Range Not Satisfiable"},
	{417, "Expectation Failed"},
	{426, "Upgrade Required"},
	{428, "Precondition Required"},
	{429, "Too Many Requests"},
	{431, "Request Header Fields Too Large"},
	{451, "Unavailable For Legal Reasons"},
	{500, "Internal Server Error"},
	{501, "Not Implemented"},
	{502, "Bad Gateway"},
	{503, "Service Unavailable"},
	{504, "Gateway Timeout"},
	{505, "HTTP Version Not Supported"},
	{506, "Variant Also Negotiates"},
	{511, "Network Authentication Required"},
	{0, EMPTY}
};

#endif
