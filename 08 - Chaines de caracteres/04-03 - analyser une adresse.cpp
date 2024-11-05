
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string full_adresse;
    const string chiffres = "0123456789";
    cout << "Entrez le nom et le numero de la rue :";
    getline(cin, full_adresse);
    int street_nb_index;
    street_nb_index = full_adresse.find_first_of(chiffres);
    if (street_nb_index != string::npos) {
        cout << "Le nom de la rue est : " << full_adresse.substr(0, street_nb_index - 1) << endl;
        cout << "Le no de la rue est  : " << full_adresse.substr(street_nb_index) << endl;
    }
    return EXIT_SUCCESS;
}