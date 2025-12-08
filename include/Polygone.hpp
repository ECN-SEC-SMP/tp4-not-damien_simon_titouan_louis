/**
 * @file Polygone.hpp
 * @brief Définition d'une classe template représentant un polygone géométrique.
 * @author CAU_Simon
 * @version 1.0
 */

#pragma once
#include <iostream>
#include <vector>
#include "Point2D.hpp"


template<typename T>
class Polygone;


template<typename T>
std::ostream& operator<<(std::ostream& os, Polygone<T> const& p);

/**
 * @class Polygone
 * @brief Classe template gérant une collection de points (sommets) formant un polygone.
 * * Cette classe stocke une liste de Point2D et permet d'effectuer des opérations 
 * globales comme la translation ou l'affichage de la forme complète.
 * * @tparam T Le type de donnée des coordonnées des sommets (ex: int, double).
 */
template<typename T>
class Polygone {
private:
    /** * @brief Vecteur contenant la liste ordonnée des sommets du polygone. 
     */
    std::vector< Point2D<T> > sommets;

public:
    /**
     * @brief Constructeur par défaut.
     * Crée un polygone vide (sans sommets).
     */
    Polygone() {} 

    /**
     * @brief Constructeur avec initialisation.
     * @param listeSommets Un vecteur de Point2D pour initialiser le polygone.
     */
    Polygone(std::vector< Point2D<T> > const& listeSommets)
        : sommets(listeSommets) {}

    // Setteurs et Getters

    /**
     * @brief Récupère la liste des sommets.
     * @return Un vecteur contenant tous les points du polygone.
     */
    std::vector< Point2D<T> > getSommets() const; 

    /**
     * @brief Donne la surface totale de la parcelle
     * @return float 
     */
    float getSurface();

    /**
     * @brief Remplace la liste actuelle des sommets.
     * @param listeSommets Le nouveau vecteur de points.
     */
    void setSommets(std::vector< Point2D<T> > const& listeSommets);

    /**
     * @brief Ajoute un nouveau sommet à la fin de la liste du polygone.
     * @param p Le point à ajouter.
     */
    void addSommet(Point2D<T> const& p); 

    // Opérations Géométriques

    /**
     * @brief Translate le polygone entier.
     * Applique une translation (x, y) à chaque sommet du polygone.
     * @param x Valeur de déplacement horizontal.
     * @param y Valeur de déplacement vertical.
     */
    void translate(T x, T y);

    /**
     * @brief Affiche le contenu du polygone dans un flux.
     * Format de sortie : Polygone [Point1, Point2, ...]
     * @param os Le flux de sortie.
     */
    virtual void afficher(std::ostream& os) const;

    /**
     * @brief Surcharge de l'opérateur de flux pour l'affichage standard.
     * @param os Le flux de sortie (ex: std::cout).
     * @param p Le polygone à afficher.
     * @return Une référence vers le flux de sortie.
     */
    friend std::ostream& operator<< <T>(std::ostream& os, Polygone<T> const& p);

};

// Implémentation des méthodes

template<typename T>
std::vector< Point2D<T> > Polygone<T>::getSommets() const {
    return this->sommets;
}

template<typename T>
float Polygone<T>::getSurface(){
    float surface = 0;
    for (size_t i = 0; i < this->sommets.size(); i++)
    {
        auto point0 = this->sommets.at(i);
        auto point1 = this->sommets.at(i + 1);
        surface += point0.getX() * point1.getY() - point1.getX() * point1.getY();
    }
    return surface /= 2;

}

template<typename T>
void Polygone<T>::setSommets(std::vector< Point2D<T> > const& listeSommets) {
    this->sommets = listeSommets;
}

template<typename T>
void Polygone<T>::addSommet(Point2D<T> const& p) {
    this->sommets.push_back(p);
}

template<typename T>
void Polygone<T>::translate(T x, T y) {
    // Itère sur chaque point par référence pour le modifier
    for (auto& p : this->sommets) {
        p.translate(x, y); 
    }
}

template<typename T>
void Polygone<T>::afficher(std::ostream& os) const {
    os << "Polygone [";
    for (size_t i = 0; i < sommets.size(); ++i) {
        os << sommets[i]; // Utilise l'opérateur << de Point2D
        if (i < sommets.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Polygone<T> const& p) {
    p.afficher(os);
    return os;
}