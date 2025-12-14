#pragma once

#include <string>

#include "Constructible.hpp"

class ZAU: public Constructible{
    public:
        ZAU(int num, std::string prop, Polygone<float> forme, int pourcentageConstructible);
        ZAU(const ZAU & zau);  
        ~ZAU();  

    /**
     * @brief Serialize la parcelle pour l'écriture dans un fichier
     *
     * @return std::string
     */
    std::string serialize() const;

    /**
     * @brief Désérialise l'objet pour la lecture d'un fichier
     * 
     * @param input (IN) String à désérialiser
     * @return ZAU
     */
    static ZAU deserialize(std::string input);
};