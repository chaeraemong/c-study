#include <iostream>
using namespace std;

class CDAccountV3
{
public:
    CDAccountV3(double d, double r, int m);
    void output() const;
    double getBalance() const;
    static int getNumAccounts();
private:
    double balance;
    double deposit;
    double interestRate;
    int month;
    static int numAccounts;
    void calBalance();
};

bool compareAccounts(const CDAccountV3& account1, const CDAccountV3& account2);
int CDAccountV3::numAccounts(0);

int main()
{
    CDAccountV3 account1(10000, 10, 6);
    account1.output();

    CDAccountV3 account2(10000, 5, 12);
    account2.output();

    cout << "The number of accounts: "
        << CDAccountV3::getNumAccounts() << endl;

    if (compareAccounts(account1, account2))
        cout << "same!" << endl;
    else
        cout << "not same!" << endl;

    return 0;
}

CDAccountV3::CDAccountV3(double d, double r, int m)
{
    deposit = d;
    interestRate = r;
    month = m;
    calBalance();
    numAccounts++;
}

void CDAccountV3::output() const
{
    cout << "Deposit: " << deposit << endl
        << "Interest Rate: " << interestRate << "%" << endl
        << "Period: " << month << " months" << endl
        << "------------------------------" << endl
        << "Balance: " << balance << endl
        << "------------------------------" << endl;
}

double CDAccountV3::getBalance() const
{
    return balance;
}

int CDAccountV3::getNumAccounts()
{
    return numAccounts;
}

void CDAccountV3::calBalance()
{
    balance = deposit * (1 + interestRate / 100 * month / 12);
}

bool compareAccounts(const CDAccountV3& account1, const CDAccountV3& account2)
{
    return account1.getBalance() == account2.getBalance();
}

/*
* °á°ú
* 
* 
Deposit: 10000
Interest Rate : 10 %
Period : 6 months
------------------------------
Balance : 10500
------------------------------
Deposit : 10000
Interest Rate : 5 %
Period : 12 months
------------------------------
Balance : 10500

------------------------------
The number of accounts : 2
same!
*/