#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "Dethi.h"

#include "Game.h"

using namespace std;

class Menu
{
public:
    vector<string> luaChon;
    void themLuaChon(string const& luachon){
        luaChon.push_back(luachon);
    }
    void xuat() {
        cout << "=========== 2251150076 - Nguyen Duy Thanh - Thuc Hanh Chuong 5 =============" << endl;
        for (int i = 0; i < luaChon.size(); i++) {
            cout << i + 1 << ".\t" << luaChon[i] << endl;
        }
    }
};

int main()
{
    srand(time(0));
    Menu menu;
    menu.themLuaChon("Che do thuong\t\ta # b");
    menu.themLuaChon("Chi bieu thuc cong\ta + b");
    menu.themLuaChon("Chi bieu thuc tru\ta - b");
    menu.themLuaChon("Chi bieu thuc nhan\ta * b");
    menu.themLuaChon("Bieu thuc phuc tap\t(a # b) # (c # d)");
    menu.themLuaChon("Bieu thuc phan so\ta/b # c/d");
    menu.themLuaChon("Che do de thi");
    menu.themLuaChon("Thoat chuong trinh");

    bool running = true;
    while (running) {
        menu.xuat();
        int luachon = 0;
        do {
            cout << "\nVui long nhap lua chon:\n> ";
            cin >> luachon;
            cin.ignore();
        } while ((luachon < 1) || (luachon > menu.luaChon.size() + 1));

        if (luachon == 1) {
            Game game;
            game.start();
        }
        else if (luachon == 2) {
            GameBTCong gamebtc;
            gamebtc.start();
        }
        else if (luachon == 3) {
            GameBTTru gamebtt;
            gamebtt.start();
        }
        else if (luachon == 4) {
            GameBTNhan gamebtn;
            gamebtn.start();
        }
        else if (luachon == 5) {
            GameBTPT gamebtpt;
            gamebtpt.start();
        }
        else if (luachon == 6) {
            GameBTPS gamebtps;
            gamebtps.start();
        }
        else if (luachon == 7) {
            int level = 1;
            do {
                cout << "\nVui long nhap level:\n> ";
                cin >> level;
                cin.ignore();
            } while (level < 1 || level > 5);
            int n1, n2, n3;
            cout << "Vui long nhap lan luot so luong bieu thuc cong, tru, nhan:\n> ";
            cin >> n1 >> n2 >> n3;
            Dethi dethi(n1, n2, n3, level);
            dethi.xuat();
            dethi.danhgia();
        }
        else running = false;
    }
}