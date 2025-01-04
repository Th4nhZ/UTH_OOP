#include "BieuthucPT.h"
#include <ctime>
#include <cstdlib>

BieuthucPT::BieuthucPT(int level) : Bieuthuc(level)
{
	a = rand() % (level < 4 ? 10 : 91) + (level < 4 ? 1 : 10);
	b = rand() % (level < 4 ? 10 : 91) + (level < 4 ? 1 : 10);
	c = rand() % (level < 4 ? 10 : 91) + (level < 4 ? 1 : 10);
	d = rand() % (level < 4 ? 10 : 91) + (level < 4 ? 1 : 10);
	string _op = "+-*";
	if (level == 1) {
		pheptoan = pheptoan2 = pheptoan3 = _op[0];
	}
	else if (level == 2 || level == 4) {
		pheptoan = _op[rand() % 2];
		pheptoan2 = _op[rand() % 2];
		pheptoan3 = _op[rand() % 2];

	}
	else if (level == 3 || level == 5) {
		pheptoan = _op[rand() % 3];
		pheptoan2 = _op[rand() % 3];
		pheptoan3 = _op[rand() % 3];
	}
}

bool BieuthucPT::kiemtra(float traloi)
{
	return traloi == giatri();
}

float BieuthucPT::giatri()
{
	float result, result1;
	switch (pheptoan) // bt1
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	default:
		break;
	}
	switch (pheptoan3) // bt2
	{
	case '+':
		result1 = c + d;
		break;
	case '-':
		result1 = c - d;
		break;
	case '*':
		result1 = c * d;
		break;
	default:
		break;
	}
	switch (pheptoan2)
	{
	case '+':
		result += result1;
		break;
	case '-':
		result -= result1;
		break;
	case '*':
		result *= result1;
		break;
	default:
		break;
	}
	return result;
}

ostream& operator<<(ostream& out, BieuthucPT bt)
{
	out << "(" << bt.a << bt.pheptoan << bt.b << ")" << bt.pheptoan2 << "(" << bt.c << bt.pheptoan3 << bt.d << ") = ?";
	return out;
}