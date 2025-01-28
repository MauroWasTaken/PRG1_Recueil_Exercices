
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nom_complet;
    cout << "Entrez le nom et le numero de la rue :";
    getline(cin, nom_complet);
    int index_of_space = nom_complet.find(" ");
    if (index_of_space != string::npos) {
        string prenom = nom_complet.substr(0, index_of_space);
        string nom = nom_complet.substr(index_of_space + 1);
        cout << "Votre prenom est   : " << prenom << endl;
        cout << "Votre nom est      : " << nom << endl;
        cout << "Votre acronyme est : " << prenom[0] << nom[0] << nom[nom.length()-1] << endl;
    }
    return EXIT_SUCCESS;
}