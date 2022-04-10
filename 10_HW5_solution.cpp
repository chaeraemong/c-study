#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;

class Account
{
public:
    Account(string nm = "", double d = 0, double r = 0, int m = 0);
    double getBalance() const { return balance; }
    friend istream& operator>>(istream& in, Account& a);
    friend ostream& operator<<(ostream& out, const Account& a);
private:
    string name;
    double balance;
    double deposit;
    double interestRate;
    int month;
    void calBalance() { balance = deposit * (1 + interestRate / 100 * month / 12); }
};

double computeAverage(const vector<double>& v);

int main()
{
    const int n = 2;
    array<Account, n> a;
    for (int i = 0; i < n; ++i)
    {   
        cin >> a.at(i);
        cout << endl;
        cout << "--------------------" << endl;
        cout << a.at(i) << endl;
        cout << "--------------------" << endl;
    }

    vector<double> v;
    v.push_back(a[0].getBalance());
    v.push_back(a[1].getBalance());
    cout << "size of v : " << v.size() << endl;
    cout << "average : " << computeAverage(v) << endl;

    return 0;
}

double computeAverage(const vector<double>& v)
{
    if (v.size() > 0)
    {
        double total = 0;
        for (int i = 0; i < v.size(); ++i)
            total += v[i];
        return total / v.size();
    }
    else
    {
        cout << "ERROR in computeAverage(): number of elements" << endl;
        exit(1);
    }
}

Account::Account(string nm, double d, double r, int m) :
    name(nm), deposit(d), interestRate(r), month(m)
{
    calBalance();
}

istream& operator>>(istream& in, Account& a)
{
    cout << "Enter the account name : ";
    in >> a.name;
    cout << "Enter the deposit : ";
    in >> a.deposit;
    cout << "Enter the interest rate (%) : ";
    in >> a.interestRate;
    cout << "Enter the months : ";
    in >> a.month;
    a.calBalance();
    return in;
}

ostream& operator<<(ostream& out, const Account& a)
{
    out << a.name;
    out << " : ";
    out << a.balance;
    return out;
}

/* 모두 구현한 후 결과예는 다음과 같습니다.

Enter the account name : a1
Enter the deposit : 10000
Enter the interest rate(%) : 5
Enter the months : 10
--------------------
a1 : 10416.7
--------------------
Enter the account name : a2
Enter the deposit : 10000
Enter the interest rate(%) : 6
Enter the months : 8
--------------------
a2 : 10400
--------------------
size of v : 2
average : 10408.3
*/
