#include "ZAU.hpp"

// Constructors
ZAU::ZAU(int num, std::string prop, Polygone<float> forme, float pourcentageConstructible)
: Parcelle(num, prop, forme),      // <-- Appel direct à Parcelle
  Constructible(num, prop, forme)   
{
    this->type = "ZAU";  
    this->pourcentageConstructible = pourcentageConstructible;
}

ZAU::ZAU(const ZAU & zau)
: Parcelle(zau),                     // <-- Appel direct à Parcelle
  Constructible(zau)                 // <-- Passer l'objet entier
{
    this->type = "ZAU";
    this->pourcentageConstructible = zau.pourcentageConstructible;
}

ZAU::~ZAU() = default;

