#include "CauhoiTN.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


string CauhoiTN::getNoiDung()
{
	return _noiDung;
}

string CauhoiTN::getDapAnA()
{
	return _dapAnA;
}

string CauhoiTN::getDapAnB()
{
	return _dapAnB;
}

// Nhap noi dung cau hoi va dap an
void CauhoiTN::nhap()
{
	cout << "\nNhap noi dung cau hoi: \n> ";
	getline(cin, _noiDung);
	cout << "Nhap dap an A: \n> ";
	getline(cin, _dapAnA);
	cout << "Nhap dap an B: \n> ";
	getline(cin, _dapAnB);
	cout << "Nhap dap an dung (A/B): \n> ";
	cin >> _dapAnDung;
	cin.ignore();

}

// Doc noi dung cau hoi va dap an tu file
void CauhoiTN::docFile(ifstream& file)
{
	getline(file, _noiDung);
	getline(file, _dapAnA);
	getline(file, _dapAnB);
	file >> _dapAnDung;
	file.ignore();
	
}

// Ghi cau hoi va dap an vao file
void CauhoiTN::ghiFile(ofstream& file)
{
	file << _noiDung << endl;
	file << _dapAnA << endl;
	file << _dapAnB << endl;
	file << _dapAnDung << endl;
}

// Hien thi cau hoi cho nguoi kiem tra
bool CauhoiTN::kiemTra() 
{	
	cout << "Cau hoi: " << _noiDung << endl;
	cout << "A. " << _dapAnA << endl;
	cout << "B. " << _dapAnB << endl;
	char dapAn;
	cout << "Nhap dap an cua ban (A/B): \n> ";
	cin >> dapAn;
	cin.ignore();
	// Ham toupper de dam bao dap an nhap vao se duoc chuyen sang chu hoa
	return (toupper(dapAn) == _dapAnDung);
}

// Xuat cau hoi va dap an ra man hinh
void CauhoiTN::xuat()
{
	cout << _noiDung << endl;
	cout << "A. " << _dapAnA << endl;
	cout << "B. " << _dapAnB << endl;
	cout << "Dap an dung: " << _dapAnDung << endl;
}

// Kiem tra xem hai cau hoi co trung nhau khong
bool giongNhau(CauhoiTN cau1, CauhoiTN cau2)
{
	return (
		cau1._noiDung   == cau2._noiDung   && 
		cau1._dapAnA    == cau2._dapAnA    &&
		cau1._dapAnB    == cau2._dapAnB    &&
		cau1._dapAnDung == cau2._dapAnDung
		);
}
