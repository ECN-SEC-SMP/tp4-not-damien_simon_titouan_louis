#include <iostream>
#pragma once

template <typename T>
class Point2D;

template <typename T>
std::ostream &operator<<(std::ostream &, Point2D<T> const &p);

template <typename T>
class Point2D
{
protected:
    T x;
    T y;

public:
    Point2D(T x, T y);         // constructeur avec les deux parametres
    Point2D(Point2D const &p); // Recopie de p
    Point2D();                 // constructeur

    // Setteurs et Guetteurs
    T getX() const;
    void setX(T x);
    T getY() const;
    void setY(T y);

    // Translation
    void translateX(T a);
    void translateY(T b);
    void translate(T a, T b);

    // opérateur d'affichage
    friend std::ostream &operator<< <T>(std::ostream &s, Point<T> const &p);
};

template <typename T>
Point2D<T>::Point2D(T x, T y)
{
    this->x = x;
    this->y = y;
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
std::ostream &operator<<(std::ostream &o, Point2D<T> const &p)
{
    o << "x = " << p.getX() << ", y = " << p.getY();
    return o;
}

template <typename T>
Point2D<T>::Point2D(Point2D<T> const &p) : x(p.x), y(p.y) {}