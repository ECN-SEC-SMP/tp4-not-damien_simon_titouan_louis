#include "ZU.hpp"

//Constructors
ZU::ZU(int num, std::string prop, Polygone<float> forme, float surfaceConstruite)
: Constructible(num, prop, forme), surfaceConstruite(surfaceConstruite) {}

ZU::ZU(const ZU & zu)
: Constructible(zu.numero, zu.proprietaire, zu.forme), surfaceConstruite(zu.surfaceConstruite) {}

ZU::~ZU() = default;

