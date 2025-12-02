#include "Constructible.hpp"

Constructible::Constructible(int num, std::string prop, Polygone<float> forme) : Parcelle(num, prop, forme) {}
Constructible::Constructible(Parcelle parc) : Parcelle(parc) {}
Constructible::~Constructible() {}