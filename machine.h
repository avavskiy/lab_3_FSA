#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class FSA {
public:
    FSA();

    bool isRight(const std::string& inputText);

    std::pair<int, char> getErrorInfo() const;

    void answer(const std::string& inputText);

private:
    std::string alphabet;
    std::vector<std::vector<int>> jumping_table;
    int state;
    int fail;
    std::vector<int> right_state_list;
    std::pair<int, char> errorInfo;
};

#endif // MACHINE_H
