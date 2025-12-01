#pragma once

#include "ZN.hpp"
#include "Constructible.hpp"

enum TypeCulture
{
    BLE,  // blé
    MAIS, // maïs
    CHANVRE,
    VACHE,
    COCHON,
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
