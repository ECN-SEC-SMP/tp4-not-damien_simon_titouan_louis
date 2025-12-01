#include "ZAU.hpp"
float ZAU::getSurfaceConstructible(){
    return getSurface() * getPourcentageConstructible();
}

//Constructors
ZAU::ZAU(int num, string prop, Polygone<int, float> forme){
    Constructible(num, prop, forme); 
}

ZAU::ZAU(Parcelle parc){
    Constructible(parc);
}
ZAU::~ZAU(){
    ~Constructible();
}