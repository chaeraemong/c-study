#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void makeneat2(ifstream& fin, ofstream& fout);

int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("rawdata.txt");
	if (fin.fail())
	{
		cout << "Input file opening failed." << endl;
		exit(1);
	}

	string filename;
	cout << "Enter output file name (*.txt):";
	cin >> filename;
	fout.open(filename);
	if (fout.fail())
	{
		cout << "Output file opening failed." << endl;
		exit(1);
	}

	makeneat2(fin, fout);

	fin.close();
	fout.close();

	return 0;
}

void makeneat2(ifstream& fin, ofstream& fout)
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);

	double next = 0;
	int num = 0;
	fin >> next;
	while (!fin.eof())
	{
		num++;
		fout << num << setw(10) << next << endl;
		fin >> next;
	}
}