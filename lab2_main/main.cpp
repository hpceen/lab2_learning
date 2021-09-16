#include <iostream>
#include <library.h>
#include "_gets.h"
#include "prints.h"

int main() {
    std::cout << "Введите радиус окружности кардиоиды: ";
    cardioid card(get_num<double>());
    std::cout.flush();
    while (true) {
        print_menu();
        int choice = get_num<int>();
        if (choice == 1) {
            std::cout << "Введите новый радиус окружности кардиоиды: ";
            auto new_radius = get_num<double>();
            std::cout.flush();
            std::cout << "Новый радиус: " << card.change_r(new_radius) << std::endl;
        } else if (choice == 2) {
            std::cout << "Введите φ: ";
            auto phi = get_num<double>();
            std::cout.flush();
            std::cout << "Расстояние до центра в полярной системе координат (φ =  " << phi << "): "
                      << card.dist_to_center(phi) << std::endl;
        } else if (choice == 3) {
            std::cout << "Координаты наиболее удаленных от оси кардиоиды точек:" << std::endl;
            print_most_distant(card.most_distant_from_Ox());
        } else if (choice == 4) {
            std::cout << "Радиуса кривизны в характерных точках кардиоиды:" << std::endl;
            std::vector<std::pair<double, double>> coords = card.get_coorsd_characteristic_points();
            print_curv_r_of_char_p(coords, card.curvature_radius_of_characteristic_points(coords));
        } else if (choice == 5) {
            std::cout << "Площадь описываемая кардиоидой: " << card.area() << std::endl;
        } else if (choice == 6) {
            std::cout << "Введите φ: ";
            auto phi = get_num<double>();
            std::cout.flush();
            std::cout << "Длина дуги: " << card.length(phi) << std::endl;
        } else if (choice == 0) break;
        else {
            std::cout << "Введено неверное число" << std::endl;
        }
    }
    return 0;
}