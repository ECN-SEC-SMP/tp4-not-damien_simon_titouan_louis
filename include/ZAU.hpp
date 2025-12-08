#pragma once

#include <string>

#include "Constructible.hpp"

class ZAU: public Constructible{
    public:
        ZAU(int num, std::string prop, Polygone<float> forme);
        ZAU(const ZAU & zau);  
        ~ZAU();  

        float getSurfaceConstructible() const override; 
};