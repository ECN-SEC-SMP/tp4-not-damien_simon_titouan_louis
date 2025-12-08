#include "Constructible.hpp"

Constructible::Constructible(int num, std::string prop, Polygone<float> forme) : Parcelle(num, prop, forme) {}
Constructible::Constructible( const Constructible& constructible ) : Parcelle(constructible.numero, constructible.proprietaire, constructible.forme) {}
Constructible::~Constructible() {}

float Constructible::getSurfaceConstructible() const
{
    return this->surface * (this->pourcentageConstructible / 100 );
}