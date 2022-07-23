// student.cpp

#include "21_HW6_solution_student_declaration.h"
#include "22_HW6_solution_subject_declaration.h"
#include <iostream>
#include <string>
using namespace std;

namespace Chaeyoung
{
	void Student::testId()
	{
		if (id.length() != 7)
		{
			cout << "Illegal id!" << endl;
			exit(1);
		}
	}

	void Student::testGrade()
	{
		if (grade < 1 || grade > 4)
		{
			cout << "Illegal grade!" << endl;
			exit(1);
		}
	}

	Student::Student(string d, int g) :id(d), grade(g)
	{
		testId();
		testGrade();
	}

	void Student::setId(string d)
	{
		id = d;
		testId();
	}

	void Student::setGrade(int g)
	{
		grade = g;
		testGrade();
	}

	ostream& operator<<(ostream& out, const Student& s)
	{
		out << s.id << "(" << s.grade << ")" << endl;

		return out;
	}

	istream& operator>>(istream& in, Student& s)
	{
		cout << "Enter student id (7 digits): ";
		in >> s.id;
		s.testId();
		cout << "Enter student grade (1~4): ";
		cin >> s.grade;
		s.testGrade();

		return in;
	}
}
