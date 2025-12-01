#include <iostream>
#include <vector>
#pragma once
#include "Point2D.hpp"

template<typename T>
class Polygone;

template<typename T>
std::ostream& operator<<(std::ostream &,Polygone<T> const& p);

template<typename T>
class Polygone {
    private:

        vector< Point2D<T> > sommets;

    public:
        Polygone(){}// constructeur
        Polygone(vector< Point2D<T> > const& listeSommets){}

        // Setteurs et Guetteurs
        vector< Point2D<T> > getSommets();
        void setSommets(vector<Point2D<T>> listeSommets);
        void addSommets(Point2D<T>);

        // Translation
        void translate(T x, T y);

    
        virtual void afficher(std::ostream& os);

        // Déclaration de l'opérateur << comme fonction amie
        friend std::ostream& operator<< <T>(std::ostream& os, Polygone<T> const& f);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Polygone<T> const& f);