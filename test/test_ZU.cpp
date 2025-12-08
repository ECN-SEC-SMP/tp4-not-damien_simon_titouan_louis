#include <gtest/gtest.h>
#include "ZU.hpp"
#include <vector>

TEST(ZUTest, DefaultConstructor) {
    std::vector<Point2D<float>> points;
    points.push_back(Point2D<float>(0, 0));
    points.push_back(Point2D<float>(1, 0));
    points.push_back(Point2D<float>(1, 1));
    points.push_back(Point2D<float>(0, 1));
    
    Polygone<float> carre(points);

    ZU zu(3, std::string("TESTZU"), carre, 0.5f);
    EXPECT_EQ(zu.getType(), "ZU");
    EXPECT_EQ(zu.getNumero(), 3);
    EXPECT_EQ(zu.getProprietaire(), "TESTZU");
    EXPECT_FLOAT_EQ(zu.getSurface(), 1.0f);
}

TEST(ZUTest, CopyConstructor) {
    std::vector<Point2D<float>> points;
    points.push_back(Point2D<float>(0, 0));
    points.push_back(Point2D<float>(2, 0));
    points.push_back(Point2D<float>(2, 3));
    points.push_back(Point2D<float>(0, 3));
    
    Polygone<float> rectangle(points);
    
    ZU zu1(7, std::string("OriginalZU"), rectangle, 2.0f);
    ZU zu2(zu1);  
    
    EXPECT_EQ(zu2.getType(), "ZU");
    EXPECT_EQ(zu2.getNumero(), 7);
    EXPECT_EQ(zu2.getProprietaire(), "OriginalZU");
    EXPECT_FLOAT_EQ(zu2.getSurface(), 6.0f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
