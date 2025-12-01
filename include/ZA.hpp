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
    /* Constructors */
    ZA(int num, std::string prop, Polygone<float> forme, TypeCulture typeCulture);
    ~ZA();

    /**
     * @brief Donne le type de culture
     *
     * @return TypeCulture
     */
    TypeCulture getTypeCulture();
};
