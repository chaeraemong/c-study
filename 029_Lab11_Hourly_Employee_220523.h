#pragma once
#include "10_HW9_Employee.h"

class HourlyEmployee : public Employee
{
	double wageRate;
	double hours;
public:
	HourlyEmployee(const std::string& theName = "No name yet", const std::string& theSsn = "No number yet", double theWageRate = 0, double theHours = 0)
		:Employee(theName, theSsn), wageRate(theWageRate), hours(theHours)
	{
		std::cout << "HourlyEmployee constructor" << std::endl;
	}
	double getRate() const { return wageRate; }
	double getHours() const { return hours; }
	void setRate(double newWageRate) { wageRate = newWageRate; }
	void setHours(double hoursWorked) { hours = hoursWorked; }
	void printCheck()
	{
		setNetPay(hours * wageRate);

		std::cout << "_________________________________________________________" << std::endl
			<< "Check for " << getName() << std::endl
			<< "The sum of " << getNetPay() << " Dollars" << std::endl
			<< "_________________________________________________________" << std::endl
			<< "Employee Number : " << getSsn() << std::endl
			<< "Hourly Employee. \nHours Worked : " << hours << " Rate : " << wageRate << " Pay : " << getNetPay() << std::endl
			<< "_________________________________________________________" << std::endl;
	}
	~HourlyEmployee()
	{
		std::cout << "~HourlyEmployee destructor" << std::endl;
	}
};
