#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Entrez un nombre entier >= 0 : ";
    string nombre;
    cin >> nombre;
    cout << "Nombre saisi       : " << nombre << endl;
    cout << "Nombre de chiffres : " << nombre.length() << endl;
    cout << "Premier chiffre    : " << nombre[0] << endl;
    cout << "Dernier chiffre    : " << nombre[nombre.length()-1] << endl;
}