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

int main() {
    for (vector<int> v: {vector<int>{},
                         {2},
                         {1, 2, 2, 2, 3, 1, 2, 4},
                         {2, 3, 4, 3, 2, 1},
                         {2, 2, 2},
                         {5, 4, 3, 2, 1, 2}}) {
        cout << to_string(v) << " -> ";
        supprimer_valeur(v,2);
        cout << to_string(v) << endl;
    }
}