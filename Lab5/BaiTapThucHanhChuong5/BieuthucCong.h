#pragma once
#include "Bieuthuc.h"

class BieuthucCong : public Bieuthuc
{
public:
	BieuthucCong(int level) : Bieuthuc(level) {
		pheptoan = '+';
	};
	bool kiemtra(float traloi);
	float giatri();
};

