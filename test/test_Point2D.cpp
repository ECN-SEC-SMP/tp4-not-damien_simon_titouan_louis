#include <gtest/gtest.h>
#include "Point2D.hpp"


// Test du constructeur par défaut : doit initialiser à (0,0)
TEST(Point2DTest, constructeurdefault) {
    Point2D<int> p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

// Test du constructeur avec paramètres
TEST(Point2DTest, constructeurs) {
    Point2D<int> p(10, 20);
    EXPECT_EQ(p.getX(), 10);
    EXPECT_EQ(p.getY(), 20);
}

// Test du constructeur de copie
TEST(Point2DTest, copie) {
    Point2D<int> p1(5, 5);
    Point2D<int> p2(p1); // Copie
    EXPECT_EQ(p2.getX(), 5);
    EXPECT_EQ(p2.getY(), 5);
}


TEST(Point2DTest, set) {
    Point2D<int> p; 
    p.setX(42);
    p.setY(-10);
    
    EXPECT_EQ(p.getX(), 42);
    EXPECT_EQ(p.getY(), -10);
}


TEST(Point2DTest, translateX) {
    Point2D<int> p(10, 10);
    p.translateX(5); // 10 + 5
    EXPECT_EQ(p.getX(), 15);
    EXPECT_EQ(p.getY(), 10); // Y ne doit pas bouger
}

TEST(Point2DTest, translateY) {
    Point2D<int> p(10, 10);
    p.translateY(-5); // 10 - 5
    EXPECT_EQ(p.getX(), 10); // X ne doit pas bouger
    EXPECT_EQ(p.getY(), 5);
}

TEST(Point2DTest, translate) {
    Point2D<int> p(0, 0);
    p.translate(100, 50);
    EXPECT_EQ(p.getX(), 100);
    EXPECT_EQ(p.getY(), 50);
}


TEST(Point2DTest, testdouble) {
    Point2D<double> p(1.5, 2.5);
    p.translate(0.5, 0.5);
    
    EXPECT_DOUBLE_EQ(p.getX(), 2.0);
    EXPECT_DOUBLE_EQ(p.getY(), 3.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}