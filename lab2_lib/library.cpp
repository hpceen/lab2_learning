#include "library.h"
#include <cmath>

double cardioid::change_r(double new_radius) {
    a = new_radius;
    return new_radius;
}

double cardioid::dist_to_center(double phi) const {
    return std::abs(2 * a * (1 - cos(phi)));
}

std::vector<std::pair<double, double>> cardioid::most_distant_from_o() const {
    std::vector<std::pair<double, double>> vertexes;
    vertexes.emplace_back(a * -1.5, a * 3.0 * sqrt(3.0) / 2.0);
    vertexes.emplace_back(a * -1.5, -a * 3.0 * sqrt(3.0) / 2.0);
    return vertexes;
}

std::vector<std::pair<double, double>> cardioid::get_coorsd_characteristic_points() const {
    std::vector<std::pair<double, double>> result;
    result.emplace_back(0, 0);
    result.emplace_back(0, 2 * a);
    result.emplace_back(-4 * a, 0);
    result.emplace_back(0, -2 * a);
    return result;
}

double cardioid::get_phi(std::pair<double, double> coords) {
    double x = coords.first;
    double y = coords.second;
    if (x == 0 && y == 0) return 0;
    return acos(x / sqrt(x * x + y * y));
}

std::vector<double>
cardioid::curvature_radius_of_characteristic_points() const {
    std::vector<double> result;
    std::vector<std::pair<double, double>> vertexes = get_coorsd_characteristic_points();
    result.reserve(4);
    for (int i = 0; i < 4; ++i) {
        result.push_back(8.0 / 3.0 * a * sin(get_phi(vertexes[i]) / 2.0));
    }
    return result;
}

double cardioid::area() const {
    return 6 * M_PI * a * a;
}

double cardioid::length(double phi1, double phi2) const {
    return std::abs(8 * a * (sin(phi2 / 2) - sin(phi1 / 2)));
}