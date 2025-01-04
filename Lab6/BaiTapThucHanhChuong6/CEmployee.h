#pragma once
#include "Employee.h"
#include <iostream>

using namespace std;

class CEmployee : public Employee
{
private:
	double grossSales;
	double commissionRate;
public:
	CEmployee(const string& first, const string& last, const string& ssn, double sales = 0.0, double rate = 0.0) : Employee(first, last, ssn) {
		setGrossSales(sales);
		setCommissionRate(rate);
	};

	void setGrossSales(double sales);
	double getGrossSales() const { return grossSales; };

	void setCommissionRate(double rate);
	double getCommissionRate() const { return commissionRate; };

	double earnings() override;
	void print() const;
};

