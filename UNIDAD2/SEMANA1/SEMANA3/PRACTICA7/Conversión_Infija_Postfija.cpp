#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Función para determinar la precedencia
int precedencia(char op)
{
    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    if(op == '^')
        return 3;

    return 0;
}

// Conversión de infija a postfija
string infijaAPostfija(string expresion)
{
    stack<char> pila;
    string salida = "";

    for(char c : expresion)
    {
        // Si es operando
        if(isalnum(c))
        {
            salida += c;
        }
        // Paréntesis izquierdo
        else if(c == '(')
        {
            pila.push(c);
        }
        // Paréntesis derecho
        else if(c == ')')
        {
            while(!pila.empty() && pila.top() != '(')
            {
                salida += pila.top();
                pila.pop();
            }

            if(!pila.empty())
                pila.pop(); // elimina '('
        }
        // Operadores
        else
        {
            while(!pila.empty() &&
                  precedencia(pila.top()) >= precedencia(c))
            {
                salida += pila.top();
                pila.pop();
            }

            pila.push(c);
        }
    }

    // Vaciar la pila
    while(!pila.empty())
    {
        salida += pila.top();
        pila.pop();
    }

    return salida;
}

int main()
{
    string expresion;

    cout << "Ingrese expresion infija: ";
    cin >> expresion;

    cout << "Expresion postfija: "
         << infijaAPostfija(expresion)
         << endl;

    return 0;
}
