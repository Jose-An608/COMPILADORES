#include <iostream>
#include <regex>
using namespace std;
int main(){
	string linea;
	cout << "Ingrese una linea de codigo: ";
	getline(cin, linea);
	
	regex patronGeneral("([a-zA-Z_]\\w*|\\d+|[+\\-*/=])");
	
	regex patronId("^[a-zA-Z_]\\w*$");
    regex patronNum("^\\d+$");
    regex patronOp("^[+\\-*/=]$");
    
    
    auto inicio = sregex_iterator(linea.begin(), linea.end(), patronGeneral);
    auto fin = sregex_iterator();
    
    cout << "Tokens encontrados: ";
    
    for(auto i = inicio; i != fin; i++){
    	string token = i->str();
    	
    	if(regex_match(token, patronId)){
    		cout << token << " -> IDENTIFICADOR" << endl;
		}else if (regex_match(token, patronNum)){
			cout << token << "-> NUMERO" << endl;
		}else if (regex_match(token, patronOp)){
			cout << token << " -> OPERADOR" << endl;
			
		}
	}
	return 0;
}
