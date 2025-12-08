#include <gtest/gtest.h>
#include "ZAU.hpp"
#include <vector>

TEST(ZAUTest, DefaultConstructor) {
    std::vector<Point2D<float>> points;
    points.push_back(Point2D<float>(0, 0));
    points.push_back(Point2D<float>(1, 0));
    points.push_back(Point2D<float>(1, 1));
    points.push_back(Point2D<float>(0, 1));
    
    Polygone<float> carre(points);

    ZAU zau(2, std::string("TEST"), carre);
    EXPECT_EQ(zau.getType(), "ZAU");
    EXPECT_EQ(zau.getNumero(), 2);
    EXPECT_EQ(zau.getProprietaire(), "TEST");
    EXPECT_FLOAT_EQ(zau.getSurface(), 1.0f);
}

TEST(ZAUTest, CopyConstructor) {
    std::vector<Point2D<float>> points;
    points.push_back(Point2D<float>(0, 0));
    points.push_back(Point2D<float>(2, 0));
    points.push_back(Point2D<float>(2, 3));
    points.push_back(Point2D<float>(0, 3));
    
    Polygone<float> rectangle(points);
    
    ZAU zau1(5, std::string("Original"), rectangle);
    ZAU zau2(zau1);  // Constructeur de copie
    
    // Vérifier que toutes les propriétés sont copiées
    EXPECT_EQ(zau2.getType(), "ZAU");
    EXPECT_EQ(zau2.getNumero(), 5);
    EXPECT_EQ(zau2.getProprietaire(), "Original");
    EXPECT_FLOAT_EQ(zau2.getSurface(), 6.0f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
