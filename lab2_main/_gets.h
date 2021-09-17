#ifndef LAB2__GETS_H
#define LAB2__GETS_H

#include <iostream>

template<typename T>
bool is_correct_get(T &a) {
    std::cin >> a;
    if (!std::cin.good() || std::cin.eof()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

template<typename T>
T get_num() {
    T num;
    while (!is_correct_get(num)) {
        std::cout << "Введено не число." << std::endl;
    }
    return num;
}

#endif //LAB2__GETS_H
