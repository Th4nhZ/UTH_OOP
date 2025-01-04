#pragma once

#include "Bieuthuc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"
#include "BieuthucPT.h"
#include "BieuthucPS.h"


class Game
{
private:
    Bieuthuc* bt;
    int level = 1;
    int streak = 0;
    int diem = 0;
protected:
    virtual Bieuthuc* createBT(int lv) const {
        return new Bieuthuc(lv);
    }
public:
    Game() = default;
    void start() {
        int lost = 0;
        while (lost <= 3) {
            bt = createBT(level);
            cout << "Level: \t\t" << level << endl;
            cout << "Diem hien co: \t" << diem << endl;
            cout << *bt << endl;
            float traloi;
            cin >> traloi;
            cin.ignore();
            if (bt->kiemtra(traloi)) {
                cout << "DUNG!\n\n";
                diem++;
                streak++;
                if (streak == 3) {
                    level == 5 ? level = 5 : level++;
                    streak = 0;
                }
            }
            else {
                cout << "SAI!\n\n";
                diem--;
                streak = 0;
                if (level > 1) {
                    level--;
                }
                lost++;
            }
            // Xoa bt di de giai phong o nho
            delete bt;
        }
        cout << "Ban da thua do tra loi sai qua 3 lan." << endl;
        cout << "Diem cua ban: " << diem << endl;
    }
};

class GameBTCong : public Game
{
protected:
    BieuthucCong* createBT(int lv) const override {
        return new BieuthucCong(lv);
    }
public:
    GameBTCong() : Game() {};
};

class GameBTTru : public Game
{
protected:
    BieuthucTru* createBT(int lv) const override {
        return new BieuthucTru(lv);
    }
public:
    GameBTTru() : Game() {};
};

class GameBTNhan : public Game
{
protected:
    BieuthucNhan* createBT(int lv) const override {
        return new BieuthucNhan(lv);
    }
public:
    GameBTNhan() : Game() {};
};

class GameBTPT : public Game
{
protected:
    BieuthucPT* createBT(int lv) const override {
        return new BieuthucPT(lv);
    }
public:
    GameBTPT() : Game() {};
};

class GameBTPS : public Game
{
protected:
    BieuthucPS* createBT(int lv) const override {
        return new BieuthucPS(lv);
    }
public:
    GameBTPS() : Game() {};
};