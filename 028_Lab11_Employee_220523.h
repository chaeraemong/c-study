#pragma once
#include <string>
#include <iostream>
#include "09_HW9_Person.h"

class Employee : public Person
{
protected:
	std::string ssn;
private:
	double netPay;
public:
	Employee(const std::string& theName = "No name yet", const std::string& theSsn = "No number yet")
		:Person(theName), ssn(theSsn), netPay(0)
	{
		std::cout << "Employee constructor" << std::endl;
	}
	std::string getSsn() const { return ssn; }
	double getNetPay() const { return netPay; }
	void setSsn(const std::string& newSsn) { ssn = newSsn; }
	void setNetPay(double newNetPay) { netPay = newNetPay; }
	void printCheck() const;
	~Employee()
	{
		std::cout << "~Employee destructor" << std::endl;
	}
};

void Employee::printCheck() const
{
	std::cout << std::endl << "ERROR: printCheck FUNCTION CALLED FOR AN" << std::endl
		<< "UNDIFFERENTIATED EMPLOYEE. Aborting the program." << std::endl
		<< "Check with the author of the program about this bug." << std::endl;
	exit(1);
}
