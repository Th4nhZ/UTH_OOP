#pragma once
#include "Bieuthuc.h"

using namespace std;

class BieuthucPT : public Bieuthuc
{
private:
    int c, d;
    char pheptoan2, pheptoan3;
public:
    BieuthucPT(int level);
    friend ostream& operator<<(ostream& out, BieuthucPT bt);
    bool kiemtra(float traloi);
    float giatri();
};

