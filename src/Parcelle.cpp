#include "Parcelle.hpp"

/* Constructors */
Parcelle::Parcelle()
    : type("Inconnu"), numero(0), proprietaire(""), pourcentageConstructible(-1), forme(), surface(0.0f)
{
}

Parcelle::Parcelle(int num, std::string prop, Polygone<float> forme)
    : type("Inconnu"), numero(num), proprietaire(prop), pourcentageConstructible(-1)
{
    this->setForme(forme);
}

Parcelle::Parcelle(const Parcelle &parc)
{
    this->type = parc.type;
    this->numero = parc.numero;
    this->proprietaire = parc.proprietaire;
    this->pourcentageConstructible = parc.pourcentageConstructible;
    this->forme = parc.forme;
    this->surface = parc.surface;
}

Parcelle::~Parcelle() = default;

/* Getters */
int Parcelle::getNumero() const
{
    return this->numero;
}

std::string Parcelle::getProprietaire() const
{
    return this->proprietaire;
}

float Parcelle::getSurface() const
{
    return this->surface;
}

Polygone<float> Parcelle::getForme() const
{
    return this->forme;
}

std::string Parcelle::getType() const
{
    return this->type;
}

int Parcelle::getPercentageConstr() const
{
    return this->pourcentageConstructible;
}

/* Setters */
void Parcelle::setNumero(int n)
{
    this->numero = n;
}

void Parcelle::setProprietaire(std::string prop)
{
    this->proprietaire = prop;
}

void Parcelle::setForme(Polygone<float> forme)
{
    this->forme = forme;
    this->surface = forme.getSurface();
}

/* Methods */
std::string Parcelle::toString() const
{
    std::string str = "Parcelle n°" + std::to_string(this->numero) + "\n" + "\tType: " + this->type + "\n" + "\tForme: " + "this->forme" + "\n" + "\tPropriétaire: " + this->proprietaire + "\n" + "\tSurface: " + std::to_string(this->surface) + "\n" + "\t%% constructible: " + std::to_string(this->pourcentageConstructible);
    return str;
}

std::ostream &operator<<(std::ostream &os, const Parcelle &parc)
{
    os << parc.toString();
    return os;
}
