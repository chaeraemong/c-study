#include <iostream>
using namespace std;

class Money
{
public:
	Money(int theWon = 0) : won(theWon) {}
	int getWon() const { return won; }
	void input() { cin >> won; }
	void output() const { cout << won; }
	friend const Money operator +(const Money& m1, const Money& m2) { return Money(m1.won + m2.won); }
	friend const Money operator -(const Money& m1, const Money& m2) { return Money(m1.won - m2.won); }
	friend bool operator ==(const Money& m1, const Money& m2) { return (m1.won == m2.won); }
	friend const Money operator -(const Money& m) { return Money(-m.won); }
	friend ostream& operator <<(ostream& out, const Money& m);
	friend istream& operator >>(istream& in, const Money& m);
private:
	int won;
};

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

	cout << "______________________________________" << endl << endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Money yourAmount2, myAmount2(20000);
	cout << "Enter an amount of money : ";
	cin >> yourAmount2;

	cout << "Your amount is " << yourAmount2 << endl;
	cout << "My amount is " << myAmount2 << endl;

	if (yourAmount2 == myAmount2)
		cout << "We have the same amounts." << endl;
	else
		cout << "One of us is richer." << endl;

	Money ourAmount2 = yourAmount2 + myAmount2;
	cout << yourAmount2 << " + " << myAmount2 << " equals " << ourAmount2 << endl;

	Money diffAmount2 = yourAmount2 - (-myAmount2);
	cout << yourAmount2 << " - (-" << myAmount2 << ") equals " << diffAmount2 << endl;

	return 0;
}

ostream& operator <<(ostream& out, const Money& m)
{
	out << m.won;
	return out;
}

istream& operator >>(istream& in, const Money& m)
{
	in >> m.won;
	return in;
}