#include "ZAU.hpp"

// Constructors
ZAU::ZAU(int num, std::string prop, Polygone<float> forme)
: Parcelle(num, prop, forme),      // <-- Appel direct à Parcelle
  Constructible(num, prop, forme)   
{
    this->type = "ZAU";              // <-- Initialiser le type
}

ZAU::ZAU(const ZAU & zau)
: Parcelle(zau),                     // <-- Appel direct à Parcelle
  Constructible(zau)                 // <-- Passer l'objet entier
{
    this->type = "ZAU";
}

ZAU::~ZAU() = default;

float ZAU::getSurfaceConstructible() const
{
    return this->surface * this->pourcentageConstructible / 100.0f;
}
