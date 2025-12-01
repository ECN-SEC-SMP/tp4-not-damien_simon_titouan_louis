#include "ZN.hpp"

ZN::ZN(int num, std::string prop, Polygone<float> forme)
    : Parcelle(num, prop, forme)
{
    this->type = "Zone Naturelle et Forestière";
    this->pourcentageConstructible = 0;
}

ZN::~ZN() = default;