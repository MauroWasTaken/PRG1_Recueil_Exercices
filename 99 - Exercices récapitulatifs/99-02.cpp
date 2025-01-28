//
// Created by maurx on 27/01/2025.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool verifier (const string_view a, const string_view b){
    bool contains = true;
    for_each(a.begin(), a.end(), [&contains,&b](char c){ if(find(b.begin(), b.end(), tolower(c)) == b.end()) if (find(b.begin(), b.end(), toupper(c)) == b.end()) contains = false; });
    return contains;
}

void tester(string_view a, string_view b) {
    cout << '\"' << a << "\" "
         << (verifier(a, b) ? "" : "in") << "compatible avec "
         << '\"' << b << '\"' << endl;
}

int main() {
    tester("abcdef","FEDBAC");
    tester("abcdef","xyz123");
    tester("abcA","cAba");
}