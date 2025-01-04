#pragma once
#include <vector>
#include "Bieuthuc.h"

class Dethi {
private:
    // Chua danh sach cau hoi
    vector<Bieuthuc> ds;
public:
    // n1: +      n2: -      n3: *
    Dethi(int n1, int n2, int n3, int level=1);
    // Xuat ds cau hoi ra man hinh
    vector<Bieuthuc> danhsach() const { return ds; }

    void xuat(ostream& output=cout);
    // Kiem tra input nguoi dung va cho diem
    int danhgia(istream& input=cin);
};

