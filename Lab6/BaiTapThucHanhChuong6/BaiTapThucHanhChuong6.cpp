#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Employee.h"
#include "SEmployee.h"
#include "CEmployee.h"
#include "SCEmployee.h"

using namespace std;

static string rand_string() {
    string randomString;
    for (int i = 0; i < 2; ++i) {
        int randomInt = rand() % 26;
        char randomChar = 'A' + randomInt;
        randomString += randomChar;
    }
    return randomString;
}

static float rand_percent() {
    return float(rand() % 99 + 1) / 100;
}

static Employee* create_CEmployee() {
    return new CEmployee(rand_string(), rand_string(), rand_string(), rand_percent(), rand_percent());
}

static Employee* create_SEmployee() {
    return new SEmployee(rand_string(), rand_string(), rand_string(), rand_percent());
}

// Su dung lop cha de tao lop chau ma khong bi loi base class Employee is ambigous
static SEmployee* create_SCEmployee() {
    return new SCEmployee(rand_string(), rand_string(), rand_string(), rand_percent(), rand_percent(), rand_percent());
}

static vector<Employee*> generate_employees() {
    vector<Employee*> employees;
    for (int i = 0; i < 30; i++) {
        if (i < 10)
            employees.push_back(create_CEmployee());
        else if (i < 20)
            employees.push_back(create_SEmployee());
        else
            employees.push_back(create_SCEmployee());
    }
    return employees;
}

static void print_employees_list(vector<Employee*> const& employees) {

    cout << "\nType\t\tFirst Name\tLast Name\tSSN\tWeekly Salary\tGross Sale\tCommission Rate\t\tEarnings\n";
    for (auto const& employee : employees) {
        employee->print();
        cout << "\t\t\t" << employee->earnings();
    }

}

static bool compare_earnings(Employee* e1, Employee* e2) {
    return e1->earnings() > e2->earnings();
}

static void sort_by_earnings(vector<Employee*>& employees) {
    sort(employees.begin(), employees.end(), compare_earnings);
}

int main()
{
    srand(time(0));
    cout << "=====Nguyen Duy Thanh - 2251150076 - BaiTapThucHanhChuong6=====\n";
    cout << "=====================Danh Sach Nhan Vien=======================\n";
    auto employees = generate_employees();
    print_employees_list(employees);
    cout << "\n\n==============Danh Sach Nhan Vien Sau Khi Sap Xep==============\n";
    sort_by_earnings(employees);
    print_employees_list(employees);
}