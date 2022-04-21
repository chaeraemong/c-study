#include <iostream>
using namespace std;

class DayOfYear
{
public:
	DayOfYear(int monthValue = 1, int dayValue = 1) :month(monthValue), day(dayValue) { testDate(); }
	void input();
	void output();
	int getMonthNumber() { return month; }
	int getDayNumber() { return day; }
private:
	int month;
	int day;
	void testDate();
};

class Holiday
{
public:
	Holiday(int month, int day, bool theEnforcement) :date(month, day), parkingEnforcement(theEnforcement) { }
	void output2();
private:
	DayOfYear date;
	bool parkingEnforcement;
};

class Counter
{
public:
	Counter() : cnt(0) {}
	int getCnt() { ++cnt; return cnt; }
	static int getStaticCnt() { ++static_cnt; return static_cnt; }
private:
	int cnt;
	static int static_cnt;
};

bool compareDayOfYear(DayOfYear& d1, DayOfYear& d2)
{
	return (d1.getDayNumber() == d2.getDayNumber()) && (d1.getMonthNumber() == d2.getMonthNumber());
}

int main()
{
	DayOfYear date1(2, 21), date2(5), date3;

	cout << "Initialized dates : " << endl;
	date1.output();
	date2.output();
	date3.output();

	date1 = DayOfYear(10, 31);
	cout << "date1 reset to the following : \n";
	date1.output(); cout << endl;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Holiday h(2, 14, true);
	cout << "Testing the class Holiday." << endl;
	h.output2();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	DayOfYear today, birthday(3, 21);
	cout << "Enter today`s date : " << endl;
	today.input();

	cout << "Today`s date is ";
	today.output();

	cout << "Your birthday`s date is ";
	birthday.output();

	if (compareDayOfYear(today, birthday))
		cout << "Happy birthday!" << endl;
	else
		cout << "Happy Unbirthday!" << endl << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Counter A, B, C;
	cout << "  " << Counter::getStaticCnt() << endl;
	cout << A.getCnt() << " " << A.getStaticCnt() << endl;
	cout << B.getCnt() << " " << B.getStaticCnt() << endl;
	cout << C.getCnt() << " " << C.getStaticCnt() << endl;
	cout << "  " << Counter::getStaticCnt() << endl;

	return 0;
}

void DayOfYear::input()
{
	cout << "Enter the month as a number : ";
	cin >> month;
	cout << "Enter the day of the month : ";
	cin >> day;

	testDate();
}

void DayOfYear::output()
{
	switch (month)
	{
	case 1:
		cout << "January "; break;
	case 2:
		cout << "Febuary "; break;
	case 3:
		cout << "March "; break;
	case 4:
		cout << "April "; break;
	case 5:
		cout << "May "; break;
	case 6:
		cout << "June "; break;
	case 7:
		cout << "July "; break;
	case 8:
		cout << "August "; break;
	case 9:
		cout << "September "; break;
	case 10:
		cout << "October "; break;
	case 11:
		cout << "November "; break;
	case 12:
		cout << "December "; break;
	default:
		cout << "Error in DayOfYear::output()";
	}
	cout << day << endl;
}

void DayOfYear::testDate()
{
	if ((month < 1) || (month > 12))
	{
		cout << "Illegal month value!" << endl;
		exit(1);
	}
	if ((day < 1) || (day > 31))
	{
		cout << "Illegal day value!" << endl;
		exit(1);
	}
}

void Holiday::output2()
{
	date.output();
	cout << endl;
	if (parkingEnforcement)
		cout << "Parking laws will be enforced." << endl;
	else
		cout << "Parking laws will not be enforced." << endl;
}

int Counter::static_cnt = 0;