#include <iostream>
#include <string>
using namespace std;

int main(){
    string cadena;
    int estado = 0;
    cout << "Ingrese cadena binaria: ";
    cin >> cadena;
    
    for(char c : cadena){
        if(c == '0'){
            if(estado == 0)
                estado = 1;
            else
                estado = 0;
        }
        else if(c == '1'){
            continue;
        }
        else{             
            cout << "Error" << endl;
            return 0;     
        }
    }
    
    if(estado == 0)
        cout << "Cadena aceptada" << endl;
    else
        cout << "Cadena rechazada" << endl;
        
    return 0;
}
