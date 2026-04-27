#include <iostream>
#include <regex>

using namespace std;

	/*regex patron("^[\\w.-]+@[\\w.-]+\\.\\w+$");
	regex patron("^9\\d{8}$");
	regex patron("^(?=.*[A-Z])(?=.*\\d).{8,}$");*/
	
int main(){
	string texto = "Hola mundo C++ regex";
	regex patron("\\w+");
	
	auto palabras_inicio = sregex_iterator(texto.begin(), texto.end(), patron);
	auto palabras_fin = sregex_iterator();
	
	for (auto i = palabras_inicio; i != palabras_fin; i++){
		cout<<i->str() << endl;
	}	
	
	return 0;
}
