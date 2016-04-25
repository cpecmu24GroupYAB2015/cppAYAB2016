#include "fileio.h"

Fio::Fio(){
    cout << "create";
}
void Fio::create(string n){
	string fn;
	fn = "name_"+n+".txt";
	ofstream f(fn.c_str(),ios::out);
	f.close();
}

