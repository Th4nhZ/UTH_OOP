#pragma once
#include "Employee.h"
#include <iostream>


using namespace std;

class SEmployee : public Employee
{
private:
	double weeklySalary;
public:
	SEmployee(const string& first, const string& last, const string& ssn, double salary) : Employee(first, last, ssn) { setWeeklySalary(salary); };

	void setWeeklySalary(double salary);
	double getWeeklySalary() const { return weeklySalary; };

	double earnings() override;
	void print() const;
};

