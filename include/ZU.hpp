#pragma once
#include "Constructible.h"

class ZU: public Constructible{
    private:
        float surfaceConstruite;
    public:
        float getSurfaceConstructible() override;
        ZU(int num, string prop, Polygone<int, float> forme, float surfaceConstruite);
        ZU(Parcelle parc, float surfaceConstruite);
        ~ZU();
};