#include "Carte.hpp"

#include <fstream>

Carte::Carte() {} 

Carte::Carte(std::vector< Parcelle > const& ListeParcelles)
    : Parcelles(ListeParcelles) {}

void Carte::save(std::string filename)
{
    std::ofstream file(filename);
    for (auto &&parcelle : this->Parcelles)
    {
        file << parcelle.serialize();
    }
    file.close();
}

void Carte::load(std::string filename)
{

}