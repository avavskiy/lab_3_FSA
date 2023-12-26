#include "machine.h"

int main() {
    std::basic_string<char> inputText;
    std::cout << "Введите строку для проверки: ";
    std::getline(std::cin, inputText);

    FSA<char> machine;
    machine.answer(inputText);

    return 0;
}