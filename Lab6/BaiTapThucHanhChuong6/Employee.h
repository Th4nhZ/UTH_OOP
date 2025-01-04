#pragma once
#include <string>
#include <iostream>

using namespace std;


class Employee
{
private:
	string firstName;
	string lastName;
	string socialSecurityNumber;

public:
	Employee(const string& first, const string& last, const string& ssn) : firstName(first), lastName(last), socialSecurityNumber(ssn) {};

	void setFirstName(const string& first) { firstName = first; };
	string getFirstName() const { return firstName; };

	void setLastName(const string& last) { lastName = last; };
	string getLastName() const { return lastName; };

	void setSSN(const string& ssn) { socialSecurityNumber = ssn; };
	string getSSN() const { return socialSecurityNumber; };

	virtual void print() const {
		cout << "\t" << getFirstName() << "\t\t" << getLastName() << "\t\t" << getSSN();
	};

	virtual double earnings() = 0;
};

