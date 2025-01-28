#include <vector>
#include <array>
#include <iostream>
#include <span>
#include <string>

using namespace std;

template <typename T>
void exchange(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
vector<T> sort(vector<T> s) {
    for (size_t i = 0; i < s.size() - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < s.size(); j++) {
            if (s[j] < s[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(s[i], s[min_index]);
        }
    }
    return s;
}

template <typename T>
void show(const vector<T>& s) {
    for (const T& t : s) {
        cout << t << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v1 {6, 2, 9, 7, 1, 3};

    const vector<int>    vInt {6, 2, 9, 7, 1, 3};
    const vector<string> vStr {"chien"s, "chat"s, "souris"s, "poisson"s};

    show (v1);
    show (sort(v1));


    show (vInt);
    show (sort(vInt));


    show (vStr);
    show (sort(vStr));
}
