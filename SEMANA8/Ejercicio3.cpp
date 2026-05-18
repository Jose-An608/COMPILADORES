#include <cctype>
#include <string>
#include <iostream>

using namespace std;

int main(){
	string palabra;
	cout << "Ingrese identificador: ";
	cin >> palabra;
	
	if(!isalpha(palabra[0])){
		cout << "Identificador invalido" << endl;
		return 0;
	}
	
	for(int i = 1; i<palabra.length();i++){
		if(!isalnum(palabra[i])){
			cout << "Identificaor invalido" << endl;
			return 0;
		}
	}
	cout << "Identificador valido" << endl;
	return 0;
}
