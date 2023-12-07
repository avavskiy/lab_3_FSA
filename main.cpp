#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class FSA {
public:
    FSA() {
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

    bool isRight(const std::string& inputText) {
        state = 0;
        for (char word : inputText) {
            if (alphabet.find(word) != std::string::npos) {
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

    std::pair<int, char> getErrorInfo() const {
        return errorInfo;
    }

    void answer(const std::string& inputText) {
        if (isRight(inputText)) {
            std::cout << "Входная цепочка верна" << std::endl;
        } else {
            std::cout << "Входная цепочка неверна\nОшибка на месте " << errorInfo.first << " - символ " << errorInfo.second << std::endl;
        }
    }

private:
    std::string alphabet;
    std::vector<std::vector<int>> jumping_table;
    int state;
    int fail;
    std::vector<int> right_state_list;
    std::pair<int, char> errorInfo;
};

int main() {
    std::string inputText;
    std::cout << "Введите строку для проверки: ";
    std::getline(std::cin, inputText);

    FSA machine;
    machine.answer(inputText);

    return 0;
}