#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int trouver_instances(const string& string1, const string& string2){
    size_t index = -1;
    int counter = 0;
    do {
        index = string1.find(string2, index + 1);
        if (index == -1) break;
        counter++;
    }while(true);
    return counter;
}

int main(){
    string input, string_to_count;
    cout << "Entrez une chaine de caractères : "<< endl;
    getline(cin, input);
    cout << "Entrez la suite de caractères à compter : "<< endl;
    getline(cin, string_to_count);
    cout << "La suite de caractères \"" << string_to_count << "\" apparait "<< trouver_instances(input,string_to_count) <<" fois dans la chaine \"" << input << "\"";
}