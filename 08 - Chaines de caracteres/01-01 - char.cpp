#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char c;
    cout << "Entrez un caractere : ";
    cin >> c;

    cout << "Code ASCII de \'a\' :" << int(c) << endl;
    cout << "\'a\' est une lettre de l\'alphabet :" << boolalpha  << bool(isalpha(c)) << endl;
    cout << "\'a\' est une lettre minuscule :" << boolalpha  << bool(islower(c)) << endl;
    cout << "\'a\' est un chiffre :" << boolalpha  << bool(isdigit(c)) << endl;
    cout << "\'a\' est un caractere de ponctuation :" << boolalpha  << bool(ispunct(c)) << endl;

}