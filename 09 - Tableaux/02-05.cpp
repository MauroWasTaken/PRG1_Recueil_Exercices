#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

void supprimer_centre(vector<int>& v) {
    if (v.empty()) return;
    int n = 2 - v.size() % 2;
    for (size_t i = 1 + v.size() / 2; i < v.size(); ++i) {
        v[i - n] = v[i];
    }
    v.resize(v.size()-n);
}

string to_string(const vector<int>& v) {
    stringstream output;
    output << "[";
    for (int i : v) {
        output << i << ", ";
    }
    return output.str().substr(0, output.str().size() - 2).append("]");
}

int main() {
    for (vector<int> v: {vector<int>{},
                         {1},
                         {1, 2},
                         {1, 2, 3},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4, 5},
                         {1, 2, 3, 4, 5, 6}}) {
        cout << to_string(v) << " -> ";
        supprimer_centre(v);
        cout << to_string(v) << endl;
                         }
}