#include <iostream>
#include <vector>
#include <algorithm>

template <typename T, typename S>
class FSA {
public:
    FSA();
    bool isRight(const T& inputText);
    std::pair<int, S> getErrorInfo() const;
    void answer(const T& inputText);

private:
    std::vector<S> alphabet;
    std::vector<std::vector<int>> jumping_table;
    int state;
    int fail;
    std::vector<int> right_state_list;
    std::pair<int, S> errorInfo;
};

template <typename T, typename S>
FSA<T, S>::FSA() {
    alphabet = {'a', 'b'};
    jumping_table = {
        {1, 2},
        {3, 2},
        {1, 3},
        {3, 3}
    };
    state = 0;
    fail = 3;
    right_state_list = {1, 2};
}

template <typename T, typename S>
bool FSA<T, S>::isRight(const T& inputText) {
    state = 0;
    for (S word : inputText) {
        auto pos = std::find(alphabet.begin(), alphabet.end(), word);
        if (pos != alphabet.end()) {
            int wordIndex = std::distance(alphabet.begin(), pos);
            state = jumping_table[state][wordIndex];
        } else {
            state = fail;
        }
        if (state == fail) {
            errorInfo = {static_cast<int>(std::distance(inputText.begin(), std::find(inputText.begin(), inputText.end(), word))), word};
            return false;
        }
    }
    return std::find(right_state_list.begin(), right_state_list.end(), state) != right_state_list.end();
}

template <typename T, typename S>
std::pair<int, S> FSA<T, S>::getErrorInfo() const {
    return errorInfo;
}

template <typename T, typename S>
void FSA<T, S>::answer(const T& inputText) {
    if (isRight(inputText)) {
        std::cout << state << std::endl;
    } else {
        std::cout << "Входная цепочка неверна\nОшибка на месте " << errorInfo.first << " - символ " << errorInfo.second << std::endl;
    }
}

int main() {
    std::string inputText; 
    std::cout << "строка для проверки: ";    
    std::getline(std::cin, inputText);
    FSA<std::string, char> machine; 
    machine.answer(inputText);
    return 0;
}