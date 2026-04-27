#include <iostream>
#include <regex>
using namespace std;

int main(){
	string texto = "Edad: 25 años";
	regex patron("\\d+");
	smatch resultado;
	
	if(regex_search(texto,resultado,patron)){
		cout<<"Numero encontrado: " << resultado[0];
	}
	return 0;
}
