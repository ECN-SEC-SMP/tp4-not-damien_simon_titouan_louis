#pragma once

#include <string>

#include "Constructible.hpp"

class ZU: public Constructible{
    private:
        float surfaceConstruite;
    public:
    ZU(int num, std::string prop, Polygone<float> forme, float surfaceConstruite, int pourcentageConstructible);
    ZU(const ZU & zu);
    ~ZU();

    /**
     * @brief Désérialise l'objet pour la lecture d'un fichier
     * 
     * @param input (IN) String à désérialiser
     * @return ZU 
     */
    static ZU deserialize(std::string input);

    float getSurfaceConstructible() const ;
};