#include <iostream>
#include <regex>
using namespace std;

int main(){
	string texto = "12345";
	regex patron("\\d+");
	
	if(regex_match(texto, patron)){
		cout << "Es un numero valido";
	}else{
		cout<<"No es valido";
	}
	
	return 0;
	
}
