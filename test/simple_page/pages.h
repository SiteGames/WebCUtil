#ifndef _PAGES_H
#define _PAGES_H

void main_page (html * index){//Funcion pata crear la pagina html,css y js(una calculadora simple)
	index->html_o("lang=\"es\"");
	index->head_o(NULL);
	index->meta("charset=\"UTF-8\"");
	index->meta("name=\"viewport\" content=\"width=device-width, initial-scale=1\"");
	index->title("Calculadora");
	index->style("* {margin: 0px;padding: 0px;box-sizing: border-box;background-color: #ecf0f3;font-family: sans-serif;outline: none;}.container {height: 100vh;display: flex;justify-content: center;align-items: center;}.calculator {background-color: #ecf0f3;padding: 15px;border-radius: 30px;box-shadow: inset 5px 5px 12px #ffffff, 5px 5px 12px rgba(0, 0, 0, .16);display: grid;grid-template-columns: repeat(4, 68px);}input {grid-column: span 4;height: 70px;widows: 260px;background-color: #ecf0f3;box-shadow: inset -5px -5px 12px #ffffff, inset 5px 5px 12px rgba(0, 0, 0, .16);border: none;border-radius: 30px;color: rgb(70, 70, 70);font-size: 50px;text-align: end;margin-top: 40px;margin-bottom: 30px;padding: 20px;}button {height: 48px;width: 48px;background-color: #ecf0f3;box-shadow: -5px -5px 12px #ffffff, 5px 5px 12px rgba(0, 0, 0, .16);border: none;border-radius: 50%; margin: 8px;font-size: 16px;font-weight: bold;}.equal {width: 115px;border-radius: 40px;background-color: #ecf0f3;box-shadow: -5px -5px 12px #ffffff, 5px 5px 12px rgba(0, 0, 0, .16);}");
	index->head_c();
	index->body_o(NULL);
	index->div_o("class=\"container\"","");
	index->div_o("class=\"calculator\"","");
	index->input("type=\"text\" placeholder=\"0\" id=\"output-screen\"");
	index->button("onclick=\"clr()\"","CL");
	index->button("onclick=\"display('%')\"","%");
	index->button("onclick=\"display('/')\"","/");
	index->button("onclick=\"display('7')\"","7");
	index->button("onclick=\"display('8')\"","8");
	index->button("onclick=\"display('9')\"","9");
	index->button("onclick=\"display('*')\"","*");
	index->button("onclick=\"display('4')\"","4");
	index->button("onclick=\"display('5')\"","5");
	index->button("onclick=\"display('6')\"","6");
	index->button("onclick=\"display('-')\"","-");
	index->button("onclick=\"display('1')\"","1");
	index->button("onclick=\"display('2')\"","2");
	index->button("onclick=\"display('3')\"","3");
	index->button("onclick=\"display('+')\"","+");
	index->button("onclick=\"display('.')\"",".");
	index->button("onclick=\"display('0')\"","0");
	index->button("onclick=\"calculate()\" class=\"equal\"","=");
	index->div_c();
	index->div_c();
	index->script("","let outputscreen = document.getElementById('output-screen');function display(num) {outputscreen.value += num}function calculate() {try {outputscreen.value = eval(outputscreen.value)}catch (err) {alert('Invalid');}}function clr() {outputscreen.value = '';}function del() {outputscreen.value = outputscreen.value.slice(0, -1)}");
	index->body_c();
	index->html_c();
}

#endif
