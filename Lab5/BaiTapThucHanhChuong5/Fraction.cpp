#include "Fraction.h"
#include "Fraction.h"
#include "Fraction.h"

istream& operator>>(istream& file, Fraction& frac)
{
    file >> frac.numerator >> frac.denominator;
    return file;
}

ostream& operator<<(ostream& file, Fraction& frac)
{
    file << frac.numerator << "/" << frac.denominator;
    return file;
}

Fraction::Fraction(int n)
{
    numerator = rand() % n + 1;
    denominator = n;
}

int Fraction::findGCD(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::simplify()
{
    int gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

Fraction& Fraction::operator++()
{
    numerator += denominator;
    return *this;
}

Fraction& Fraction::operator++(int)
{
    Fraction *temp = new Fraction(*this);
    ++(*this);
    return *temp;
}

Fraction& Fraction::operator--()
{
    numerator -= denominator;
    return *this;
}

Fraction& Fraction::operator--(int)
{
    Fraction* temp = new Fraction(*this);
    --(*this);
    return *temp;
}

Fraction& Fraction::operator+(Fraction& other)
{
    Fraction* result = new Fraction(
        this->numerator * other.denominator + this->denominator * other.numerator,
        this->denominator * other.denominator
    );
    result->simplify();
    return *result;
}

Fraction& Fraction::operator-(Fraction& other)
{
    Fraction* result = new Fraction(
        this->numerator * other.denominator - this->denominator * other.numerator,
        this->denominator * other.denominator
    );
    result->simplify();
    return *result;
}

Fraction& Fraction::operator*(Fraction& other)
{
    Fraction* result = new Fraction(
        this->numerator * other.numerator,
        this->denominator * other.denominator
    );
    result->simplify();
    return *result;
}

Fraction& Fraction::operator/(Fraction& other)
{
    Fraction* result = new Fraction(
        this->numerator * other.denominator,
        this->denominator * other.numerator
    );
    result->simplify();
    return *result;
}

bool Fraction::operator>(Fraction const& other) const
{
    return (numerator / denominator > other.numerator / other.denominator);
}

bool Fraction::operator<(Fraction const& other) const
{
    return (numerator / denominator < other.numerator / other.denominator);
}

bool Fraction::operator==(Fraction const& other) const
{
    return (numerator * other.denominator == denominator * other.numerator);
}

bool Fraction::operator!=(Fraction const& other) const
{
    return (numerator * other.denominator != denominator * other.numerator);
}
