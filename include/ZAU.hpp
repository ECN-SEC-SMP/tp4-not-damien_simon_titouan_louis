#pragma once

#include <string>

#include "Constructible.hpp"

class ZAU: public Constructible{
    public:
        ZAU(int num, std::string prop, Polygone<float> forme, float pourcentageConstructible);
        ZAU(const ZAU & zau);  
        ~ZAU();  
};