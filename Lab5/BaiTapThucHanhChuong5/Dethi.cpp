#include "Dethi.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"

#include <algorithm>
#include <random>

Dethi::Dethi(int n1, int n2, int n3, int level)
{
	for (int i = 0; i < n1 + n2 + n3; i++) {
		if (i < n1) // n1 bieu thuc cong
			ds.push_back(BieuthucCong(level));
		else if (i < n1 + n2) // n2 bieu thuc tru + n1 bieu thuc cong truoc do
			ds.push_back(BieuthucTru(level));
		else // n3 con lai bieu thuc nhan
			ds.push_back(BieuthucNhan(level));
	}
	random_shuffle(ds.begin(), ds.end());
}

void Dethi::xuat(ostream& output)
{
	for (Bieuthuc& bt : ds) {
		output << bt << endl;
	}
}

int Dethi::danhgia(istream& input)
{
	int count = 0;
	for (Bieuthuc& bt : ds) {
		float ans;
		input >> ans;
		if (bt.kiemtra(ans))
			count++;
	}
	return count;
}
