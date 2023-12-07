#include "machine.h"

int main() {
    std::string inputText;
    std::cout << "Введите строку для проверки: ";
    std::getline(std::cin, inputText);

    FSA machine;
    machine.answer(inputText);

    return 0;
}