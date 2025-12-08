#include "ZA.hpp"

ZA::ZA(int num, std::string prop, Polygone<float> forme, TypeCulture typeCulture, int pourcentageConstructible)
    : ZN(num, prop, forme), Constructible(num, prop, forme), typeCulture(typeCulture)
{
    this->type = "Zone Agricole";
    this->pourcentageConstructible = pourcentageConstructible;
}

ZA::~ZA() = default;

TypeCulture ZA::getTypeCulture() const
{
    return this->typeCulture;
}

bool ZA::constructible(Polygone<float> surface_a_construire)
{
    bool constructible = true;
    constructible = constructible && (surface_a_construire.getSurface() < 0.1 * this->getSurfaceConstructible());
    constructible = constructible && (surface_a_construire.getSurface() < 200);

    return constructible;
}

std::ostream &operator<<(std::ostream &out, ZA const &za)
{
    out << za.toString() << std::endl
        << "\tType culture : " << za.getTypeCulture();

    return out;
}