#include <iostream>
using namespace std;

// insérez ici votre code

pair <char,char> premiere_et_derniere_lettres (string s){
    return {s.at(0), s.at(s.length() - 1)};
}

int main() {
    string s = "Hello";
    auto [ prem, der ] = premiere_et_derniere_lettres(s);
    cout << prem << " -> " << der << endl;
}