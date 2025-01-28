#include <iostream>

using namespace std;

struct HeureMinute {
    int8_t heure;
    int8_t minute;
};

ostream& operator<< (ostream& os, const HeureMinute& hm) {
    os << (long)hm.heure << ":" << (long)hm.minute;
    return os;
}

istream& operator>> (istream& is, HeureMinute& h) {
    char c;
    int  valeur;
    is >> valeur;
    h.heure = valeur;

    is >> c;
    if (c != ':') {
        is.setstate(ios::failbit);
    }

    is >> valeur;
    h.minute = valeur;

    if (h.minute >= 60) {
        cout << h.minute << endl;
        is.setstate(ios::failbit);
    }

    return is;
}

bool operator< (const HeureMinute& lhs, const HeureMinute& rhs) {
    return lhs.heure != rhs.heure ? lhs.heure < rhs.heure : lhs.minute < rhs.minute;
}
bool operator> (const HeureMinute& lhs, const HeureMinute& rhs) {
    return rhs < lhs;
}
bool operator== (const HeureMinute& lhs, const HeureMinute& rhs) {
    return rhs.heure == lhs.heure && lhs.minute == rhs.minute;
}
bool operator!= (const HeureMinute& lhs, const HeureMinute& rhs) {
    return !(lhs == rhs);
}
bool operator<= (const HeureMinute& lhs, const HeureMinute& rhs) {
    return lhs < rhs || lhs == rhs;
}
bool operator>= (const HeureMinute& lhs, const HeureMinute& rhs) {
    return rhs < lhs || lhs == rhs;
}
HeureMinute operator+ (const HeureMinute& lhs, const HeureMinute& rhs) {
    return HeureMinute((lhs.heure + rhs.heure + (lhs.minute + rhs.minute) / 60) % 24, (lhs.minute + rhs.minute)% 60);
}
HeureMinute operator+ (const HeureMinute& lhs, const int minutes) {
    return HeureMinute((lhs.heure + (lhs.minute + minutes) / 60) % 24, (lhs.minute + minutes)% 60);
}
HeureMinute operator+ (const int minutes, const HeureMinute& lhs) {
    return lhs + minutes;
}
HeureMinute& operator+= (HeureMinute& lhs, const int minutes) {
    lhs = lhs + minutes;
    return lhs;
}
HeureMinute& operator++ (HeureMinute& lhs) {
    lhs = lhs + 1;
    return lhs;
}
HeureMinute operator++ (HeureMinute& lhs,const int minutes) {
    const HeureMinute tmp = lhs;
    lhs = lhs + 1;
    return tmp;
}

HeureMinute saisie(const string& msg) {
    HeureMinute hm;
    bool erreur;
    do {
        cout << msg;
        cin >> hm;
        erreur = cin.fail();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (erreur);
    return hm;
}
int main(){
    HeureMinute hm1 = {12, 34};
    HeureMinute hm2 = {21, 43};

    cout << boolalpha;
    cout << hm1 << " <  " << hm2 << "  : " << (hm1 <  hm2) << endl;
    cout << hm1 << " >  " << hm2 << "  : " << (hm1 >  hm2) << endl;
    cout << hm1 << " <= " << hm2 << "  : " << (hm1 <= hm2) << endl;
    cout << hm1 << " >= " << hm2 << "  : " << (hm1 >= hm2) << endl;
    cout << hm1 << " == " << hm2 << "  : " << (hm1 == hm2) << endl;
    cout << hm1 << " != " << hm2 << "  : " << (hm1 != hm2) << endl;

    cout << hm1 << " +  " << hm2 << "  : " << (hm1 +  hm2) << endl;
    cout << hm1 << " +  " << 44  << "     : " << (hm1 +  44 ) << endl;
    cout << 44  << "    +  " << hm1 << "  : " << (44  +  hm1) << endl;
    cout << hm1 << " += "  << 2 << "      : " << (hm1+=2 )    << endl;

    cout << "++" << hm1  << "\t\t: " << ++hm1 << endl;
    cout << hm1  << "++" << "\t\t: " << hm1++ << endl;
    cout << hm1 << endl;

    cout << endl;
    HeureMinute hm3 = saisie("heure [hh:mm]: ");
    cout << "votre saisie : " << hm3 << endl;
}