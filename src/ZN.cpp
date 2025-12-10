#include "ZN.hpp"

ZN::ZN(int num, std::string prop, Polygone<float> forme)
    : Parcelle(num, prop, forme)
{
    this->type = "ZN";
    this->pourcentageConstructible = 0;
}

ZN::ZN(const ZN &zn)
    : ZN(zn.numero, zn.proprietaire, zn.forme) {}

ZN::~ZN() = default;

std::ostream &operator<<(std::ostream &out, ZN const &zn)
{
    out << zn.toString() << std::endl;

    return out;
}