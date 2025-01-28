#ifndef TRI_H
#define TRI_H

#include <span>

template <typename T>
void sort(std::span<T> s) {
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
}


#endif //TRI_H
