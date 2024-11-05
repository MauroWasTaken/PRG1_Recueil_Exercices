
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string milieu(string s) {
    int len = s.length();
    return s.substr(len % 2 ? len / 2 : (len/2) - 1,len % 2 ? 1 : 2);
}

int main() {
    cout << milieu("ABC") << endl;
}

