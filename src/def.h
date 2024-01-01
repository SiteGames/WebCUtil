#ifndef DEF_H
#define DEF_H

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
