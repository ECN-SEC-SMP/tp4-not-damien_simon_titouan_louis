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
    int getNumero() const;
    /**
     * @brief Get the Proprietaire object
     * 
     * @return std::string 
     */
    std::string getProprietaire() const;
    /**
     * @brief Donne la surface totale de la parcelle
     * 
     * @return float 
     */
    float getSurface() const;
    /**
     * @brief Donne le polygone correspondant à la parcelle
     * 
     * @return Polygone<float> 
     */
    Polygone<float> getForme() const;
    /**
     * @brief Donne le type de parcelle
     * 
     * @return std::string 
     */
    std::string getType() const;
    /**
     * @brief Donne le percentage constructible de la parcelle
     * 
     * @return int 
     */
    int getPercentageConstr() const;

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
    void setForme(Polygone<float> forme);

    /* Methods */
    /**
     * @brief Donne les informations formatées de la parcelle 
     * 
     * @return std::string 
     */
    std::string toString() const;

    friend std::ostream & operator<< (std::ostream os, const Parcelle & parc);
};
