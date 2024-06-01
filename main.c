#include "webcutil.h"

void index_page (BuildHtml * );

int main (){
	Server server;
	server.port = 8080;
	server.buffer_file = 6046;
	server.url = "127.0.0.1";
	openServer(&server);
	while(true){
		BuildHtml page;
		buildHtml(&page);
		index_page(&page);
		page.send(&server);
		page.resetAllHTML();
		printf("%s",server.load_buffer());
	}
	return 0;
}

void index_page (BuildHtml * page){
	page->html_o(EMPTY);
	page->title("A tittle");
	page->head_o(EMPTY);
	page->head_c();
	page->body_o(EMPTY);
	page->h1(EMPTY,"Is Empty");
	page->body_c();
	page->html_c();
}
