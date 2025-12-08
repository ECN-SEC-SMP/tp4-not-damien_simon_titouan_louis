#pragma once

#include <string>

#include "Polygone.hpp"
#include "Parcelle.hpp"

class Constructible : virtual public Parcelle
{
public:
    Constructible(int num, std::string prop, Polygone<float> forme);
    Constructible( const Constructible& constructible );
    ~Constructible();
    float getSurfaceConstructible() const;
};