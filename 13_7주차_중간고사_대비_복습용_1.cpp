#include <iostream>
using namespace std;

class Int
{
	int n;
	int* a = nullptr;
public:
	Int(int m = 0) :n(m) { a = new int[n]; }
	Int& add(int m) { n += m; return *this; }
	Int& sub(int m) { n -= m; return *this; }
	Int& mul(int m) { n *= m; return *this; }
	void setN(int m) { this->n = m; }
	int getN() { return this->n; }
};

class CharPair
{
	char first, second;
public:
	CharPair(char firstvalue = 'a', char secondvalue = 'b') :first(firstvalue), second(secondvalue) {}
	char& operator [](int index);
};

int main()
{
	Int n(10);
	n.add(10).sub(10).mul(10);
	cout << n.getN() << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "____________________________________________________" << endl << endl;

	CharPair a;
	a[1] = 'A';
	a[2] = 'B';
	cout << "a[1] and a[2] are : " << endl;
	cout << a[1] << " " << a[2] << endl;

	cout << "Enter two letters (no spaces) : " << endl;
	cin >> a[1] >> a[2];
	cout << "You entered : ";
	cout << a[1] << " " << a[2] << endl;

	return 0;
}

char& CharPair::operator [](int index)
{
	if (index == 1)
		return first;
	else if (index == 2)
		return second;
	else
	{
		cout << "Illegal index value." << endl;
		exit(1);
	}
}