#pragma once

#include <iostream>

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

class ZA : public ZN, public Constructible
{
private:
    TypeCulture typeCulture;

public:
    /* Constructors */
    ZA(int num, std::string prop, Polygone<float> forme, TypeCulture typeCulture, int pourcentageConstructible);
    ~ZA();

    /**
     * @brief Donne le type de culture
     *
     * @return TypeCulture
     */
    TypeCulture getTypeCulture() const;

    /**
     * @brief Test si une surface remplit les conditions
     * pour être constructible
     *
     * @param surface_a_construire
     * @return true : La surface est constructible
     * @return false : La surface n'est pas constructible
     */
    bool constructible(Polygone<float> surface_a_construire);

    friend std::ostream &operator<<(std::ostream &out, ZA const &za);
};
