#include <iostream>
#include <gtest/gtest.h>
#define private public
#include <library.h>
#include <cmath>

TEST(Construct, Positive) {
    cardioid card(3.9);
    EXPECT_DOUBLE_EQ(card.a, 3.9);
}

TEST(Construct, Zero) {
    cardioid card(0);
    EXPECT_DOUBLE_EQ(card.a, 0);
}

TEST(Construct, Negative) {
    cardioid card(-4.32);
    EXPECT_DOUBLE_EQ(card.a, -4.32);
}

TEST(CopyConstruct, Positive) {
    cardioid card(3.78);
    cardioid card_copy(card);
    EXPECT_DOUBLE_EQ(card_copy.a, card.a);
}

TEST(CopyConstruct, Zero) {
    cardioid card(0);
    cardioid card_copy(card);
    EXPECT_DOUBLE_EQ(card_copy.a, card.a);
}

TEST(CopyConstruct, Negative) {
    cardioid card(-3.99);
    cardioid card_copy(card);
    EXPECT_DOUBLE_EQ(card_copy.a, card.a);
}

TEST(ChangingRadius, NotEqual) {
    cardioid card(-3.99);
    card.change_r(8.99);
    EXPECT_NE(card.a, -3.99);
}

TEST(ChangingRadius, Equal) {
    cardioid card(-3.99);
    card.change_r(8.99);
    EXPECT_DOUBLE_EQ(card.a, 8.99);
}

TEST(GetPhi, NotZero){
    cardioid card(0);
    EXPECT_DOUBLE_EQ(card.get_phi(std::make_pair(4.67, 8.88)), acos(4.67 / sqrt(4.67 * 4.67 + 8.88 * 8.88)));
}

TEST(GetPhi, Zero){
    cardioid card(0);
    EXPECT_DOUBLE_EQ(card.get_phi(std::make_pair(0, 0)), 0);
}

TEST(DistToCenter, Equal) {
    cardioid card(8.74);
    EXPECT_DOUBLE_EQ(card.dist_to_center(12), 2 * card.a * (1 - cos(12)));
}

TEST(DistToCenter, NotEqual) {
    cardioid card(8.74);
    EXPECT_NE(card.dist_to_center(12), 2 * card.a * (1 - cos(11)));
}

TEST(Most_Distant_Ox, All) {
    cardioid card(8.76);
    std::vector<std::pair<double, double>> coords = card.most_distant_from_o();
    EXPECT_DOUBLE_EQ(coords[0].first, card.a * -1.5);
    EXPECT_DOUBLE_EQ(coords[0].second, card.a * 3.0 * sqrt(3.0) / 2.0);
    EXPECT_DOUBLE_EQ(coords[1].first, card.a * -1.5);
    EXPECT_DOUBLE_EQ(coords[1].second, -card.a * 3.0 * sqrt(3.0) / 2.0);
}

TEST(CharacteristicPoints, All) {
    cardioid card(7.55);
    std::vector<std::pair<double, double>> coords = card.get_coorsd_characteristic_points();
    EXPECT_DOUBLE_EQ(coords[0].first, 0);
    EXPECT_DOUBLE_EQ(coords[0].second, 0);
    EXPECT_DOUBLE_EQ(coords[1].first, 0);
    EXPECT_DOUBLE_EQ(coords[1].second, card.a * 2);
    EXPECT_DOUBLE_EQ(coords[2].first, -4 * card.a);
    EXPECT_DOUBLE_EQ(coords[2].second, 0);
    EXPECT_DOUBLE_EQ(coords[3].first, 0);
    EXPECT_DOUBLE_EQ(coords[3].second, -2 * card.a);
}

TEST(CurvatureRadius, All) {
    cardioid card(9.65);
    std::vector<std::pair<double, double>> vertexes = card.get_coorsd_characteristic_points();
    std::vector<double> curv_rads = card.curvature_radius_of_characteristic_points();
    EXPECT_DOUBLE_EQ(curv_rads[0], 8.0 / 3.0 * card.a * sin(card.get_phi(vertexes[0]) / 2.0));
    EXPECT_DOUBLE_EQ(curv_rads[1], 8.0 / 3.0 * card.a * sin(card.get_phi(vertexes[1]) / 2.0));
    EXPECT_DOUBLE_EQ(curv_rads[2], 8.0 / 3.0 * card.a * sin(card.get_phi(vertexes[2]) / 2.0));
    EXPECT_DOUBLE_EQ(curv_rads[3], 8.0 / 3.0 * card.a * sin(card.get_phi(vertexes[3]) / 2.0));
}

TEST(Area, NotZero){
    cardioid card(7.66);
    EXPECT_DOUBLE_EQ(card.area(), 6 * M_PI * card.a * card.a);
}

TEST(Area, Zero){
    cardioid card(0);
    EXPECT_DOUBLE_EQ(card.area(), 6 * M_PI * card.a * card.a);
}

TEST(Length, All){
    cardioid card(89.13);
    EXPECT_DOUBLE_EQ(card.length(3.25, 6.6), std::abs(8 * card.a * (sin (6.6/2) - sin(3.25 / 2))));
}