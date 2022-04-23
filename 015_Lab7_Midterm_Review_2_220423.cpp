#include <iostream>
using namespace std;

class PFArrayD
{
public:
	PFArrayD(int capacityValue = 50) : capacity(capacityValue), used(0) { a = new double[capacity]; }
	PFArrayD(const PFArrayD& copy);
	void addElement(double element);
	bool full() const { return (capacity == used); }
	int getCapacity() const { return capacity; }
	int getUsed() const { return used; }
	void emptyArray() { used = 0; }
	double& operator[](int index);
	PFArrayD& operator = (const PFArrayD& right);
	~PFArrayD() { delete[] a; }
private:
	double* a = nullptr;
	int capacity = 50;
	int used;
	void deepCopy(const PFArrayD& source);
};

void testPFArrayD();

int main()
{
	cout << "This program tests the class PFArrayD." << endl;
	char ans('y');
	do
	{
		testPFArrayD();
		cout << endl << "Test again? (y/n) ";
		cin >> ans;
	} while ((ans == 'y') || (ans == 'Y'));

	return 0;
}

PFArrayD::PFArrayD(const PFArrayD& copy)
	: capacity(copy.capacity), used(copy.used)
{
	deepCopy(copy);
}

void PFArrayD::addElement(double element)
{
	if (used >= capacity)
	{
		cout << "Attempt to exceed capacity" << endl;
		exit(0);
	}
	a[used] = element;
	used++;
}

double& PFArrayD::operator [](int index)
{
	if (index > used)
	{
		cout << "Illegal index in PFArrayD" << endl;
		exit(0);
	}

	return a[index];
}

PFArrayD& PFArrayD::operator =(const PFArrayD& right)
{
	if (this != &right)
	{
		capacity = right.capacity;
		used = right.used;
		delete[] a;
		deepCopy(right);
	}

	return *this;
}

void PFArrayD::deepCopy(const PFArrayD& source)
{
	if (source.a)
	{
		a = new double[capacity];
		for (int i = 0; i < used; i++)
			*(a+i) = source.a[i];
	}
	else
		a = nullptr;
}

void testPFArrayD()
{
	int cap;
	cout << endl << "Enter capacity of this super array : ";
	cin >> cap;
	PFArrayD temp(cap);
	cout << endl << "Enter up to " << cap << " nonnegative numbers." << endl;
	cout << "Place a negative number at the end." << endl;
	double next;
	cin >> next;
	while ((next >= 0) && (!temp.full()))
	{
		temp.addElement(next);
		cin >> next;
	}
	cout << endl << "You entered the following " << temp.getUsed() << " numbers : " << endl;
	int index;
	int count = temp.getUsed();
	for (index = 0; index < count; index++)
		cout << temp[index] << " ";
	cout << endl;
}
