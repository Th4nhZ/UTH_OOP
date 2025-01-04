#pragma once
#include "SEmployee.h"
#include "CEmployee.h"
#include <iostream>

using namespace std;

class SCEmployee : public SEmployee, public CEmployee
{
public:
	SCEmployee(const string& first, const string& last, const string& ssn, double salary, double sales = 0.0, double rate = 0.0)
		: SEmployee(first, last, ssn, salary), CEmployee(first, last, ssn, sales, rate) {};

	double earnings() final;
	void print() const;
};

