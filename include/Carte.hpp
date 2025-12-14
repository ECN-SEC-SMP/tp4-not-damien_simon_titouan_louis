#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Parcelle.hpp"

class Carte
{
private:
    /** * @brief Vecteur contenant la liste des parcelles.
     */
    std::vector<Parcelle *> Parcelles;

public:
    /**
     * @brief Constructeur par défaut.
     * Crée une carte vide.
     */
    Carte();

    /**
     * @brief Constructeur avec initialisation.
     * @param listeSommets Un vecteur de Parcelle pour initialiser la carte.
     */
    Carte(std::vector<Parcelle *> const &ListeParcelles);

    /**
     * @brief Enregistre le fichier.
     */
    void save(std::string filename);

    /**
     * @brief Lit le fichier.
     */
    void load(std::string filename);
};