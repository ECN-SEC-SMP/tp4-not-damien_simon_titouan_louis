#include "Carte.hpp"

Carte::Carte() {}

Carte::Carte(std::vector<Parcelle> const &ListeParcelles)
    : Parcelles(ListeParcelles) {}

void Carte::load(std::string file)
{
}