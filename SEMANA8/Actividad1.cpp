/*Construir un autómata que acepte cadenas binarias terminadas en 10.*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string cadena;
    int estado = 0;
    cout << "Ingrese cadena binaria: ";
    cin >> cadena;

    for(char c : cadena){
        if(estado == 0){
            if(c == '0') estado = 0;
            else if(c == '1') estado = 1;
            else { cout << "Simbolo invalido" << endl; return 0; }
        }
        else if(estado == 1){
            if(c == '0') estado = 2;
            else if(c == '1') estado = 1;
            else { cout << "Simbolo invalido" << endl; return 0; }
        }
        else if(estado == 2){
            if(c == '0') estado = 0;
            else if(c == '1') estado = 1;
            else { cout << "Simbolo invalido" << endl; return 0; }
        }
    }

    if(estado == 2)
        cout << "Cadena ACEPTADA" << endl;
    else
        cout << "Cadena RECHAZADA" << endl;

    return 0;
}
