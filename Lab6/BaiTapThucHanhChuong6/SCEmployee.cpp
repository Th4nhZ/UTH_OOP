#include "SCEmployee.h"

double SCEmployee::earnings()
{
    return SEmployee::earnings() + CEmployee::earnings();
}

void SCEmployee::print() const
{
    cout << "\nSCEmployee";
    Employee::print();
    cout << "\t" << SEmployee::getWeeklySalary();
    cout << "\t\t" << CEmployee::getGrossSales();
    cout << "\t\t" << CEmployee::getCommissionRate();
}
