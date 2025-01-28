#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


bool est_palindrome(const string& s){
    string reverse_s = "";
    for (int i = s.length() - 1; i >= 0; i--){
        reverse_s += s[i];
    }
    return s == reverse_s;
}

int main(){
    do{
        string input;
        cout << "Entrez un mot (ou 'quitter' pour sortir) : ";
        cin >> input;
        if(input == "quitter") break;
        cout << "Le mot \'" << input << "\'" << (est_palindrome(input) ? " est un palindrome." : " n'est pas un palindrome.") << endl;

    }while(true);
    return EXIT_SUCCESS;
}