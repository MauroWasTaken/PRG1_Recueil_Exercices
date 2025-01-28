#include <span>
#include <array>

using namespace std;

void rotateRight(span<int> s){
    if (s.empty()) return;
    for (int i = s.size() - 1; i > 0; --i){
        if (s[i]>s[i-1]){
          int t = s[i];
          s[i] = s[i-1];
          s[i-1] = t;
        }
    }
}

int main(){
    array a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotateRight(a);
    return 0;
}