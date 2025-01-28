#include <array>
#include <iostream>

using namespace std;

struct Date {
    uint8_t  jour;
    uint8_t  mois;
    uint16_t annee;
};

struct Personne {
    string prenom;
    string nom;
    Date   date;
};
ostream& operator<<(ostream& os, const Date& d) {
    static char seperator = '.';
    os << (int)d.jour << seperator << (int)d.mois << seperator << (int)d.annee;
    return os;
}
ostream& operator<<(ostream& os, const Personne& p) {
    os << "Prenom : " << p.prenom << endl;
    os << "Nom    : " << p.nom << endl;
    os << "Date   : " << p.date << endl;
    return os;
}
template<typename T, size_t taille>
ostream& operator<<(ostream& os, const array<T,taille>& v) {
    for (T t: v){
        cout << t << endl;
    }
    return os;
}

int main() {
    array carnet {Personne{"Jean"s,   "Veuxplus"s, Date{ 7,  4, 1975}},
                Personne{"Alain"s,  "Verse"s,    Date{21, 12, 2018}},
                Personne{"Justin"s, "Ptipeu"s,   Date{ 1,  8, 2023}},
                Personne{"Rémi"s,   "Fasol"s,    Date{17,  5, 1957}}};

    cout << carnet << endl;
}