#pragma once

#include <string>

#include "Constructible.hpp"

class ZU: public Constructible{
    private:
        float surfaceConstruite;
    public:
        float getSurfaceConstructible() const override;
        ZU(int num, std::string prop, Polygone<float> forme, float surfaceConstruite);
        ZU(const ZU & zu);
        ~ZU();
};