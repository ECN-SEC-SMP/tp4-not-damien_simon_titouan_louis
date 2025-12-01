#pragma once
#include "Parcelle.hpp"

class Constructible: public Parcelle {
    public:
        virtual float getSurfaceConstructible() = 0;
};