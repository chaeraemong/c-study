#include <iostream>
using namespace std;

class DayOfYear
{
public:
    void input();
    void output();
    int month;
    int day;
    int year;
};

void wrongtestDay(int& day);
int DayCalculate(DayOfYear& D1, DayOfYear& D2);
int LeapYear(DayOfYear& D);
bool LeapYear2(DayOfYear& D);
int monthDays(DayOfYear& D);
int monthDays2(int D);
int MonthCalculate(DayOfYear& D1, DayOfYear& D2);
int YearCalculate(DayOfYear& D1, DayOfYear& D2);
bool compareDayOfYear(DayOfYear& D1, DayOfYear& D2);

int main()
{
    DayOfYear today{};
    cout << "Enter today`s date... " << endl;
    today.input();
    cout << endl;
    cout << ">>> Today`s date is " << today.year << " ";
    today.output();
    cout << ". <<<";
    cout << endl << endl << endl;

    DayOfYear birthday{};
    cout << "Enter your birthday date... " << endl;
    birthday.input();
    cout << endl;
    cout << ">>> Your birthday`s date is " << birthday.year << " ";
    birthday.output();
    cout << ". <<<";
    cout << endl << endl << endl;

    cout << ">>> It has been " << DayCalculate(today, birthday) << "days, "
        << MonthCalculate(today, birthday) << "months, and "
        << YearCalculate(today, birthday) << "years since you were born. <<<" << endl;
    cout << endl;

    if (compareDayOfYear(today, birthday))
        cout << ">>> Happy Birthday!  <<<" << endl;
    else
        cout << ">>>  Today is NOT your birthday! HAHAHAA!  <<<" << endl;

    return 0;
}

void DayOfYear::input()
{
    cout << "Enter the number of the year : ";
    cin >> year;
    if (month < 0)
    {
        cout << endl;
        cout << ">>>  Illegal month value!  <<<\nRE-ENTER the year : ";
        cin >> year;
        cout << endl;
    }

    cout << "Enter the month as a number : ";
    cin >> month;
    if ((month < 1) || (month > 12))
    {
        cout << endl;
        cout << ">>>  Illegal month value!  <<<\nRE-ENTER the month : ";
        cin >> month;
        cout << endl;
    }

    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
    {
        cout << "Enter the number of the day : ";
        cin >> day;
        if ((day < 1) || (day > 31))
            wrongtestDay(day);
    }
    else if (month == 2)
    {
        cout << "Enter the number of the day : ";
        cin >> day;
        if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0))
        {
            if ((day < 1) || (day > 29))
                wrongtestDay(day);
        }
        else
            if ((day < 1) || (day > 28))
                wrongtestDay(day);
    }
    else
    {
        cout << "Enter the number of the day : ";
        cin >> day;
        if ((day < 1) || (day > 30))
            wrongtestDay(day);
    }
}

void wrongtestDay(int& day)
{
    cout << endl;
    cout << ">>>  Illegal day value!  <<<\nRE-ENTER the day: ";
    cin >> day;
    cout << endl;
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
        break;
    }
    cout << day;
}

int DayCalculate(DayOfYear& D1, DayOfYear& D2)                  // calculate total days since you were born
{
    int leapYear = 0, leapYear1 = 0, leapYear2 = 0;
    int days = 0;

    DayOfYear D3;
    D3.year = D2.year - 1;

    leapYear1 = LeapYear(D1);                                   // number of leap years until today
    leapYear2 = LeapYear(D3);                                   // number of leap years until your birth year
    leapYear = leapYear1 - leapYear2;                           // number of leap years during you were alive

    if (LeapYear2(D2) == 1)                                     // [1] if born year is leap year
    {
        if ((D2.month == 1) || ((D2.month == 2) && (D2.day <= 28))) // 1) if born before febuary 29th
        {
            if ((LeapYear2(D1) == 1) && ((D1.month == 1) || ((D1.month == 2) && (D1.day <= 28)))) // (1) if leap year and today`s date before febuary 29th
                leapYear = leapYear - 1;
            else                                                // (2) if leap year and today`s date after febuary 28th or not leap year
                leapYear = leapYear - 0;
        }
        else if (((D2.month == 2) && (D2.day == 29)) || (D2.month >= 3)) // 2) if boren after febuary 28th
        {
            if ((LeapYear2(D1) == 1) && ((D1.month == 1) || ((D1.month == 2) && (D1.day <= 28)))) // (1) if leap year and today`s date before febuary 29th
                leapYear = leapYear - 2;
            else                                                // (2) if leap year and today`s date after febuary 28th or not leap year
                leapYear = leapYear - 1;
        }
    }
    else if (LeapYear2(D2) == 0)                                // [2] if born year is not leap year
    {
        if ((LeapYear2(D1) == 1) && ((D1.month == 1) || ((D1.month == 2) && (D1.day <= 28)))) // 1) if leap year and today`s date before febuary 29th
            leapYear = leapYear - 1;
        else                                                    // 2) if leap year and today`s date after feburary 28th or not leap year
            leapYear = leapYear - 0;
    }

    if (D1.month < D2.month)                                    // D1.month < D2.month
    {
        for (int i = 1; i < D1.month; i++)                      // number of days from january 1st to (D1.month-1)
            days += monthDays2(i);
        for (int j = D2.month; j <= 12; j++)                    // number of days from D2.month to december
            days += monthDays2(j);
        days = days + D1.day - D2.day;
    }
    else if (D1.month == D2.month)                              // D1.month == D2.month
    {
        if ((D1.day + 1) >= D2.day)
            days = D1.day - D2.day;///
        else
            days = 365 - (D2.day - D1.day);
    }
    else if (D1.month > D2.month)                               // D1.month > D2.month
    {
        for (int i = D2.month; i < D1.month; i++)
            days += monthDays2(i);
        days = days + D1.day - D2.day;
    }

    return (YearCalculate(D1, D2) * 365) + leapYear + days;
}

int LeapYear(DayOfYear& D)                                      // number of leap years
{
    int leapYear = 0;

    for (int i = 1; i <= D.year; i++)
    {
        if ((i % 4) == 0)
            leapYear++;
    }
    for (int i = 1; i <= D.year; i++)
    {
        if ((i % 100) == 0)
            leapYear--;
    }
    for (int i = 1; i <= D.year; i++)
    {
        if ((i % 400) == 0)
            leapYear++;
    }

    return leapYear;
}

bool LeapYear2(DayOfYear& D)
{
    if (((D.year % 400) == 0) || (((D.year % 4) == 0) && ((D.year % 100) != 0)))    // if leap year
        return 1;
    else                                                        // if not leap year
        return 0;
}

int monthDays(DayOfYear& D)                             // number of days each month
{
    if ((D.month == 1) || (D.month == 3) || (D.month == 5) || (D.month == 7) || (D.month == 8) || (D.month == 10) || (D.month == 12))
        return 31;
    else if (D.month == 2)
    {
        if (((D.year % 4) == 0) && (((D.year % 100) != 0) || ((D.year % 400) == 0)))
            return 29;
        else
            return 28;
    }
    else
        return 30;
}

int monthDays2(int D)                                           // number of days each month
{
    if ((D == 1) || (D == 3) || (D == 5) || (D == 7) || (D == 8) || (D == 10) || (D == 12))
        return 31;
    else if (D == 2)
        return 28;
    else if ((D == 4) || (D == 6) || (D == 9) || (D == 11))
        return 30;
}

int MonthCalculate(DayOfYear& D1, DayOfYear& D2)        // calculate total months since you were born
{
    int months;
    if (D1.month < D2.month)
    {
        if ((D1.day + 1) >= D2.day)
            months = 12 + D1.month - D2.month;
        else
            months = 11 + D1.month - D2.month;
    }
    else if (D1.month == D2.month)
    {
        if ((D1.day + 1) >= D2.day)
            months = 0;
        else
            months = 11;
    }
    else
    {
        if ((D1.day + 1) >= D2.day)
            months = D2.month - D1.month;
        else
            months = D2.month - D1.month - 1;
    }
    return YearCalculate(D1, D2) * 12 + months;
}

int YearCalculate(DayOfYear& D1, DayOfYear& D2)                 // calculate total years since you were born
{
    if (D1.month > D2.month)
    {
        return D1.year - D2.year;
    }
    else if (D1.month == D2.month)
    {
        if ((D1.day + 1) >= D2.day)
            return D1.year - D2.year;
        else
            return D1.year - D2.year - 1;
    }
    else
        return D1.year - D2.year - 1;
}

bool compareDayOfYear(DayOfYear& D1, DayOfYear& D2)     // compare whether today is your birthday
{
    return (D1.month == D2.month) && (D1.day == D2.day);
}
