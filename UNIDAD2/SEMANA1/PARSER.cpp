#include <iostream>
#include <string>
using namespace std;

string entrada;
int pos = 0;

void E();
void Ep();
void T();
void Tp();
void F();

void error(){
	cout << "Error sintactico " << endl;
	exit(1);
}

void E(){
	T();
	Ep();
}

void Ep(){
	if(entrada[pos] == '+'){
		pos++;
		T();
		Ep();
	}
}

void T(){
	F();
	Tp();
}

void Tp(){
	if(entrada[pos] == '*'){
		pos++;
		F();
		Tp();
	}
}

void F(){
	if(isalpha(entrada[pos])){
		pos++;
	}
	else if(entrada[pos]=='('){
		pos++;
		E();
		
		if(entrada[pos] == ')')
			pos++;
		else
			error();
	}
	else{
		error();
	}
}


int main(){
	cout << "Ingrese expresion: ";
	cin >> entrada;
	
	E();
	
	if(pos==entrada.length())
		cout << "Cadena aceptada" << endl;
	else
		cout << "Cadena rechazada" << endl;
		
	return 0;
}
