#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 200
#define EMPTY NULL
#define FOLDERS_LENGTH 8

void concatplus(char *result, const char *format, ...){
	va_list args;
	va_start(args, format);
	va_list args_copy;
	va_copy(args_copy, args);
	int length = vsnprintf(EMPTY, 0, format, args_copy);
	va_end(args_copy);
	vsnprintf(result, length + 1, format, args);
	va_end(args);
}

int main (){
	char nombre_del_proyecto[MAX_LENGTH];
	char name_main_file[MAX_LENGTH];
	char * foldels[] = {
	    "css",
	    "html",
	    "js",
	    "img",
	    "res",
	    "tmp",
	    "transh",
	    "include",
	};
	FILE * main_file;
	puts("\nWelcome a creator the proyects of webCUtil\n");
	printf("Input name the project: ");
	fflush(stdin);
	fgets(nombre_del_proyecto,MAX_LENGTH,stdin);
	fflush(stdin);
	if(strcmp(nombre_del_proyecto,"\n") == 0){
		puts("\nERROR: 'Name of project is EMPTY'");
		return -1;
	}
	printf("Input name the main file: ");
	fflush(stdin);
	fgets(name_main_file, MAX_LENGTH, stdin);
	fflush(stdin);
	if(strcmp(name_main_file,"\n") == 0){
		puts("\nERROR: 'Name of main file is EMPTY'");
		return -1;
	}
	if(mkdir(nombre_del_proyecto,0755) == 0){
	    printf("FOLDER: %s=>'main folder' = Created successfully\n",nombre_del_proyecto);
	    usleep(1000 * 1000);
	    for(int i = 0; i < FOLDERS_LENGTH; i++){
	        char destiny_folder[MAX_LENGTH];
	        concatplus(destiny_folder,"%s/%s",nombre_del_proyecto,foldels[i]);
	        if(mkdir(destiny_folder,0755) == 0){
	            printf("FOLDER: %s => Created successufully in folder '%s'\n",foldels[i],nombre_del_proyecto);
	        } else {
	            perror("ERROR ");
	            printf("ERROR: falled in create project => folder: %s",foldels[i]);
	            return -1;
	        }
	        usleep(1000 * 1000);
	    }
	    char fileMainRute[MAX_LENGTH];
	    concatplus(fileMainRute, "%s/%s.c",nombre_del_proyecto,name_main_file);
	    main_file = fopen(fileMainRute,"w");
	    if(main_file == EMPTY){
	        perror("ERROR with main file");
	        return -1;
	    } else {
	        fprintf(main_file,"#include \"include/webcutil.h\"\n");
	        fprintf(main_file,"#include \"include/sqlite3.h\"");
	        fprintf(main_file,"\n");
	        fprintf(main_file,"void index_page (BuildHtml *);\n");
	        fprintf(main_file,"\n");
	        fprintf(main_file,"int main (){\n");
	        fprintf(main_file,"    Server server;\n");
	        fprintf(main_file,"    server.port = 8080;\n");
	        fprintf(main_file,"    server.buffer_file = 6096;\n");
	        fprintf(main_file,"    server.url = \"127.0.0.1\";\n");
	        fprintf(main_file,"    openServer(&servidor);\n");
	        fprintf(main_file,"    while(1){\n");
	        fprintf(main_file,"        BuildHtml index;\n");
	        fprintf(main_file,"        buildHtml(&index);\n");
	        fprintf(main_file,"        index_page(&index);\n");
	        fprintf(main_file,"        index.send(&server);\n");
	        fprintf(main_file,"        index.resetAllHTML();\n");
	        fprintf(main_file,"        puts(server.load_buffer());\n");
	        fprintf(main_file,"        server.saveBuffer(\"server_log\");\n");
	        fprintf(main_file,"    }\n");
	        fprintf(main_file,"    return 0;\n}\n\n");
	        fprintf(main_file,"void index_page (BuildHtml * page){\n");
	        fprintf(main_file,"    String result = getStringHtml(\"index\");\n");
        	fprintf(main_file,"    page->load_extern_html(result);\n");
            fprintf(main_file,"}\n");
	        fclose(main_file);
	        printf("FILE: '%s' => Created successufully in folder '%s'\n",name_main_file,nombre_del_proyecto);
	        usleep(1000 * 1000);
	        char file_index[MAX_LENGTH];
	        concatplus(file_index,"%s/%s/index.html",nombre_del_proyecto,foldels[1]);
	        FILE * index_file = fopen(file_index,"w");
	        if(index_file == EMPTY){
	            perror("ERROR: ");
	            printf("RUTE the file: %s\n",file_index);
	            return -1;
	        } else {
	            fprintf(index_file,"<!DOCTYPE html>\n");
                fprintf(index_file,"<html>\n");
                fprintf(index_file,"<head>\n");
                fprintf(index_file,"<meta charset=\"UTF-8\">\n");
                fprintf(index_file,"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n");
                fprintf(index_file,"<title>webCUtil project: %s</title>\n",nombre_del_proyecto);
                fprintf(index_file,"</head>\n");
                fprintf(index_file,"<body>\n");
                fprintf(index_file,"<p>Benvenuto!</p>");
                fprintf(index_file,"</body>\n");
                fprintf(index_file,"</html>\n");
	            printf("FILE: 'index.html' => Created successufully in folder '%s/html'\n",nombre_del_proyecto);
	            usleep(1000 * 1000);
	        }
	        char file_css[MAX_LENGTH];
	        concatplus(file_css,"%s/%s/main.css",nombre_del_proyecto,foldels[0]);
	        FILE * index_css = fopen(file_css,"w");
	        if(index_css == EMPTY){
	            perror("ERROR: ");
	            printf("RUTE the file: %s\n",file_css);
	            fclose(index_file);
	            return -1;
	        } else {
	            printf("FILE: 'main.css' => Created successufully in folder '%s/css'\n",nombre_del_proyecto);
	            usleep(1000 * 1000);
	        }
	        char file_js[MAX_LENGTH];
	        concatplus(file_js,"%s/%s/main.js",nombre_del_proyecto,foldels[2]);
	        FILE * index_js = fopen(file_js,"w");
	        if(index_js == EMPTY){
	            perror("ERROR: ");
	            printf("RUTE the file: %s\n",file_js);
	            fclose(index_file);
	            fclose(index_css);
	            return -1;
	        } else {
	            fprintf(index_js,"console.log('Ciao, mio mondo!');\n");
	            printf("FILE: 'main.js' => Created successufully in folder '%s/js'\n",nombre_del_proyecto);
	            usleep(1000 * 1000);
	        }
	        fclose(index_file);
	        fclose(index_js);
        	fclose(index_css);
	    }
	} else {
	    perror("ERROR ");
	}
	puts("Project created successufully");
	return 0;
}
