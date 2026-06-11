#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<char, map<char, string>> tabla;

void initTabla() {
    tabla['E']['i'] = "eT";   // E -> T E'
    tabla['E']['('] = "eT";

    tabla['e']['+'] = "eT+";  // E' -> + T E'
    tabla['e'][')'] = "";     // E' -> epsilon
    tabla['e']['$'] = "";

    tabla['T']['i'] = "tF";   // T -> F T'
    tabla['T']['('] = "tF";

    tabla['t']['*'] = "tF*";  // T' -> * F T'
    tabla['t']['+'] = "";     // T' -> epsilon
    tabla['t'][')'] = "";
    tabla['t']['$'] = "";

    tabla['F']['i'] = "i";    // F -> id
    tabla['F']['('] = ")E(";  // F -> ( E )
}

bool esNT(char c) {
    return c=='E'||c=='e'||c=='T'||c=='t'||c=='F';
}

string tokenizar(const string& s) {
    string r;
    for (char c : s) {
        if (c==' ') continue;
        r += isalpha(c) ? 'i' : c;
    }
    return r + '$';
}

string sym(char c) {
    if (c=='e') return "E'";
    if (c=='t') return "T'";
    if (c=='i') return "id";
    return string(1,c);
}

string pilaStr(stack<char> p) {
    vector<char> v;
    while (!p.empty()) { v.push_back(p.top()); p.pop(); }
    string s;
    for (int i=v.size()-1;i>=0;i--) s += sym(v[i]);
    return s;
}

string prodStr(char nt, const string& inv) {
    string s = sym(nt) + "->"; 
    if (inv.empty()) return s+"eps";
    for (int i=inv.size()-1;i>=0;i--) s+=sym(inv[i]);
    return s;
}

bool analizar(const string& orig) {
    string ent = tokenizar(orig);
    int pos = 0;
    stack<char> pila;
    pila.push('$');
    pila.push('E');

    cout << "\n  Traza: \"" << orig << "\"\n";
    printf("  %-22s %-14s %s\n","Pila","Entrada","Accion");
    cout << "  " << string(58,'-') << "\n";

    while (!pila.empty()) {
        char top = pila.top();
        char tok = ent[pos];
        printf("  %-22s %-14s ", pilaStr(pila).c_str(), ent.substr(pos).c_str());

        if (top=='$' && tok=='$') { cout<<"ACCEPT\n"; return true; }

        if (!esNT(top)) {
            if (top==tok) { cout<<"Match "<<sym(tok)<<"\n"; pila.pop(); pos++; }
            else { cout<<"ERROR: esperaba "<<sym(top)<<" got "<<sym(tok)<<"\n"; return false; }
        } else {
            if (tabla.count(top) && tabla[top].count(tok)) {
                string prod = tabla[top][tok];
                cout << prodStr(top,prod) << "\n";
                pila.pop();
                for (char c : prod) pila.push(c);
            } else {
                cout<<"ERROR: M["<<sym(top)<<","<<sym(tok)<<"] vacio\n";
                return false;
            }
        }
    }
    return false;
}

int main() {
    initTabla();
    cout << "=== Analizador LL(1) - Practica 2 ===\n";
    cout << "Gramatica: E->TE'|E'->+TE'|eps|T->FT'|T'->*FT'|eps|F->(E)|id\n";

    vector<string> pruebas = {"a+b","a+b*c","(a+b)*c"};
    for (auto& p : pruebas) {
        bool ok = analizar(p);
        cout << "  >> " << p << " : " << (ok?"ACEPTADA":"RECHAZADA") << "\n";
    }

    cout << "\nIngresa expresion (o salir): ";
    string s;
    while (cin>>s && s!="salir") {
        bool ok = analizar(s);
        cout << "  >> " << (ok?"ACEPTADA":"RECHAZADA") << "\n";
        cout << "Ingresa expresion (o salir): ";
    }
    return 0;
}
