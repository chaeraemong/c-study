#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;

void newLine();

int main()
{
	array<int, 3 > a = { 1, 2, 3 };
	cout << a[0] << " " << a.at(1) << " " << a.size() << endl;
	for (int i = 0; i < 3; ++i)
		cout << a[i] << " ";
	cout << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "________________________________________________-" << endl << endl;

	vector<int> v;
	cout << "Enter a list of positive numbers. Place a negative at the end." << endl;
	int next;
	cin >> next;
	cout << endl;

	while (next >= 0)
	{
		v.push_back(next);
		cout << next << " added. v.size() = " << v.size() << endl;
		cin >> next;
	}

	cout << endl << "You entered : " << endl;
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "________________________________________________-" << endl << endl;

	string firstname, lastname, recordname, spellname;
	string motto = "Your records are our records.";

	cout << "Enter your first and last name : " << endl;
	cin >> firstname >> lastname;
	newLine();

	recordname = lastname + ", " + firstname;
	cout << "Your name in our records is : " << recordname << endl << endl;
	
	spellname = firstname + " " + lastname;
	cout << "Your name is spelled : " << endl;
	for (unsigned int i = 0; i < spellname.length(); i++)
	{
		cout << spellname[i] << " ";
		spellname[i] = '-';
	}
	cout << endl;
	for (unsigned int i = 0; i < spellname.length(); i++)
		cout << spellname[i] << " ";
	cout << endl << endl;

	cout << "Our motto is : " << motto << endl << endl;

	cout << "Please suggest a better motto(one line) : ";
	getline(cin, motto);
	cout << "Our new motto will be : " << motto << endl << endl;

	cout << "Have a nice day " << firstname << endl;

	return 0;
}

void newLine()
{
	char nextChar;
	do
	{
		cin.get(nextChar);
	} while (nextChar != '\n');
}
