// main.cpp

#include "21_HW6_solution_student_declaration.h"
#include "22_HW6_solution_subject_declaration.h"
#include <iostream>
#include <string>
using namespace std;
using namespace Chaeyoung;
using namespace EAP;

int Subject::staticN = 0;

int main()
{
	int n = 3;
	Subject cppProgramming(n);

	cppProgramming[0] = Student("2172000", 2);
	cout << "1st student: ";
	cout << cppProgramming[0];

	cppProgramming[1].setId("2072000");
	cppProgramming[1].setGrade(3);
	cout << "2nd student: ";
	cout << cppProgramming[1];

	cout << "Enter your information: " << endl;
	cin >> cppProgramming[2];
	cout << "3rd student: ";
	cout << cppProgramming[2];

	cout << "----------------------------" << endl;
	cout << "subject: cppProgramming" << endl;
	cout << cppProgramming;
	cout << cppProgramming.getN() << " students in this subject" << endl;

	cout << "----------------------------" << endl;
	cout << "subject: copy" << endl;
	Subject cppCopy(cppProgramming);
	cout << cppCopy;
	cout << cppCopy.getN() << " students in this subject" << endl;

	cout << "----------------------------" << endl;
	cout << "subject: assign" << endl;
	Subject cppAssign;
	cppAssign = cppCopy;
	cout << cppAssign;
	cout << cppAssign.getN() << " students in this subject" << endl;

	cout << "----------------------------" << endl;
	cout << EAP::Subject::getStaticN() << " subjects." << endl;

	return 0;
}
