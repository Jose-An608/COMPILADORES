#include <iostream>

using namespace std;
int main(){
	string cadena;
	while(1){
		cout<<"\n\nIngrese una cadena de 0s y 1s: ";
		getline(cin,cadena);
		int inicio=1, aceptado=1;
		int estado=inicio;
		bool fin=false;
		int contador=0;
		
		while(fin==false){
			if(contador>cadena.length()-1){
				fin=true;
				break;
		}
		if(estado==1){
			if(cadena[contador]=='1') estado=1;
			if(cadena[contador]=='0') estado=2;
			contador++;
			continue;
		}
		if(estado==2){
			if(cadena[contador]=='1')estado=2;
			if(cadena[contador]=='0')estado=1;
			contador++;
		continue;
		}
	}
	
	if(estado==aceptado){cout<<"La cadena" << cadena<<"es aceptada" << endl;}
	else{cout << "La cadena" << cadena << "es rechazada" << endl;}
}
return 0;
}
