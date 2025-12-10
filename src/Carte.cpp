#include "Carte.hpp"

#include <fstream>
#include <sstream>

#include "Helper.hpp"
#include "ZN.hpp"
#include "ZA.hpp"
#include "ZAU.hpp"
#include "ZU.hpp"

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
    this->Parcelles.clear();

    std::ifstream file(filename);
    std::string str; 
    while (std::getline(file, str))
    {
        std::cout << "str: " << str << std::endl;

        std::istringstream in(str);
        std::string type;
        int numero;
        std::string proprietaire;

        in >> type;
        in.ignore(1, ' ');
        in >> numero;
        in.ignore(1, ' ');
        in >> proprietaire;

        std::cout << "type: " << type << std::endl;
        std::cout << "numero: " << numero << std::endl;
        std::cout << "proprietaire: " << proprietaire << std::endl;

        if (type == "ZN") // ZN
        {
            std::getline(file, str);
            std::cout << "str: " << str << std::endl;
            auto forme = Polygone<float>::deserialize(str);
        }
        else if (type == "ZA") // ZA
        {
            std::getline(file, str);
            auto forme = Polygone<float>::deserialize(str);
        }
        else if (type == "ZAU") // ZAU
        {
            std::getline(file, str);
            auto forme = Polygone<float>::deserialize(str);
        }
        else if (type == "ZU") // ZU
        {
            std::getline(file, str);
            auto forme = Polygone<float>::deserialize(str);
        }
        else
        {
            std::getline(file, str);
            std::cerr << "Error: Unknown parcelle type!" << std::endl;
        }
    }
}