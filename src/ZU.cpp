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

std::string ZU::serialize() const
{
    std::string result = this->type;
    result += " " + std::to_string(this->numero);
    result += " " + this->proprietaire;
    result += " " + std::to_string(this->pourcentageConstructible);
    result += " " + std::to_string(this->surfaceConstruite);
    result += "\n" + this->forme.serialize();
    result += "\n";
    return result;
}

ZU ZU::deserialize(std::string input)
{
    int nl_pos = input.find('\n', 0);
    std::istringstream in(input.substr(0, nl_pos));
    std::string type;
    int numero;
    std::string proprietaire;
    int surfaceConstruite;
    int pConstructible;

    in >> type;
    in.ignore(1, ' ');
    in >> numero;
    in.ignore(1, ' ');
    in >> proprietaire;
    in.ignore(1, ' ');
    in >> pConstructible;
    in.ignore(1, ' ');
    in >> surfaceConstruite;

    auto forme = Polygone<float>::deserialize(input.substr(nl_pos+1, input.npos));
    return ZU(numero, proprietaire, forme, surfaceConstruite, pConstructible);
}

