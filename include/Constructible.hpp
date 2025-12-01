#pragma once

#include <string>

#include "Polygone.hpp"
#include "Parcelle.hpp"

class Constructible: public Parcelle {
    public:
        Constructible(int num, std::string prop, Polygone<float> forme);
        Constructible(Parcelle parc);
        ~Constructible();
        virtual float getSurfaceConstructible() const = 0;
};