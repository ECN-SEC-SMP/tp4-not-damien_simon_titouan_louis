#include "ZA.hpp"

ZA::ZA(int num, std::string prop, Polygone<float> forme, TypeCulture typeCulture, int pourcentageConstructible)
    : Parcelle(num, prop, forme), ZN(num, prop, forme), Constructible(num, prop, forme), typeCulture(typeCulture)
{
    this->type = "ZA";
    this->pourcentageConstructible = pourcentageConstructible;
}

ZA::ZA(const ZA &za)
    : ZA(za.numero, za.proprietaire, za.forme, za.typeCulture, za.pourcentageConstructible) {}

ZA::~ZA() = default;

TypeCulture ZA::getTypeCulture() const
{
    return this->typeCulture;
}

bool ZA::constructible(Polygone<float> surface_a_construire)
{
    bool constructible = true;
    constructible = constructible && (surface_a_construire.getSurface() < 0.1 * this->getSurfaceConstructible());
    constructible = constructible && (surface_a_construire.getSurface() < 200);

    return constructible;
}

std::string ZA::serialize() const
{
    std::string result = this->type;
    result += " " + std::to_string(this->numero);
    result += " " + this->proprietaire;
    result += " " + std::to_string(this->typeCulture);
    result += " " + std::to_string(this->pourcentageConstructible);
    result += "\n" + this->forme.serialize();
    result += "\n";
    return result;
}

ZA ZA::deserialize(std::string input)
{
    int nl_pos = input.find('\n', 0);
    std::istringstream in(input.substr(0, nl_pos));
    std::string type;
    int numero;
    std::string proprietaire;
    int typeCulture;
    int pConstructible;

    in >> type;
    in.ignore(1, ' ');
    in >> numero;
    in.ignore(1, ' ');
    in >> proprietaire;
    in.ignore(1, ' ');
    in >> typeCulture;
    in.ignore(1, ' ');
    in >> pConstructible;

    auto forme = Polygone<float>::deserialize(input.substr(nl_pos + 1, input.npos));
    return ZA(numero, proprietaire, forme, (TypeCulture)typeCulture, pConstructible);
}

std::ostream &operator<<(std::ostream &out, ZA const &za)
{
    out << za.toString() << std::endl
        << "\tType culture : " << za.getTypeCulture();

    return out;
}