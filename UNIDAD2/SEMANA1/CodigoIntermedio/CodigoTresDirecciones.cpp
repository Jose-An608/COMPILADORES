#include <iostream>
#include <string>
using namespace std;
int temporal = 1;
string nuevoTemporal()
{
 return "t" + to_string(temporal++);
}
int main()
{
 string a,b,c,d;
 cout<<"Ingrese variable destino: ";
 cin>>a;
 cout<<"Ingrese primer operando: ";
 cin>>b;
 cout<<"Ingrese segundo operando: ";
 cin>>c;
 cout<<"Ingrese tercer operando: ";
 cin>>d;
 string t1=nuevoTemporal();
 string t2=nuevoTemporal();
 cout<<"\nCodigo Intermedio\n\n";
 cout<<t1<<" = "<<c<<" * "<<d<<endl;
 cout<<t2<<" = "<<b<<" + "<<t1<<endl;
 cout<<a<<" = "<<t2<<endl;
 return 0;
}
