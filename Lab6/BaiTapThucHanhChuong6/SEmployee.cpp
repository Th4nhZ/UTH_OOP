#include "SEmployee.h"

void SEmployee::setWeeklySalary(double salary)
{
	if (salary >= 0.0) {
		weeklySalary = salary;
	}
	else {
		throw invalid_argument("Weekly salary must be >= 0.0");
	}
}

double SEmployee::earnings()
{
	return getWeeklySalary();
}

void SEmployee::print() const
{
	cout << "\nSEmployee";
	Employee::print();
	cout << "\t" << getWeeklySalary() << "\t\t" << "-" << "\t\t" << "-";
}
