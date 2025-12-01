#include "ZA.hpp"

ZA::ZA(int num, std::string prop, Polygone<float> forme, TypeCulture typeCulture)
    : Parcelle(num, prop, forme), typeCulture(typeCulture)
{
}

ZA::~ZA() = default;

TypeCulture ZA::getTypeCulture()
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

friend ostream ZA::&operator<<(ostream &out, ZA const &za)
{
    out << this->to_string() << std::endl
        << "\tType culture : " << za.getTypeCulture();

    return out;
}