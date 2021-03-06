#include <iostream>
using namespace std;

class CDAccountV2
{
public:
    void output();
    void setDeposit(double NewDeposit);
    void setInterestRate(double NewInterestRate);
    void setMonth(int NewMonth);
    double getDeposit();
    double getInterestRate();
    int getMonth();
private:
    double deposit = 10000;
    double interestRate = 10;
    int month = 6;
};

int main()
{
    CDAccountV2 account1;
    account1.output();

    CDAccountV2 account2;
    account2.setDeposit(20000);
    account2.setInterestRate(5);
    account2.setMonth(6);
    account2.output();
    if ((account1.getDeposit() == account2.getDeposit()) && (account1.getInterestRate() == account2.getInterestRate()) && (account1.getMonth() == account2.getMonth()))
        cout << "same" << endl;
    else
        cout << "not same" << endl;

    return 0;
}

void CDAccountV2::output()
{
    cout << "Deposit: " << deposit << endl
        << "Interest Rate: " << interestRate << "%" << endl
        << "Period: " << month << " months" << endl;
}

void CDAccountV2::setDeposit(double NewDeposit)
{
    deposit = NewDeposit;
}

void CDAccountV2::setInterestRate(double NewInterestRate)
{
    interestRate = NewInterestRate;
}

void CDAccountV2::setMonth(int NewMonth)
{
    month = NewMonth;
}

double CDAccountV2::getDeposit()
{
    return deposit;
}

double CDAccountV2::getInterestRate()
{
    return interestRate;
}

int CDAccountV2::getMonth()
{
    return month;
}

/*
°á°ú
Deposit: 10000
Interest Rate : 10 %
Period : 6 months
Deposit : 20000
Interest Rate : 5 %
Period : 6 months
not same
*/
