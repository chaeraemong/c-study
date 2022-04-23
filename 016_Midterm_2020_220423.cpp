#include <iostream>
#include <string>
using namespace std;

class CDAccountV4
{
public:
	CDAccountV4() : cap(50), used(0) { bal = new double[cap]; name = new string[cap]; }
	CDAccountV4(int size) : cap(size), used(0) { bal = new double[cap]; name = new string[cap]; }
	CDAccountV4(const CDAccountV4& CDAObject);
	void add(double bal2, string n);
	void empty() { used = 0; }
	bool full() const { return cap == used; }
	int getCapacity() const { return cap; }
	int getNumberUsed() const { return used; }
	string getName(int index) { return name[index]; }
	double& operator [](int index);
	CDAccountV4& operator = (const CDAccountV4& r);
	~CDAccountV4();
	
private :
	double* bal;
	string* name;
	int cap;
	int used;
};

void testCDAccountV4();

int main()
{
	cout << "This program tests the class CDAccountV4." << endl;
	char ans;
	do
	{
		testCDAccountV4();
		cout << "Test again? (y/n) ";
		cin >> ans;
	} while ((ans == 'y') || (ans == 'Y'));
	
	return 0;
}

CDAccountV4::CDAccountV4(const CDAccountV4& CDAObject) : cap(CDAObject.cap), used(CDAObject.used)
{
	bal = new double[cap];
	name = new string[cap];

	for (int i = 0; i < used; i++)
	{
		*(bal + i) = CDAObject.bal[i];
		*(name + i) = CDAObject.name[i];
	}
}

void CDAccountV4::add(double bal2, string n)
{
	if (used >= cap)
	{
		cout << endl << "Attemp to exceed capacity in CDAccountV4." << endl;
		exit(0);
	}
	bal[used] = bal2;
	name[used] = n;
	used++;
}

double& CDAccountV4::operator [](int index)
{
	if (index >= used)
	{
		cout << "Illegal index in CDAccountV4." << endl;
		exit(0);
	}

	return bal[index];
}

CDAccountV4& CDAccountV4::operator =(const CDAccountV4& r)
{
	if (cap != r.getCapacity())
	{
		delete[] bal;
		delete[] name;

		bal = new double[r.cap];
		name = new string[r.cap];
	}

	cap = r.cap;
	used = r.used;

	for (int i = 0; i < used; i++)
	{
		bal[i] = r.bal[i];
		name[i] = r.name[i];
	}

	return *this;
}

CDAccountV4::~CDAccountV4()
{
	delete[] bal;
	delete[] name;
}

void testCDAccountV4()
{
	int cap2;
	cout << endl << "Enter capacity of this account array : ";
	cin >> cap2;
	CDAccountV4 temp(cap2);

	cout << endl << "Enter up to " << cap2 << " CDAccount balances and names." << endl;
	cout << "Place a negatice number at the end." << endl;
	double next;
	string name;
	cout << endl << "CDAccount balance : ";
	cin >> next;

	while ((next >= 0) && (!temp.full()))
	{
		cout << "CDAccount name : ";
		cin >> name;
		temp.add(next, name);
		cout <<  endl << "CDAccount balance : ";
		cin >> next;
	}

	int count = temp.getNumberUsed();
	cout << endl << "You entered the following " << count << " numbers : " << endl;
	
	for (int index = 0; index < count; index++)
		cout << temp.getName(index) << " : " << temp[index] << endl;
	cout << endl;
}
