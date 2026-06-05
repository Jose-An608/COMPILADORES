#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    string dato;
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(string valor) {
    Nodo* n = new Nodo();
    n->dato = valor;
    n->izq  = nullptr;
    n->der  = nullptr;
    return n;
}

string entrada;
int pos = 0;

Nodo* Asignacion();
Nodo* E();
Nodo* Ep(Nodo* izq);
Nodo* T();
Nodo* Tp(Nodo* izq);
Nodo* F();

void error(string msg = "") {
    cout << "Error sintactico";
    if (!msg.empty()) cout << ": " << msg;
    cout << endl;
    exit(1);
}

void skipEspacios() {
    while (pos < (int)entrada.size() && entrada[pos] == ' ')
        pos++;
}


Nodo* F() {
    skipEspacios();
    Nodo* nodo = nullptr;

    if (pos < (int)entrada.size() && isalpha(entrada[pos])) {
       
        string id = "";
        while (pos < (int)entrada.size() && isalpha(entrada[pos]))
            id += entrada[pos++];
        nodo = crearNodo(id);
    }
    else if (pos < (int)entrada.size() && entrada[pos] == '(') {
        pos++; 
        nodo = E();
        skipEspacios();
        if (pos < (int)entrada.size() && entrada[pos] == ')')
            pos++; 
        else
            error("se esperaba ')'");
    }
    else {
        error("se esperaba identificador o '('");
    }
    return nodo;
}


Nodo* Tp(Nodo* izq) {
    skipEspacios();
    if (pos < (int)entrada.size() &&
        (entrada[pos] == '*' || entrada[pos] == '/')) {
        char op = entrada[pos++];
        Nodo* raiz = crearNodo(string(1, op));
        raiz->izq  = izq;
        raiz->der  = F();
        return Tp(raiz);
    }
    return izq; 
}

Nodo* T() {
    return Tp(F());
}

Nodo* Ep(Nodo* izq) {
    skipEspacios();
    if (pos < (int)entrada.size() &&
        (entrada[pos] == '+' || entrada[pos] == '-')) {
        char op = entrada[pos++];
        Nodo* raiz = crearNodo(string(1, op));
        raiz->izq  = izq;
        raiz->der  = T();
        return Ep(raiz);
    }
    return izq; // epsilon
}

Nodo* E() {
    return Ep(T());
}

Nodo* Asignacion() {
    skipEspacios();

    if (!(pos < (int)entrada.size() && isalpha(entrada[pos])))
        error("se esperaba identificador al inicio");

    string id = "";
    while (pos < (int)entrada.size() && isalpha(entrada[pos]))
        id += entrada[pos++];

    skipEspacios();

    if (pos < (int)entrada.size() && entrada[pos] == '=')
        pos++;
    else
        error("se esperaba '='");

    Nodo* expr = E();

    skipEspacios();

    if (pos < (int)entrada.size() && entrada[pos] == ';')
        pos++;
    else
        error("se esperaba ';'");

    Nodo* raiz = crearNodo("=");
    raiz->izq  = crearNodo(id);
    raiz->der  = expr;
    return raiz;
}

void imprimirAST(Nodo* nodo, string prefijo = "", bool esUltimo = true) {
    if (nodo == nullptr) return;
    cout << prefijo;
    cout << (esUltimo ? "+-- " : "+-- ");
    cout << nodo->dato << endl;
    string nuevoPrefijo = prefijo + (esUltimo ? "    " : "¦   ");
    if (nodo->izq)
        imprimirAST(nodo->izq, nuevoPrefijo, nodo->der == nullptr);
    if (nodo->der)
        imprimirAST(nodo->der, nuevoPrefijo, true);
}

void inorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->izq);
    cout << nodo->dato << " ";
    inorden(nodo->der);
}

int main() {
    cout << "Ingrese sentencia (ej: x = a + b * c;): ";
    getline(cin, entrada);

    pos = 0;
    Nodo* ast = Asignacion();

    skipEspacios();
    if (pos == (int)entrada.size()) {
        cout << "Sentencia valida" << endl;

        cout << "\nRecorrido Inorden: ";
        inorden(ast);
        cout << endl;

        cout << "\nArbol de Sintaxis Abstracta (AST):" << endl;
        cout << ast->dato << endl;
        if (ast->izq)
            imprimirAST(ast->izq, "", ast->der == nullptr);
        if (ast->der)
            imprimirAST(ast->der, "", true);
    } else {
        cout << "Sentencia rechazada" << endl;
    }

    return 0;
}
