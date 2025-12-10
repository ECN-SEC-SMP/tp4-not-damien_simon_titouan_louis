/**
 * @file Point2D.hpp
 * @brief Définition d'une classe template représentant un point en deux dimensions.
 * @author CAU_Simon
 * @version 1.0
 */

#pragma once
#include <iostream>


template <typename T>
class Point2D;


template <typename T>
std::ostream &operator<<(std::ostream &, Point2D<T> const &p);

/**
 * @class Point2D
 * @brief Classe template pour gérer des coordonnées 2D (x, y).
 * * Cette classe permet de manipuler des points avec des types génériques
 * (int, float, double, etc.) et offre des fonctionnalités de translation.
 * * @tparam T Le type de donnée des coordonnées (ex: int, double).
 */
template <typename T>
class Point2D
{
protected:
    T x; /**< Coordonnée sur l'axe des abscisses */
    T y; /**< Coordonnée sur l'axe des ordonnées */

public:
    /**
     * @brief Constructeur avec paramètres.
     * @param x La coordonnée X initiale.
     * @param y La coordonnée Y initiale.
     */
    Point2D(T x, T y);

    /**
     * @brief Constructeur de copie.
     * @param p Le point à copier.
     */
    Point2D(Point2D const &p);

    /**
     * @brief Constructeur par défaut.
     * Initialise le point (généralement à 0,0 selon l'implémentation).
     */
    Point2D();

    // Setteurs et Getters

    /**
     * @brief Récupère la coordonnée X.
     * @return La valeur de x.
     */
    T getX() const;

    /**
     * @brief Définit la coordonnée X.
     * @param x La nouvelle valeur de x.
     */
    void setX(T x);

    /**
     * @brief Récupère la coordonnée Y.
     * @return La valeur de y.
     */
    T getY() const;

    /**
     * @brief Définit la coordonnée Y.
     * @param y La nouvelle valeur de y.
     */
    void setY(T y);

    // Méthodes de Translation

    /**
     * @brief Translate le point horizontalement.
     * @param a La valeur à ajouter à x.
     */
    void translateX(T a);

    /**
     * @brief Translate le point verticalement.
     * @param b La valeur à ajouter à y.
     */
    void translateY(T b);

    /**
     * @brief Translate le point sur les deux axes.
     * @param a La valeur à ajouter à x.
     * @param b La valeur à ajouter à y.
     */
    void translate(T a, T b);

    /**
     * @brief Sérialise le point 2D pour l'écriture dans un fichier
     * 
     * @return std::string 
     */
    std::string serialize() const;

    /**
     * @brief Désérialise le point 2D pour la lecture d'un fichier
     * 
     * @param input (IN) String à désérialiser
     * @return Point2D<T> 
     */
    static Point2D<T> deserialize(std::string input);

    /**
     * @brief Surcharge de l'opérateur de flux pour l'affichage.
     * @param s Le flux de sortie (ex: std::cout).
     * @param p Le point à afficher.
     * @return Une référence vers le flux de sortie.
     */
    friend std::ostream &operator<< <T>(std::ostream &s, Point2D<T> const &p);
};


// Implémentation des méthodes

template <typename T>
Point2D<T>::Point2D() : x(0), y(0) 
{
    // Initialisation par défaut à 0
}

template <typename T>
Point2D<T>::Point2D(T x, T y)
{
    this->x = x;
    this->y = y;
}

template <typename T>
Point2D<T>::Point2D(Point2D<T> const &p) : x(p.x), y(p.y) 
{
    // Copie effectuée via la liste d'initialisation
}

template <typename T>
T Point2D<T>::getX() const
{
    return this->x;
}

template <typename T>
void Point2D<T>::setX(T x)
{
    this->x = x;
}

template <typename T>
T Point2D<T>::getY() const
{
    return this->y;
}

template <typename T>
void Point2D<T>::setY(T y)
{
    this->y = y;
}

template <typename T>
void Point2D<T>::translateX(T a)
{
    this->x += a;
}

template <typename T>
void Point2D<T>::translateY(T b)
{
    this->y += b;
}

template <typename T>
void Point2D<T>::translate(T a, T b)
{
    this->x += a;
    this->y += b;
}

template <typename T>
std::string Point2D<T>::serialize() const
{
    return std::to_string(this->x) + "," + std::to_string(this->y);
}

template <typename T>
Point2D<T> Point2D<T>::deserialize(std::string input) 
{
    T x, y;
    std::istringstream strstr(input);
    strstr >> x;
    strstr.ignore(1, ",");
    strstr >> y;
    
    return Point2D<T>(x, y);
}

template <typename T>
std::ostream &operator<<(std::ostream &o, Point2D<T> const &p)
{
    o << "x = " << p.getX() << ", y = " << p.getY();
    return o;
}