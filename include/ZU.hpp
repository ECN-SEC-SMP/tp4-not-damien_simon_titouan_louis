#pragma once

#include <string>

#include "Constructible.hpp"

class ZU: public Constructible{
    private:
        float surfaceConstruite;
    public:
    ZU(int num, std::string prop, Polygone<float> forme, float surfaceConstruite, float pourcentageConstructible);
    ZU(const ZU & zu);
    ~ZU();

    float getSurfaceConstructible() const ;
};