#pragma once

#include "Parcelle.hpp"
#include "Polygone.hpp"

class ZN : virtual public Parcelle
{
public:
    /* Constructors */
    ZN(int num, std::string prop, Polygone<float> forme);
    ~ZN();
};
