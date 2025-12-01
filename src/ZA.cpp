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