#include <iostream>
#include <regex>
using namespace std;
int main(){
	string texto = "var1 = 100 + total2";
	regex patron("(\\d+|\\w+)");
	auto it = sregex_iterator(texto.begin(), texto.end(), patron);
	auto end = sregex_iterator();
	
	for(; it != end; ++it){
		cout << "Token: " << it->str() << endl;
	}
	
	return 0;
}
