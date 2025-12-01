#pragma once

#include "ZN.hpp"
#include "Constructible.hpp"

enum TypeCulture
{
    Blé,
    Maïs,
    Chanvre,
    Vache,
    Cochon,
};

class ZA : public ZN, Constructible
{
private:
    TypeCulture typeCulture;

public:
    ZA(TypeCulture typeCulture);
    ~ZA();

    TypeCulture getTypeCulture();
};
