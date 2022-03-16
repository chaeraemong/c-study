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
bool compareDayOfYear(DayOfYear& D1, DayOfYear& D2);

int main()
{
    DayOfYear today{};
    cout << "Enter today`s date... " << endl;
    today.input();
    cout << "Today`s date is ";
    today.output();
    cout << ".";
    cout << endl << endl;

    DayOfYear birthday{};
    cout << "Enter birthday`s date... " << endl;
    birthday.input();
    cout << "Birthday`s date is ";
    birthday.output();
    cout << ".";
    cout << endl << endl;

    if (compareDayOfYear(today, birthday))
        cout << ">>> Happy Birthday!  <<<" << endl;
    else
        cout << ">>>  Today is NOT your birthday! HAHAHAA!  <<<" << endl;

    return 0;
}

void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << endl;
    if ((month < 1) || (month > 12))
    {
        cout << ">>>  Illeagal month value!  <<<\nRE-ENTER the month: ";
        cin >> month;
        cout << endl;
    }

    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
    {
        cout << "Enter the day of the month: ";
        cin >> day;
        if ((day < 1) || (day > 31))
            wrongtestDay(day);
    }
    else if (month == 2)
    {
        cout << "Enter the number of this year: ";
        cin >> year;
        cout << endl;
        cout << "Enter the day of the month: ";
        cin >> day;
        if ((year % 4) == 0)
        {
            if ((year % 100) == 0)
            {
                if ((day < 1) || (day > 29))
                    wrongtestDay(day);
            }
            else
                wrongtestDay(day);
        }
        else
            wrongtestDay(day); 
    }
    else
    {
        cout << "Enter the day of the month: ";
        cin >> day;
        if ((day < 1) || (day > 30))
            wrongtestDay(day);
    }
}

void wrongtestDay(int& day)
{
    cout << endl;
    cout << ">>>  Illeagal day value!  <<<\nRE-ENTER the day: ";
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
        cout << "You put in the wrong number";
    }
    cout << day;
}

bool compareDayOfYear(DayOfYear& D1, DayOfYear& D2)
{
    return (D1.month == D2.month) && (D1.day == D2.day);
}