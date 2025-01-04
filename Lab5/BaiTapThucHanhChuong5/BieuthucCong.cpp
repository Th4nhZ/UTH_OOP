#include "BieuthucCong.h"

bool BieuthucCong::kiemtra(float traloi)
{
    return traloi == giatri();
}

float BieuthucCong::giatri()
{
    return a + b;
}
