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

std::string ZN::serialize() const
{
    std::string result = this->type;
    result += " " + std::to_string(this->numero);
    result += " " + this->proprietaire;
    result += "\n" + this->forme.serialize();
    result += "\n";
    return result;
}

ZN ZN::deserialize(std::string input)
{
    int nl_pos = input.find('\n', 0);
    std::istringstream in(input.substr(0, nl_pos));
    std::string type;
    int numero;
    std::string proprietaire;

    in >> type;
    in.ignore(1, ' ');
    in >> numero;
    in.ignore(1, ' ');
    in >> proprietaire;

    auto forme = Polygone<float>::deserialize(input.substr(nl_pos+1, input.npos));
    return ZN(numero, proprietaire, forme);
}

std::ostream &operator<<(std::ostream &out, ZN const &zn)
{
    out << zn.toString() << std::endl;

    return out;
}