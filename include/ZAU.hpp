#pragma once

#include <string>

#include "Constructible.hpp"

class ZAU: public Constructible{
    public:
        float getSurfaceConstructible() const override;
        ZAU(int num, std::string prop, Polygone<float> forme);
        ZAU(const ZAU & zau);  
        ~ZAU();  
};