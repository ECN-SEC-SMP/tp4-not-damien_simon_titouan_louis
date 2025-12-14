#include "ZAU.hpp"

// Constructors
ZAU::ZAU(int num, std::string prop, Polygone<float> forme, int pourcentageConstructible)
    : Parcelle(num, prop, forme), // <-- Appel direct à Parcelle
      Constructible(num, prop, forme)
{
  this->type = "ZAU";
  this->pourcentageConstructible = pourcentageConstructible;
}

ZAU::ZAU(const ZAU &zau)
    : Parcelle(zau),     // <-- Appel direct à Parcelle
      Constructible(zau) // <-- Passer l'objet entier
{
  this->type = "ZAU";
  this->pourcentageConstructible = zau.pourcentageConstructible;
}

ZAU::~ZAU() = default;

std::string ZAU::serialize() const
{
  std::string result = this->type;
  result += " " + std::to_string(this->numero);
  result += " " + this->proprietaire;
  result += " " + std::to_string(this->pourcentageConstructible);
  result += "\n" + this->forme.serialize();
  result += "\n";
  return result;
}

ZAU ZAU::deserialize(std::string input)
{
  int nl_pos = input.find('\n', 0);
  std::istringstream in(input.substr(0, nl_pos));
  std::string type;
  int numero;
  std::string proprietaire;
  int pConstructible;

  in >> type;
  in.ignore(1, ' ');
  in >> numero;
  in.ignore(1, ' ');
  in >> proprietaire;
  in.ignore(1, ' ');
  in >> pConstructible;

  auto forme = Polygone<float>::deserialize(input.substr(nl_pos + 1, input.npos));
  return ZAU(numero, proprietaire, forme, pConstructible);
}
