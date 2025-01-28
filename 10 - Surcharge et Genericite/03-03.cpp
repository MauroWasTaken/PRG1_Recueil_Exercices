#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Chiffre { ZERO,  UN,  DEUX,  TROIS,  QUATRE,  CINQ,  SIX,  SEPT,  HUIT,  NEUF };
array      CHIFFRE {"ZERO","UN","DEUX","TROIS","QUATRE","CINQ","SIX","SEPT","HUIT","NEUF" };

vector<Chiffre> nbreToEnums(int i){
    vector<Chiffre> output {};
    string s = to_string(i);
    for (const char c : s) {
        switch (c - '0') {
            case 0: output.push_back(Chiffre::ZERO); break;
            case 1: output.push_back(Chiffre::UN); break;
            case 2: output.push_back(Chiffre::DEUX); break;
            case 3: output.push_back(Chiffre::TROIS); break;
            case 4: output.push_back(Chiffre::QUATRE); break;
            case 5: output.push_back(Chiffre::CINQ); break;
            case 6: output.push_back(Chiffre::SIX); break;
            case 7: output.push_back(Chiffre::SEPT); break;
            case 8: output.push_back(Chiffre::HUIT); break;
            case 9: output.push_back(Chiffre::NEUF); break;
            default:break;
        }
    }
    return output;
}

ostream& operator<<(ostream& os, const vector<Chiffre>& v) {
    for (Chiffre chiffre : v) {
        cout << CHIFFRE[int(chiffre)] << " ";
    }
    return os;
}

int main() {
    cout << nbreToEnums(1298403);
}