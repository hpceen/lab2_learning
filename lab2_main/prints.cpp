#include "prints.h"
#include <iostream>

void print_menu() {
    std::cout << "1)Изменить радиус." << std::endl;
    std::cout
            << "2)Вернуть расстояние до центра в полярной системе координат в зависимости от угла для точки принадлежащей кардиоиде."
            << std::endl;
    std::cout << "3)Вернуть координаты наиболее удаленных от оси кардиоиды точек." << std::endl;
    std::cout << "4)Вернуть радиуса кривизны в характерных точках кардиоиды." << std::endl;
    std::cout << "5)Вернуть площадь описываемую кардиоидой." << std::endl;
    std::cout << "6)Вернуть длину дуги кардиоиды в зависимости от угла полярного радиуса." << std::endl;
    std::cout << "0)Выход." << std::endl;
}

void print_most_distant(const std::vector<std::pair<double, double>> &vertexes) {
    for (int i = 0; i < 2; ++i) {
        std::cout << "(" << vertexes[i].first << "; " << vertexes[i].second << ")" << std::endl;
    }
}

void print_curv_r_of_char_p(const std::vector<std::pair<double, double>> &coords, const std::vector<double> &curv_rads) {
    for (int i = 0; i < 4; ++i) {
        std::cout << "(" << coords[i].first << "; " << coords[i].second << ") " << "Радиус кривизны: " << curv_rads[i]
                  << std::endl;
    }
}