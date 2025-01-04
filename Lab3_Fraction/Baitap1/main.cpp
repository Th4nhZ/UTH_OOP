#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    string filename;
    cin >> filename;
    ifstream file(filename);

    int count;
    file >> count;

    vector<Fraction> fractions;

    for (int i = 0; i < count; i++) {
        int numerator;
        int denominator;
        file >> numerator >> denominator;
        fractions.push_back(Fraction(numerator, denominator));
    }
    file.close();

    Fraction big = fractions[0];
    Fraction small = fractions[0];

    for (int i = 1; i < fractions.size(); i++) {
        if (fractions[i] > big) {
            big = fractions[i];
        }
        else if (fractions[i] < small) {
            small = fractions[i];
        }
    }
    cout << small.getNum() << "/" << small.getDen() << endl;
    cout << big.getNum() << "/" << big.getDen() << endl;
    return 0;
}