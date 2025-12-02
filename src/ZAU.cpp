#include "ZAU.hpp"

// Constructors
ZAU::ZAU(int num, std::string prop, Polygone<float> forme)
: Constructible(num, prop, forme) {}

ZAU::ZAU(const ZAU & zau)
: Constructible(zau.numero, zau.proprietaire, zau.forme) {}

ZAU::~ZAU() = default;

float ZAU::getSurfaceConstructible() const
{
    return this->surface * this->pourcentageConstructible;
}