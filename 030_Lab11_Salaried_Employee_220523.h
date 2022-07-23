#pragma once
#include "10_HW9_Employee.h"

class SalariedEmployee : public Employee
{
	double salary;
public:
	SalariedEmployee(const std::string& theName = "No name yet", const std::string& theSsn = "No number yet", double theWeeklySalary = 0)
		:Employee(theName, theSsn), salary(theWeeklySalary)
	{
		std::cout << "SalariedEmployee constructor" << std::endl;
	}
	double getSalary() const { return salary; }
	void setSalary(double newSalary) { salary = newSalary; }
	void printCheck()
	{
		setNetPay(salary);

		std::cout << "_________________________________________________________" << std::endl
			<< "Check for " << getName() << std::endl
			<< "The sum of " << getNetPay() << " Dollars" << std::endl
			<< "_________________________________________________________" << std::endl
			<< "Employee Number : " << getSsn() << std::endl
			<< "Salaried Employee. Regular pay : " << salary << std::endl
			<< "_________________________________________________________" << std::endl;
	}
	~SalariedEmployee()
	{
		std::cout << "~SalariedEmployee destructor" << std::endl;
	}
};
