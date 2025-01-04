#include "BieuthucTru.h"

bool BieuthucTru::kiemtra(float traloi)
{
    return traloi == giatri();
}

float BieuthucTru::giatri()
{
    return a - b;
}
