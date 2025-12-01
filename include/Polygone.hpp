#pragma once
#include <iostream>
#include <vector>
#include "Point2D.hpp"

template<typename T>
class Polygone;

template<typename T>
std::ostream& operator<<(std::ostream& os, Polygone<T> const& p);

template<typename T>
class Polygone {
private:
    std::vector< Point2D<T> > sommets;

public:
    Polygone() {}// Constructeur par défaut
    Polygone(std::vector< Point2D<T> > const& listeSommets)// Constructeur avec liste de sommets
        : sommets(listeSommets) {}

    // Setteurs et Getters
    std::vector< Point2D<T> > getSommets() const; 
    void setSommets(std::vector< Point2D<T> > const& listeSommets);
    void addSommet(Point2D<T> const& p); 

    // Translation
    void translate(T x, T y);

    virtual void afficher(std::ostream& os) const;

    friend std::ostream& operator<< <T>(std::ostream& os, Polygone<T> const& p);
};


template<typename T>
std::vector< Point2D<T> > Polygone<T>::getSommets() const {
    return this->sommets;
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
    for (auto& p : this->sommets) {
        p.translate(x, y); 
    }
}


template<typename T>
void Polygone<T>::afficher(std::ostream& os) const {
    os << "Polygone [";
    for (size_t i = 0; i < sommets.size(); ++i) {
        os << sommets[i]; 
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