#pragma once
#include "Bieuthuc.h"

class BieuthucTru : public Bieuthuc
{
public:
	BieuthucTru(int level) : Bieuthuc(level) {
		pheptoan = '-';
	};
	bool kiemtra(float traloi);
	float giatri();
};