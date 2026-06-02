#include <iostream>
using namespace std;

string entrada;
int pos = 0;

void error(){
	cout << "Erro sintactico...";
}
void E(){
	
	if((entrada[pos] >= 'a' && entrada[pos]<='z') ||
		(entrada[pos]>= 'A' && entrada[pos]<='Z')){
			pos++;
	}else{
		error();
		return;
	}
	
	if(entrada[pos] == '+'){
		pos++;
	}else{
		error();
		return;
	}
	
	if((entrada[pos] >= 'a' && entrada[pos]<='z') ||
		(entrada[pos]>= 'A' && entrada[pos]<='Z')){
			pos++;
	}else{
		error();
		return;
	}
	
}
int main(){
	cout << "Ingrese la expresion: ";
	cin >> entrada;
	
	E();
	
	if(pos == entrada.length())
		cout << "Cadena aceptada" << endl;
	else
		cout << "Cadena rechazada" << endl;
		
	return 0;
}
