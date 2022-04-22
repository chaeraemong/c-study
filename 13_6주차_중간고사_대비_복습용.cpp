#include <iostream>
using namespace std;

typedef int* Intptr;
void sneaky(Intptr temp);
void fillArray(int a[], int size);
int search(int a[], int size, int target);


int main()
{
	Intptr p;
	p = new int;
	*p = 77;
	cout << "Before call to function *p == " << *p << endl;
	sneaky(p);
	cout << "After call to function *p == " << *p << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "________________________________________________________" << endl << endl;

	cout << "This program searches a list of numbers." << endl;
	int arraysize;
	cout << "How many numbers will be on the list? ";
	cin >> arraysize;
	cout << endl;

	Intptr a;
	a = new int[arraysize];
	fillArray(a, arraysize);

	int target;
	cout << endl << "Enter a value to search for : ";
	cin >> target;
	int location = search(a, arraysize, target);
	if (location == -1)
		cout << target << " is not is the array" << endl;
	else
		cout << target << " is element " << location << " in the array." << endl << endl;
	
	delete[] a;

	//////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "________________________________________________________" << endl << endl;

	int r, c;
	cout << "Enter the row and column dimensions of the array : ";
	cin >> r >> c;

	Intptr* m = new Intptr[r];
	int i, j;
	for (i = 0; i < r; i++)
		m[i] = new int[c];

	cout << endl << "Enter " << r << " rows of " << c << " integers each : " << endl;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			cin >> m[i][j];

	cout << endl << "Echoing the 2 dimensional array : " << endl;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}

	for (i = 0; i < r; i++)
		delete[] m[i];
	delete m;

	return 0;
}

void sneaky(Intptr temp)
{
	*temp = 99;
	cout << "Inside function call *temp == " << *temp << endl;
}

void fillArray(int a[], int size)
{
	cout << "Enter " << size << " integers." << endl;
	for (int index = 0; index < size; index++)
		cin >> a[index];
}

int search(int a[], int size, int target)
{
	int index = 0;
	while ((a[index] != target) && (index < size))
		index++;
	if (index == size)
		index = -1;

	return index;
}