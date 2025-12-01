#pragma once
#include "Constructible.h"

class ZU: public Constructible{
    public:
        float getSurfaceConstructible() override;
        ZU(int num, string prop, Polygone<int, float> forme);
        ZU(Parcelle parc);
};