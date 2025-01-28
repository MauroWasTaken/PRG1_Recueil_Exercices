//
// Created by maurx on 27/01/2025.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

size_t transformer(string& s , const string& s1, const string& s2 ){
    size_t compteur = 0;
    for(char& c : s){
        size_t i = s1.find(static_cast<char>(tolower(c)));
        if(i != -1ull) {
            compteur ++;
            if (islower(c)){
                c = static_cast<char>(tolower(s2[i]));
            }else{
                c = static_cast<char>(toupper(s2[i]));
            }
        }
    }
    return compteur;
}

int main() {
    string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";
    cout << transformer(s,"abcdefgh.!,:","fghabcde!,:.") << endl;
    cout << s << endl;
    cout << transformer(s,"fghabcde!,:.","abcdefgh.!,:") << endl;
    cout << s << endl;
}