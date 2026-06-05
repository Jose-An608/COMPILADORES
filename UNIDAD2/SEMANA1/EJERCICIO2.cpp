#include <iostream>
#include <string>
using namespace std;

string entrada;
int pos = 0;

void error(){
    cout << "Error sintactico..." << endl;
    exit(1);
}

void E(){
    if((entrada[pos] >= 'a' && entrada[pos] <= 'z') ||
       (entrada[pos] >= 'A' && entrada[pos] <= 'Z')){
        pos++;
    } else {
        error();
    }

    if(entrada[pos] == '+'){
        pos++;
    } else {
        error();
    }

    if((entrada[pos] >= 'a' && entrada[pos] <= 'z') ||
       (entrada[pos] >= 'A' && entrada[pos] <= 'Z')){
        pos++;
    } else {
        error();
    }

    if(entrada[pos] == '*'){
        pos++;
    } else {
        error();
    }

    if((entrada[pos] >= 'a' && entrada[pos] <= 'z') ||
       (entrada[pos] >= 'A' && entrada[pos] <= 'Z')){
        pos++;
    } else {
        error();
    }
}

int main(){
    cout << "Ingrese la expresion: ";
    cin >> entrada;

    E();

    if(pos == entrada.length())
        cout << "Cadena aceptada" << endl;
    else
        cout << "Cadena rechazada" << endl;

    return 0;
}
