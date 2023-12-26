#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
class FSA {
public:
    FSA();

    bool isRight(const std::basic_string<T>& inputText);

    std::pair<int, T> getErrorInfo() const;

    void answer(const std::basic_string<T>& inputText);

private:
    std::basic_string<T> alphabet;
    std::vector<std::vector<int>> jumping_table;
    int state;
    int fail;
    std::vector<int> right_state_list;
    std::pair<int, T> errorInfo;
};

template<typename T1>
FSA<T1>::FSA() {
    alphabet = "abcdef01234;";
    jumping_table = {
        {1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
    };
    state = 0;
    fail = 3;
    right_state_list = {1, 2};
}

template<typename T2>
bool FSA<T2>::isRight(const std::basic_string<T2>& inputText) {
    state = 0;
    for (T2 word : inputText) {
        if (alphabet.find(word) != std::basic_string<T2>::npos) {
            int wordIndex = alphabet.find(word);
            state = jumping_table[state][wordIndex];
        } else {
            state = fail;
        }
        if (state == fail) {
            errorInfo = {static_cast<int>(inputText.find(word)), word};
            return false;
        }
    }
    return std::find(right_state_list.begin(), right_state_list.end(), state) != right_state_list.end();
}

template<typename T3>
std::pair<int, T3> FSA<T3>::getErrorInfo() const {
    return errorInfo;
}

template<typename T4>
void FSA<T4>::answer(const std::basic_string<T4>& inputText) {
    if (isRight(inputText)) {
        std::cout << "Входная цепочка верна" << std::endl;
    } else {
        std::cout << "Входная цепочка неверна\nОшибка на месте " << errorInfo.first << " - символ " << errorInfo.second << std::endl;
    }
}
#endif