#pragma once
#include <string>
#include <fstream>

using namespace std;

class CauhoiTN
{
private:
	string _noiDung;
	string _dapAnA;
	string _dapAnB;
	char _dapAnDung;

public:
	string getNoiDung();
	string getDapAnA();
	string getDapAnB();
	void nhap();
	void docFile(ifstream& file);
	void ghiFile(ofstream& file);
	bool kiemTra();
	void xuat();
	friend bool giongNhau(CauhoiTN cau1, CauhoiTN cau2);
};

