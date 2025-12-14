#include "Carte.hpp"

#include <fstream>
#include <sstream>

#include "Helper.hpp"
#include "ZN.hpp"
#include "ZA.hpp"
#include "ZAU.hpp"
#include "ZU.hpp"

Carte::Carte() {}

Carte::Carte(std::vector<Parcelle *> const &ListeParcelles)
    : Parcelles(ListeParcelles) {}

void Carte::save(std::string filename)
{
    std::ofstream file(filename);
    for (auto &&parcelle : this->Parcelles)
    {
        file << parcelle->serialize();
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
        std::istringstream in(str);
        std::string type;
        in >> type;

        std::string temp;
        std::getline(file, temp);
        str += '\n';
        str += temp;

        if (type == "ZN") // ZN
        {
            this->Parcelles.push_back(new ZN(ZN::deserialize(str)));
        }
        else if (type == "ZA") // ZA
        {
            this->Parcelles.push_back(new ZA(ZA::deserialize(str)));
        }
        else if (type == "ZAU") // ZAU
        {
            this->Parcelles.push_back(new ZAU(ZAU::deserialize(str)));
        }
        else if (type == "ZU") // ZU
        {
            this->Parcelles.push_back(new ZU(ZU::deserialize(str)));
        }
        else
        {
            std::getline(file, str);
            std::cerr << "Error: Unknown parcelle type!" << std::endl;
        }
    }
    file.close();
}