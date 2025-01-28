#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string to_string(const vector<int>& v) {
    stringstream output;
    output << "[";
    for (int i : v) {
        output << i << ", ";
    }
    return output.str().substr(0, output.str().size() - 2).append("]");
}


int main () {
    const vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << to_string(v); // [1, 2, 3, 4, 5, 6]
}