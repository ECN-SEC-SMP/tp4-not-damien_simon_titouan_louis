#include "ZU.hpp"
float ZU::getSurfaceConstructible(){
    return getSurface() * getPourcentageConstructible()-surfaceConstruite;
}

//Constructors
ZU::ZU(int num, string prop, Polygone<int, float> forme, float surfaceConstruite){
    Constructible(num, prop, forme); 
    this->surfaceConstruite = surfaceConstruite;
}

ZU::ZU(Parcelle parc, float surfaceConstruite){
    Constructible(parc);
    this->surfaceConstruite = surfaceConstruite;
}