#include <iostream>

#pragma once

using namespace std;

class Bieuthuc
{
protected:
	int a; // Toan hang thu nhat
	int b; // Toan hang thu hai
	char pheptoan = ' '; // Phep toan + ; - ; *
public:
	// Tao bieu thuc ngau nhien theo quy luat
	Bieuthuc(int level);
	// Xuat bieu thuc theo dang a # b
	friend ostream& operator<<(ostream& out, Bieuthuc& bt);
	// Nhan cau tra loi va kiem tra dap an
	bool kiemtra(float traloi);
	// Tinh gia tri bieu thuc
	float giatri();
};

