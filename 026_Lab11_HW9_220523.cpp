#include <iostream>
#include "09_HW9_Person.h"
#include "10_HW9_Employee.h"
#include "11_HW9_Hourly_Employee.h"
#include "12_HW9_Salaried_Employee.h"
using namespace std;

int main()
{
	HourlyEmployee joe;
	joe.setName("Mighty Joe");
	joe.setSsn("123-45-6789");
	joe.setRate(20.50);
	joe.setHours(40);
	joe.printCheck();

	SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500.50);
	boss.printCheck();

	return 0;
}

/*실행예는 다음과 같습니다.

Person constructor
Employee constructor
HourlyEmployee constructor
________________________________________________
Check for Mighty Joe
The sum of 820 Dollars
________________________________________________
Employee Number : 123 - 45 - 6789
Hourly Employee.
Hours worked : 40 Rate : 20.5 Pay : 820
________________________________________________
Person constructor
Employee constructor
SalariedEmployee constructor
________________________________________________
Check for Mr.Big Shot
The sum of 10500.5 Dollars
________________________________________________
Employee Number : 987 - 65 - 4321
Salaried Employee.Regular Pay : 10500.5
________________________________________________
~SalariedEmployee destructor
~Employee destructor
~Person destructor
~HourlyEmployee destructor
~Employee destructor
~Person destructor
*/
