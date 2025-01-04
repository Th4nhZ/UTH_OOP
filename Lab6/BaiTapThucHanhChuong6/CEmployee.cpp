#include "CEmployee.h"

void CEmployee::setGrossSales(double sales)
{
	if (sales >= 0.0) {
		grossSales = sales;
	}
	else {
		throw invalid_argument("Gross sales must be >= 0.0");
	}
}

void CEmployee::setCommissionRate(double rate)
{
	if (rate > 0.0 && rate < 1.0) {
		commissionRate = rate;
	}
	else {
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
	}
}

double CEmployee::earnings()
{
	return getCommissionRate() * getGrossSales();
}

void CEmployee::print() const
{
	cout << "\nCEmployee";
	Employee::print();
	cout << "\t" << "-\t\t" << getGrossSales();
	cout << "\t\t" << getCommissionRate();
}
