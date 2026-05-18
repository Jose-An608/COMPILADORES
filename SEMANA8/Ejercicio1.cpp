#include <iostream>
#include <string>
using namespace std;

int main(){
	string cadena;
	int estado=0;
	cout<<"Ingrese cadena binaria: ";
	cin >> cadena;
	for(char c:cadena){
		switch(estado){
			case 0:
				if(c=='0')
					estado=1;
				else if(c=='1')
					estado=0;
				else{
					cout<<"Simbolo invalido" << endl;
					return 0;
				}
				break;
			
			case 1:
				if(c=='0')
					estado=1;
				else if(c=='1')
					estado=2;
				else{
					cout<<"Simbolo invalido"<<endl;
					return 0;
				}
				break;
				
			case 2:
				if(c=='0')
					estado=1;
				else if(c=='1')
					estado=0;
				else{
					cout << "Simbolo invalido" << endl;
					return 0;
				}
				break;
		}
	}
	
	if(estado==2)
		cout <<"Cadena aceptada" << endl;
	else
		cout << "Cadena rechazada" << endl;
		
	return 0;
}

