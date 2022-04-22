#include <iostream>
using namespace std;

class Money
{
public:
	Money(int theWon = 0) : won(theWon) {}
	int getWon() const { return won; }
	void input() { cin >> won; }
	void output()const { cout << won; }
	const Money operator +(const Money& m) const { return Money(won + m.won); }
	const Money operator -(const Money& m) const { return Money(won - m.won); }
	bool operator ==(const Money& m) const { return won == m.won; }
	const Money operator -() const { return Money(-won); }
private:
	int won;
};

class IntPair
{
public:
	IntPair(int firstValue, int secondValue) :first(firstValue), second(secondValue) {}
	IntPair operator ++(int);
	IntPair operator ++();
	void setFirst(int newValue) { first = newValue; }
	void setSecond(int newValue) { second = newValue; }
	int getFirst() { return first; }
	int getSecond() { return second; }
private:
	int first;
	int second;
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
	
	IntPair a(1, 2);
	cout << "Postfix a++ : Start value of object a : ";
	cout << a.getFirst() << " " << a.getSecond() << endl;

	IntPair b = a++;
	cout << "Valude returned : ";
	cout << b.getFirst() << " " << b.getSecond() << endl;
	cout << "Changed object : ";
	cout << a.getFirst() << " " << a.getSecond() << endl << endl;

	a = IntPair(1, 2);
	cout << "Postfix ++a : Start value of object a : ";
	cout << a.getFirst() << " " << a.getSecond() << endl;

	IntPair c = ++a;
	cout << "Valude returned : ";
	cout << c.getFirst() << " " << c.getSecond() << endl;
	cout << "Changed object : ";
	cout << c.getFirst() << " " << c.getSecond() << endl;

	return 0;
}

IntPair IntPair::operator ++(int)
{
	int temp1 = first;
	int temp2 = second;
	first++;
	second++;

	return IntPair(temp1, temp2);
}

IntPair IntPair:: operator ++()
{
	first++;
	second++;

	return IntPair(first, second);
}
