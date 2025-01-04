#include <iostream>
#include <fstream>
#include <vector>

#include "CauhoiTN.h"


// Dung de xoa man hinh
#ifdef _WIN32
constexpr auto CLEAR_COMMAND = "cls";
#else
constexpr auto CLEAR_COMMAND = "clear";
#endif

using namespace std;

static void inMenu()
{
    system(CLEAR_COMMAND);
    cout << "==== 2251150076 - Nguyen Duy Thanh - Bai Tap 2 ====\n";
    cout << "= Chuong trinh thi trac nghiem =\n";
    cout << "1. Tao de thi trac nghiem.\n";
    cout << "2. Thi trac nghiem.\n";
    cout << "3. Kiem tra khoang trang thua cua de thi da co va sua loi.\n";
    cout << "4. Thoat chuong trinh.\n\n";
}

static void enterToContinue()
{
    cout << "Nhan Enter de tiep tuc...";
    cin.get();
}

int main()
{
    bool running = true;
    while (running)
    {
        if (running == false) break;


        // TODO: lam sao de khong hardcode doan options
        vector <int> options = { 1, 2, 3, 4 };
        int option;
        bool valid = false; // Flag de danh dau lua chon phu hop
        inMenu();
        do
        {
            cout << "Chon tuy chon: \n> ";
            cin >> option;
            cin.ignore();
            for (int validOption : options)
                if (option == validOption)
                    valid = true;
        } while (!valid);

        switch (option)
        {
            case 1: // Tao de thi
            {
                ofstream file("dethi.TTN");
                int n;
                cout << "Nhap so luong cau hoi: \n> ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++)
                {
                    system(CLEAR_COMMAND);
                    CauhoiTN cauHoi;
                    cauHoi.nhap();
                    cauHoi.ghiFile(file);
                }
                file.close();
                cout << "Tao de thi thanh cong!\n\n";
                enterToContinue();
                break;
            }
            case 2: // Tien hanh thi trac nghiem
            {
                ifstream file("dethi.TTN");
                if (!file.is_open())
                {
                    cout << "Loi: De thi khong ton tai!\n\n";
                    break;
                }
                int diem = 0, soCauHoi = 0;

                while (!file.eof())
                {
                    CauhoiTN cauHoi;
                    cout << endl;
                    cauHoi.docFile(file);
                    // Vi luc nhap cau hoi, ki tu cuoi cung la ki tu xuong dong
                    // Nen phai loai bo cau hoi cuoi cung - cau hoi trong
                    if (cauHoi.getNoiDung().empty())
                        continue;
                    if (cauHoi.kiemTra())
                        diem++;
                    soCauHoi++;
                }
                file.close();

                cout << "Ban tra loi dung " << diem << "/" << soCauHoi << " cau hoi.\n\n";
                enterToContinue();
                break;
            }
            case 3: // Kiem tra khoang trang thua va xoa chung
            {
                ifstream fileIn("dethi.TTN");
                if (!fileIn.is_open())
                {
                    cout << "Loi: De thi khong ton tai!\n\n";
                    break;
                }
                string line, result = "";
                while (getline(fileIn, line))
                {
                    bool lastCharIsSpace = true; // Flag de biet ki tu truoc co la khoang trang khong

                    for (int i = 0; i < line.size(); i++)
                    {
                        if (!isspace(line[i]) || (isspace(line[i]) && lastCharIsSpace == false))
                        {
                            result += line[i];
                            lastCharIsSpace = false;
                        }
                        else lastCharIsSpace = true;
                    }
                    result += "\n";
                }

                ofstream fileOut("dethi.TTN");
                fileOut << result;
                fileOut.close();
                
                cout << "Da xoa cac khoang trang khong can thiet va ghi lai de bai.\n\n";
                enterToContinue();
                break;
            }
            case 4: // Thoat chuong trinh
            {
                running = false;
                break;
            }
        }
    }
    
}