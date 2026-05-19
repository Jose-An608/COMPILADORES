/*Implementar un programa que valide correos electrónicos simples.*/
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string correo;
    int estado = 0;
    cout << "Ingrese correo: ";
    cin >> correo;

    for(char c : correo){
        switch(estado){
            case 0: 
                if(isalnum(c) || c == '_') estado = 0;
                else if(c == '@') estado = 1;
                else { estado = -1; }
                break;
            case 1: 
                if(isalpha(c)) estado = 2;
                else estado = -1;
                break;
            case 2: 
                if(isalnum(c)) estado = 2;
                else if(c == '.') estado = 3;
                else estado = -1;
                break;
            case 3: 
                if(isalpha(c)) estado = 4;
                else estado = -1;
                break;
            case 4:
                if(isalpha(c)) estado = 4;
                else estado = -1;
                break;
            default:
                estado = -1;
        }
        if(estado == -1) break;
    }

    if(estado == 4)
        cout << "Correo valido" << endl;
    else
        cout << "Correo invalido" << endl;

    return 0;
}
