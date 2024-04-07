#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

typedef signed char results;
typedef char *PAGE_URL;
typedef char *WEB_FILES;
typedef char *String;
typedef int array;
typedef int *ptr;
typedef int jit;

typedef struct{
	char current_date[20];
	char hour[9];
} date;

#define BUFFER_SIZE 100096
#define BUFFER_SIZE_3 10096
#define HTML_LONG 10096
#define MAX_COOKIES 10
#define V 200
#define Q 50
#define _URL const char * 
#define SMTP_TEXT 500
#define _POST char *post
#define POST post
#define _GET char *get
#define GET get
#define IMAGE_PNG_FILE "image/png"
#define IMAGE_JPEG_FILE "image/jpeg"
#define VIDEO_MP4_FILE "video/mp4"
#define OCTET_STREAM_FILE "application/octet-stream"
#define ANDROID_APP_FILE "application/vnd.android.package-archive"
#define OS_ANDROID "\"Android\""
#define OS_LINUX "\"Linux\""
#define OS_WINDOWS "\"Windows\""
#define MAX_SESSIONS 100
#define MAX_SESSION_ID_LENGTH 5
#define END_SESSION -10
#define NOT_END_SESSION 10 
#define WEB_OK 1
#define WEB_ERROR -1
#define WEB_TRUE 1
#define WEB_FALSE 0
char buffer[BUFFER_SIZE] = {0};
char true_html[BUFFER_SIZE_3] = " ";
char result_html[BUFFER_SIZE_3] = "<html>";
char _hh[BUFFER_SIZE_3];
char total_2[BUFFER_SIZE_3];
char total_html[BUFFER_SIZE_3];
String ob;
int long_buffer_size = BUFFER_SIZE;
int pre = 0;
String content_file;
size_t length;
size_t body_offset;
String end_of_header;
char *_post;
char *_get;
char cookie_value[30];
String ob;
char *ress;
String _get;
String _post;
int result_;
String resq;
PAGE_URL pages_request;
String post_params_request;
char buffer_2[BUFFER_SIZE][BUFFER_SIZE];
String Response;
struct curl_slist *header;
int logDataSqlite = 100;
String rows[3][3];
String nameElements[3];

#define GET_RESPONSE() buffer

typedef struct{
	char smtp_url[V];
	char smtp_user[V];
	char smtp_password[V];
	char mail_from[V];
	char recipient[V];
	char payload_text[SMTP_TEXT];
} email;

enum normalErrors {
    Error = -1,
    Ok = 2,
};

enum boolsWeb {
    Web_true = 1,
    Web_false = 0
};

enum webErrors {
    Web_ok = 1,
    Web_error = -5
};

enum fileErrors {
    Web_file_error = -7,
    Error_length_string_up = -12,
    Error_length_string_down = -11,
    Have_file = 21,
    No_have_file = -21,
    Error_file = -210,
    Ok_file = 210
};

enum cookiesErrors {
    Is_active = 200,
    Is_no_active = -200
};

enum resquestErrors {
    Status_ok = 400,
    Status_error = -400,
    Ini_request = 10,
    No_ini_request = -10
};

enum htmlErrorAndDefines {
    Html_error = -303,
    Html_ok = 303
};

enum jsDef {
    Js_errors_on = 220,
    Js_errors_off = -220
};

enum database {
    Database_ok = 2,
    Database_error = -2
};

enum others {
    Localhost_url_length = 200,
};

#endif
