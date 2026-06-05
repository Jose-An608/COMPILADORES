#include <iostream>
#include <string>
using namespace std;

string entrada;
int pos = 0;

void E();
void Ep();
void T();
void Tp();
void F();

void error() {
    cout << "Error sintactico" << endl;
    exit(1);
}

void E() {
    T();
    Ep();
}

void Ep() {
    if (pos < (int)entrada.size() && entrada[pos] == '+') {
        pos++;
        T();
        Ep();
    }
}

void T() {
    F();
    Tp();
}

void Tp() {
    if (pos < (int)entrada.size() && entrada[pos] == '*') {
        pos++;
        F();
        Tp();
    }
}

void F() {
    if (pos < (int)entrada.size() && isalpha(entrada[pos])) {
        cout << "  >> id reconocido: '" << entrada[pos] << "'" << endl;
        pos++;
    }
    else if (pos < (int)entrada.size() && entrada[pos] == '(') {
        cout << "  >> '(' reconocido" << endl;
        pos++;
        E();
        if (pos < (int)entrada.size() && entrada[pos] == ')') {
            cout << "  >> ')' reconocido" << endl;
            pos++;
        } else {
            cout << "Error: se esperaba ')'" << endl;
            exit(1);
        }
    }
    else {
        error();
    }
}

int main() {
    cout << "Ingrese expresion: ";
    cin >> entrada;

    pos = 0;
    E();

    if (pos == (int)entrada.size())
        cout << "Resultado: Cadena ACEPTADA" << endl;
    else
        cout << "Resultado: Cadena RECHAZADA" << endl;

    return 0;
}
