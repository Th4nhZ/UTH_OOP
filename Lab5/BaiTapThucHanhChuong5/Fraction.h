#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Fraction
{
private:
	// Tu so
	int numerator = 0;
	// Mau so
	int denominator = 1;
public:
	Fraction() = default;
	Fraction(int n, int d) : numerator(n), denominator(d) {
		if (d == 0) {
			numerator = 0;
			denominator = 1;
		}
	}
	Fraction(int random);
	friend istream& operator>>(istream& file, Fraction& frac);
	friend ostream& operator<<(ostream& file, Fraction& frac);
	//Ham lay tu va mau
	int getNum() const { return numerator; };
	int getDen() const { return denominator; };
	void setNum(int const& x) { numerator = x; };
	void setDen(int const& x) { denominator = x; };
	//Ham ho tro tinh toan
	int findGCD(int a, int b);
	void simplify();
	//Toan tu 1 ngoi
	Fraction& operator++();
	Fraction& operator++(int);
	Fraction& operator--();
	Fraction& operator--(int);
	//Toan tu 2 ngoi
	Fraction& operator+(Fraction& other);
	Fraction& operator-(Fraction& other);
	Fraction& operator*(Fraction& other);
	Fraction& operator/(Fraction& other);
	//Toan tu so sanh
	bool operator>(Fraction const& other) const;
	bool operator<(Fraction const& other) const;
	bool operator==(Fraction const& other) const;
	bool operator!=(Fraction const& other) const;
};




