#include "Parcelle.hpp"

/* Constructors */
Parcelle::Parcelle(int num, std::string prop, Polygone<float> forme)
    : numero(num), proprietaire(prop), pourcentageConstructible(-1), type("Inconnu")
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
int Parcelle::getNumero()
{
    return this->numero;
}

std::string Parcelle::getProprietaire()
{
    return this->proprietaire;
}

float Parcelle::getSurface()
{
    return this->surface;
}

Polygone<float> Parcelle::getForme()
{
    return this->forme;
}

std::string Parcelle::getType()
{
    return this->type;
}

int Parcelle::getPercentageConstr()
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
    this->surface = 0;
    for (size_t i = 0; i < forme.getSommets().size(); i++)
    {
        auto point0 = forme.getSommets().at(i);
        auto point1 = forme.getSommets().at(i + 1);
        this->surface += point0.getX() * point1.getY() - point1.getX() * point1.getY();
    }
    this->surface /= 2;
}
