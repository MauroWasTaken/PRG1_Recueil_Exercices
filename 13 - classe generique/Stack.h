//
// Created by mauro on 09/01/25.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <array>

template <typename T, size_t n>
class Stack{
    size_t _size = 0;
    std::array <T,n> data {};
public:
    void display() const {
        std::cout << "size   : " << this->_size << std::endl
             << "data   : [";
        for (T i = 0; i < this->_size; i++) {
            std::cout << this->data[i];
            if (i != this->_size -1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    [[nodiscard]] bool full() const {
        return this->_size == 10;
    }

    [[nodiscard]] bool empty() const {
        return this->_size == 0;
    }

    void push(T val) {
        this->data[this->_size] = val;
        ++this->_size;
    }

    void pop() {
        --this->_size;
    }

    [[nodiscard]] T top() const {
        return this->data[this->_size-1];
    }

    [[nodiscard]] size_t size() const {
        return this->_size;
    }
};




#endif //STACK_H
