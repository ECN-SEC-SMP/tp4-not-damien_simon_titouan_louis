#pragma once

#include "Parcelle.hpp"
#include "Polygone.hpp"

class ZN : virtual public Parcelle
{
public:
    /* Constructors */
    ZN(int num, std::string prop, Polygone<float> forme);
    ZN(const ZN &zn);
    ~ZN();

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
     * @return ZN
     */
    static ZN deserialize(std::string input);

    friend std::ostream &operator<<(std::ostream &out, ZN const &zn);
};
