#include <iostream>
#include <regex>
using namespace std;
int main(){
	string texto = "Mi edad es 25";
	regex patron("\\d+");
	
	string nuevo = regex_replace(texto, patron, "X");
	
	cout<<nuevo;
	
	return 0;
}
