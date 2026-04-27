#include <iostream>
#include <regex>
using namespace std;

int main(){
	
	//1. validar correo
	string correo = "esis@gmail.com";
	regex patronCorreo("^[\\w.-]+@[\\w.-]+\\.\\w+$");
	
	if(regex_match(correo, patronCorreo)){
		cout << "correo validado" << endl;
	}else{
		cout << "Correo invalido" << endl;
	}
	
	//2. validad numero telefonico
	string telefono = "989281212";
	regex patronTelefono("^9\\d{8}$");
	
	if(regex_match(telefono, patronTelefono)){
		cout << "Telefono validado" << endl;
	}else{
		cout << "Telefono invalido" << endl;
	}
	
	//3. validar contraseña segura
	string password = "Abc12345";
	regex patronPassword("^(?=.*[A-Z])(?=.*\\d).{8,}$");
	
	if(regex_match(password, patronPassword)){
		cout << "Password validado" << endl;
	}else{
		cout << "Password invalido" << endl;
	}
	return 0;
}
