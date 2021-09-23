#ifndef LAB2_LIB_LIBRARY_H
#define LAB2_LIB_LIBRARY_H

#include <vector>

//r = 2a (1 – cos (φ))
//(х^2 + у^2 +2аx) 2 – 4a^2(х^2 + у^2) = 0;

class cardioid {
private:
    static double get_phi(std::pair<double, double> coords);

    double a;
public:
    cardioid() {
        a = 0;
    }

    explicit cardioid(double radius) {//2 задание
        a = radius;
    }

    ~cardioid() = default;

    cardioid(const cardioid &card) {
        a = card.get_a();
    }

    [[nodiscard]] double get_a() const { return a; }

    double change_r(double new_radius);//Изменить радиус.

    [[nodiscard]] double dist_to_center(
            double phi) const;//Вернуть расстояние до центра в полярной системе координат в зависимости от угла для точки принадлежащей кардиоиде.

    [[nodiscard]] std::vector<std::pair<double, double>>
    most_distant_from_o() const;//Вернуть координаты наиболее удаленных от оси кардиоиды точек.

    [[nodiscard]] std::vector<std::pair<double, double>>
    get_coorsd_characteristic_points() const;//Получение координат характерных точек

    [[nodiscard]]  std::vector<double>
    curvature_radius_of_characteristic_points() const;//Вернуть радиуса кривизны в характерных точках кардиоиды.

    [[nodiscard]] double area() const;//Вернуть площадь описываемую кардиоидой.

    [[nodiscard]] double
    length(double phi1, double phi2) const;//Вернуть длину дуги кардиоиды в зависимости от угла полярного радиуса.

};

#endif //LAB2_LIB_LIBRARY_H
