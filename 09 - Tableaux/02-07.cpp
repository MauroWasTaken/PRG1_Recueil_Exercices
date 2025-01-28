#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string to_string(const vector<int>& v) {
    stringstream output;
    output << "[";
    for (int i : v) {
        output << i << ", ";
    }
    return output.str().substr(0, output.str().size() - 2).append("]");
}
size_t trouver_index(vector<int>& v, int value) {
    for (size_t i = 0; i < v.size(); i++)
        if (v[i] == value)
            return i;
    return -1;
}
void supprimer_valeur(vector<int>& v, int value) {
    while (trouver_index(v, value) != -1){
        size_t index = trouver_index(v, value);
        for (int i = index; i < v.size()-1; i++)
            v[i] = v[i + 1];
        v.pop_back();
    }
}
void rendre_unique(vector <int>& v) {
    for (int i : v){
        size_t first_index = trouver_index(v, i);
        vector<int> subvector = {v.begin() + first_index + 1, v.end()};
        while (trouver_index(subvector, i) != -1){
            size_t index = trouver_index(subvector, i);
            for (int j = index; j < v.size()-1; j++)
                v[j] = v[j + 1];
            v.pop_back();
        }
    }
}

int main() {
    for (vector<int> v: {vector<int>{},
                         {2},
                         {1, 2, 2, 2, 3, 1, 2, 4},
                         {2, 3, 3, 2, 2, 1},
                         {2, 2, 2},
                         {5, 4, 4, 3, 2, 2, 2, 3}}) {
        cout << to_string(v) << " -> ";
        rendre_unique(v);
        cout << to_string(v) << endl;
                         }
}