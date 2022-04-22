#include <iostream>
using namespace std;

class Money
{
public:
	Money(int theWon = 0) : won(theWon) {}
	int getWon() const { return won; }
	void input() { cin >> won; }
	void output()const { cout << won; }
private:
	int won;
};

const Money operator +(const Money& m1, const Money& m2)
{
	return Money(m1.getWon() + m2.getWon());
}

const Money operator -(const Money& m1, const Money& m2)
{
	return Money(m1.getWon() - m2.getWon());
}

bool operator ==(const Money& m1, const Money& m2)
{
	return (m1.getWon() == m2.getWon());
}

const Money operator -(const Money& m)
{
	return Money(-m.getWon());
}

int main()
{
	Money yourAmount, myAmount(10000);
	cout << "Enter an amount of money : ";
	yourAmount.input();

	cout << "Your amount is ";
	yourAmount.output();
	cout << endl;

	cout << "My amount is ";
	myAmount.output();
	cout << endl;

	if (yourAmount == myAmount)
		cout << "We have the same amounts." << endl;
	else
		cout << "One of us is richer." << endl;

	Money ourAmount = yourAmount + myAmount;
	yourAmount.output(); cout << " + "; myAmount.output(); cout << " equals "; ourAmount.output(); cout << endl;

	Money diffAmount = yourAmount - (-myAmount);
	yourAmount.output(); cout << " - (-"; myAmount.output(); cout << ") equals "; diffAmount.output(); cout << endl;

	return 0;
}