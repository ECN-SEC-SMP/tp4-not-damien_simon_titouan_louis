#pragma once

#include "Parcelle.hpp"
#include "Polygone.hpp"

class ZN : public Parcelle
{
public:
    /* Constructors */
    ZN(int num, std::string prop, Polygone<float> forme);
    ~ZN();
};
