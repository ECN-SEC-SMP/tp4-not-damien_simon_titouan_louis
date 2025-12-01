#pragma once

#include "Parcelle.hpp"
#include "Polygone.hpp"

class ZN : public Parcelle
{
public:
    ZN(int num, std::string prop, Polygone<float> forme);
    ~ZN();
};
