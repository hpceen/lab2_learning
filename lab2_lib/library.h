#ifndef LAB2_LIB_LIBRARY_H
#define LAB2_LIB_LIBRARY_H

#include <cmath>
#include <iostream>
#include <vector>

const double pi = 3.1415926535;

//r = 2a (1 – cos (φ))
//(х^2 + у^2 +2аx) 2 – 4a^2(х^2 + у^2) = 0;

class cardioid {
//private:


public:
    double a;

    static double get_phi(std::pair<double, double> coords);

    explicit cardioid(double radius) {//2 задание
        a = radius;
    }

    ~cardioid() {
        a = 0;
    }

    cardioid(const cardioid &card) {
        a = card.a;
    }

    double change_r(double new_radius);//2 задание (1 пункт)

    [[nodiscard]] double dist_to_center(double phi) const;//3 задание (2 пункт)

    [[nodiscard]] std::vector<std::pair<double, double>> most_distant_from_Ox() const;//4 задание (3 пункт)

    [[nodiscard]] std::vector<std::pair<double, double>> get_coorsd_characteristic_points() const;//5 задание (4 пункт)

    [[nodiscard]]  std::vector<double> curvature_radius_of_characteristic_points(
            std::vector<std::pair<double, double>> vertexes) const;//5 задание (4 пункт)

    [[nodiscard]] double area() const;//6 задание

    [[nodiscard]] double length(double phi) const;//7 задание

};

#endif //LAB2_LIB_LIBRARY_H
