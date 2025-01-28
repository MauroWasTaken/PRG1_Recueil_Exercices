#include <string_view>
#include <iostream>

using namespace std;

int traduire_romain(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romain_en_entier(string_view s){
    int output = 0;
    for(int i = 0; i < s.size(); ++i){
        if(traduire_romain(s[i]) < traduire_romain(s[i+1])){
            output += traduire_romain(s[i+1]) - traduire_romain(s[i]);
            ++i;
        }else{
            output += traduire_romain(s[i]);
        }
    }
    return output;
}

int main() {
    string_view tests[] = {"I", "II", "III", "IV", "V",
                            "VI", "VII", "VIII", "IX", "X",
                            "MMMMDCCCLXXXVIII"};
    for (string_view s : tests) {
        cout << "\"" << s << "\" = " << romain_en_entier(s) << '\n';
    }

    return 0;
}