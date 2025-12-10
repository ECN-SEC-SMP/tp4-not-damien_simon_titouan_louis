#include "ZU.hpp"

//Constructors
ZU::ZU(int num, std::string prop, Polygone<float> forme, float surfaceConstruite, int pourcentageConstructible)
: Parcelle(num, prop, forme),Constructible(num, prop, forme), surfaceConstruite(surfaceConstruite) {
    this->type = "ZU";
    this->pourcentageConstructible = pourcentageConstructible;
}

ZU::ZU(const ZU & zu)
: Parcelle(zu.numero, zu.proprietaire, zu.forme), Constructible(zu.numero, zu.proprietaire, zu.forme), surfaceConstruite(zu.surfaceConstruite) {
    this->type = "ZU";
    this->pourcentageConstructible = zu.pourcentageConstructible;
}

ZU::~ZU() = default;

float ZU::getSurfaceConstructible() const 
{
    return this->surface * this->pourcentageConstructible/ 100.0f - surfaceConstruite;
}

