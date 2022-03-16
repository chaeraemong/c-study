#include <iostream>
using namespace std;

class DayOfYear
{
public:
    void input();
    void output();
    void set(int NewMonth, int NewDay);
    int getMonthNumber();
    int getDayNumber();
private:
    int month;
    int day;
    void testDate();
};

bool compareDayOfYear(DayOfYear& D1, DayOfYear& D2);

int main()
{
    DayOfYear today{};
    cout << "Enter today`s date: " << endl;
    today.input();
    cout << "Today`s date is ";
    today.output();
    cout << endl << endl;

    DayOfYear birthday{};
    cout << "Enter birthday`s date: " << endl;
    birthday.input();
    cout << "Birthday`s date is ";
    birthday.output();
    cout << endl << endl;

    if (compareDayOfYear(today, birthday))
        cout << "Happy Birthday!" << endl;
    else
        cout << "Happy UN-Birthday!" << endl;

    return 0;
}

void DayOfYear::input()
{
    cout << "Enter the month as a number:" << endl;
    cin >> month;
    cout << "Enter the day of the month: " << endl;
    cin >> day;
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
    cout << day;
}

void DayOfYear::set(int NewMonth, int NewDay)
{
    month = NewMonth;
    day = NewDay;
    testDate();
}

int DayOfYear::getMonthNumber()
{
    return month;
}

int DayOfYear::getDayNumber()
{
    return day;
}

void DayOfYear::testDate()
{
    if ((month < 1) || (month > 12))
    {
        cout << "Illeagal month value!\n";
        exit(1);
    }
    if ((day < 1) || (day > 31))
    {
        cout<< "Illeagal day value!\n";
        exit(1);
    }
}

bool compareDayOfYear(DayOfYear& D1, DayOfYear& D2)
{
    return (D1.getMonthNumber() == D2.getMonthNumber()) && (D1.getDayNumber() == D2.getDayNumber());
}