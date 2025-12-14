#include <gtest/gtest.h>
#include <vector>
#include "Point2D.hpp"
#include "Polygone.hpp"

// Test constructur
TEST(PolygoneTest, Constructeur)
{
    Polygone<int> poly;
    EXPECT_EQ(poly.getSommets().size(), 0);
}

// Test polygone avec points
TEST(PolygoneTest, Constructeurtriangle)
{
    std::vector<Point2D<int>> points;
    points.push_back(Point2D<int>(0, 0));
    points.push_back(Point2D<int>(10, 0));
    points.push_back(Point2D<int>(0, 10));

    Polygone<int> triangle(points);

    EXPECT_EQ(triangle.getSommets().size(), 3);
    EXPECT_EQ(triangle.getSommets()[1].getX(), 10);
}

TEST(PolygoneTest, add)
{
    Polygone<int> carre;

    carre.addSommet(Point2D<int>(0, 0));
    carre.addSommet(Point2D<int>(5, 0));

    EXPECT_EQ(carre.getSommets().size(), 2);
    EXPECT_EQ(carre.getSommets()[1].getX(), 5);
}

TEST(PolygoneTest, replace)
{
    Polygone<int> p;
    p.addSommet(Point2D<int>(1, 1));

    std::vector<Point2D<int>> nouveauxPoints;
    nouveauxPoints.push_back(Point2D<int>(10, 10));
    nouveauxPoints.push_back(Point2D<int>(20, 20));

    p.setSommets(nouveauxPoints);

    EXPECT_EQ(p.getSommets().size(), 2);
    EXPECT_EQ(p.getSommets()[0].getX(), 10);
}

// Test trnaslate
TEST(PolygoneTest, translate)
{
    std::vector<Point2D<int>> points;
    points.push_back(Point2D<int>(0, 0));
    points.push_back(Point2D<int>(10, 0));

    Polygone<int> carre(points);

    carre.translate(5, 5);

    std::vector<Point2D<int>> resultat = carre.getSommets();

    EXPECT_EQ(resultat[0].getX(), 5);
    EXPECT_EQ(resultat[0].getY(), 5);

    EXPECT_EQ(resultat[1].getX(), 15);
    EXPECT_EQ(resultat[1].getY(), 5);
}

// Test superficie
TEST(PolygoneTest, surface)
{
    std::vector<Point2D<int>> points;
    points.push_back(Point2D<int>(0, 0));
    points.push_back(Point2D<int>(1, 0));
    points.push_back(Point2D<int>(1, 1));
    points.push_back(Point2D<int>(0, 1));

    Polygone<int> carre(points);

    float surf = carre.getSurface();

    EXPECT_EQ(surf, 1);
}

TEST(PolygoneTest, copieprof)
{
    std::vector<Point2D<int>> points;
    points.push_back(Point2D<int>(0, 0));
    points.push_back(Point2D<int>(1, 0));
    points.push_back(Point2D<int>(1, 1));
    points.push_back(Point2D<int>(0, 1));

    Polygone<int> carre(points);
    Polygone<int> carrev2(carre);

    carre.translate(1, 1);

    auto sommetsCarre = carre.getSommets();
    auto sommetsCarrev2 = carrev2.getSommets();

    ASSERT_EQ(sommetsCarre.size(), sommetsCarrev2.size());

    for (size_t i = 0; i < sommetsCarre.size(); ++i)
    {
        EXPECT_EQ(sommetsCarrev2[i].getX() + 1, sommetsCarre[i].getX());
        EXPECT_EQ(sommetsCarrev2[i].getY() + 1, sommetsCarre[i].getY());
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}