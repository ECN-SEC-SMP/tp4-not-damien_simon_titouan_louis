#pragma once
#include "Constructible.h"

class ZAU: public Constructible{
    public:
        float getSurfaceConstructible() override;
        ZAU(int num, string prop, Polygone<int, float> forme);
        ZAU(Parcelle parc);
        
};