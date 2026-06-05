#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    string dato;
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(string valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->izq  = nullptr;
    nuevo->der  = nullptr;
    return nuevo;
}

string entrada;
int pos = 0;

Nodo* E();
Nodo* Ep(Nodo* izquierdo);
Nodo* T();
Nodo* Tp(Nodo* izquierdo);
Nodo* F();

void error() {
    cout << "Error sintactico" << endl;
    exit(1);
}

Nodo* F() {
    Nodo* nodo = nullptr;
    if (pos < (int)entrada.size() && isalpha(entrada[pos])) {
        nodo = crearNodo(string(1, entrada[pos]));
        pos++;
    }
    else if (pos < (int)entrada.size() && entrada[pos] == '(') {
        pos++;
        nodo = E();
        if (pos < (int)entrada.size() && entrada[pos] == ')')
            pos++;
        else {
            cout << "Error: se esperaba ')'" << endl;
            exit(1);
        }
    }
    else {
        error();
    }
    return nodo;
}

Nodo* Tp(Nodo* izquierdo) {
    if (pos < (int)entrada.size() && entrada[pos] == '*') {
        pos++;
        Nodo* raiz = crearNodo("*");
        raiz->izq  = izquierdo;
        raiz->der  = F();
        return Tp(raiz);
    }
    return izquierdo;
}

Nodo* T() {
    return Tp(F());
}

Nodo* Ep(Nodo* izquierdo) {
    if (pos < (int)entrada.size() && entrada[pos] == '+') {
        pos++;
        Nodo* raiz = crearNodo("+");
        raiz->izq  = izquierdo;
        raiz->der  = T();
        return Ep(raiz);
    }
    return izquierdo;
}

Nodo* E() {
    return Ep(T());
}

void inorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->izq);
    cout << nodo->dato << " ";
    inorden(nodo->der);
}

void imprimirArbol(Nodo* nodo, string prefijo = "", bool esUltimo = true) {
    if (nodo == nullptr) return;

    cout << prefijo;
    cout << (esUltimo ? "+-- " : "+-- ");
    cout << nodo->dato << endl;

    string nuevoPrefijo = prefijo + (esUltimo ? "    " : "¦   ");
    if (nodo->izq != nullptr || nodo->der != nullptr) {
        if (nodo->izq)
            imprimirArbol(nodo->izq, nuevoPrefijo, nodo->der == nullptr);
        if (nodo->der)
            imprimirArbol(nodo->der, nuevoPrefijo, true);
    }
}

int main() {
    cout << "Ingrese expresion: ";
    cin >> entrada;

    pos = 0;
    Nodo* arbol = E();

    if (pos == (int)entrada.size()) {
        cout << "Cadena aceptada" << endl;

        cout << "\nRecorrido Inorden: ";
        inorden(arbol);
        cout << endl;

        cout << "\nArbol Sintactico:" << endl;
        cout << arbol->dato << endl;
        if (arbol->izq)
            imprimirArbol(arbol->izq, "", arbol->der == nullptr);
        if (arbol->der)
            imprimirArbol(arbol->der, "", true);
    } else {
        cout << "Cadena rechazada" << endl;
    }

    return 0;
}
