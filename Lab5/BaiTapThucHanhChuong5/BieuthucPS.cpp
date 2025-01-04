#include "BieuthucPS.h"

BieuthucPS::BieuthucPS(int level) : Bieuthuc(level)
{
	a.setNum(rand() % (level < 4 ? 10 : 91) + (level < 4 ? 1 : 10));
	a.setDen(rand() % (level < 4 ? 10 : 91) + (level < 4 ? 1 : 10));
	b.setNum(rand() % (level < 4 ? 10 : 91) + (level < 4 ? 1 : 10));
	b.setDen(rand() % (level < 4 ? 10 : 91) + (level < 4 ? 1 : 10));
}

bool BieuthucPS::kiemtra(float traloi)
{
	return abs(traloi - giatri()) < 0.000001f;
}

float BieuthucPS::giatri()
{
	switch (pheptoan) {
	case '+':
		return (float(a.getNum() * b.getDen() + b.getNum() * a.getDen()) / float(a.getDen() * b.getDen()));
		break;
	case '-':
		return (float(a.getNum() * b.getDen() - b.getNum() * a.getDen()) / float(a.getDen() * b.getDen()));
		break;
	case '*':
		return (float(a.getNum() * b.getNum()) / float(a.getDen() * b.getDen()));
		break;
	}
	return 0.0f;
}

ostream& operator<<(ostream& out, BieuthucPS bt)
{
	out << bt.a.getNum() << "/" << bt.a.getDen() << bt.pheptoan << bt.b.getNum() << "/" << bt.b.getDen() << endl;
	return out;
}
