#include <iostream>
#include <vector>

#include "Polygone.hpp"
#include "ZN.hpp"
#include "ZA.hpp"
#include "ZAU.hpp"
#include "ZU.hpp"
#include "Carte.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "Hello, World!" << std::endl;

    std::vector<Parcelle> parcelles;

    Polygone<float> zone({Point2D<float>(0, 0), Point2D<float>(1, 0), Point2D<float>(1, 1), Point2D<float>(0, 1)});
    ZN zn(1, "Moi", zone);
    // std::cout << zn << std::endl;

    // Polygone<float> zone({Point2D<float>(0, 0), Point2D<float>(1, 0), Point2D<float>(1, 1), Point2D<float>(0, 1)});
    ZA za(2, "Moii", zone, TypeCulture::CHANVRE, 10);
    // std::cout << za << std::endl;

    // Polygone<float> zone({Point2D<float>(0, 0), Point2D<float>(1, 0), Point2D<float>(1, 1), Point2D<float>(0, 1)});
    ZAU zau(3, "Moiii", zone, 20);
    zau.getSurfaceConstructible();
    // std::cout << zau << std::endl;

    // Polygone<float> zone({Point2D<float>(0, 0), Point2D<float>(1, 0), Point2D<float>(1, 1), Point2D<float>(0, 1)});
    ZU zu(4, "Moiiii", zone, 15.0f, 30);
    // std::cout << zu << std::endl;

    parcelles.push_back(zn);
    parcelles.push_back(za);
    parcelles.push_back(zau);
    parcelles.push_back(zu);

    for (auto &&parcelle : parcelles)
    {
        std::cout << parcelle << std::endl;
    }

    Carte carte({&za, &zau, &zu, &zn});
    carte.save("carte.txt");
    // carte.load("carte.txt");
    // carte.save("carte.txt");

    return 0;
}
