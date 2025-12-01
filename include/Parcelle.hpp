#pragma once

#include <string>

#include "Polygone.hpp"

class Parcelle
{
protected:
    std::string type;
    int numero;
    std::string proprietaire;
    float surface;
    Polygone<float> forme;
    int pourcentageConstructible;

public:
    /* Constructors */
    Parcelle(int num, std::string prop, Polygone<float> forme);
    Parcelle(const Parcelle & parc);
    ~Parcelle();

    /* Getters */
    /**
     * @brief Donne le numéro de parcelle
     * 
     * @return int 
     */
    int getNumero();
    /**
     * @brief Get the Proprietaire object
     * 
     * @return std::string 
     */
    std::string getProprietaire();
    /**
     * @brief Donne la surface totale de la parcelle
     * 
     * @return float 
     */
    float getSurface();
    /**
     * @brief Donne le polygone correspondant à la parcelle
     * 
     * @return Polygone<float> 
     */
    Polygone<float> getForme();
    /**
     * @brief Donne le type de parcelle
     * 
     * @return std::string 
     */
    std::string getType();

    /* Setters */
    /**
     * @brief Définit le numéro de la parcelle
     * 
     * @param n (IN) Nouveau numéro
     */
    void setNumero(int n);
    /**
     * @brief Définit le propriétaire de la parcelle
     * 
     * @param prop (IN) Nouveau Propriétaire
     */
    void setProprietaire(std::string prop);
    /**
     * @brief Définit le polygone de la parcelle
     * 
     * @param forme (IN) Nouvelle le poligone de la parcelle
     */
    void setForme(Polygone<int> forme);
};
