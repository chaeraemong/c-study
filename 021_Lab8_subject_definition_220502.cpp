// subject.cpp

#include "21_HW6_solution_student_declaration.h"
#include "22_HW6_solution_subject_declaration.h"
#include <iostream>
#include <string>
using namespace std;

namespace EAP
{
	ostream& operator<<(ostream& out, const Subject& s)
	{
		for (int i = 0; i < s.n; ++i)
			out << s.students[i];

		return out;
	}

	void Subject::deepCopy(const Subject& s)
	{
		if (s.students)
		{
			students = new Chaeyoung::Student[n];
			for (int i = 0; i < n; ++i)
				students[i] = s.students[i];
		}
		else
			students = nullptr;
	}
	Subject::Subject(int num) :n(num)
	{
		students = new Chaeyoung::Student[n]{};
		staticN++;
	}

	Subject::Subject(const Subject& copy) : n(copy.n)
	{
		deepCopy(copy);
		staticN++;
	}

	int Subject::getN() const
	{
		return n;
	}

	int Subject::getStaticN()
	{
		return staticN;
	}

	Subject& EAP::Subject::operator=(const Subject& right)
	{
		if (this != &right)
		{
			n = right.n;
			delete[] students;
			deepCopy(right);
		}
		return *this;
	}

	Chaeyoung::Student& Subject::operator[](int index)
	{
		if (index >= n)
		{
			cout << "Error: illegal index!" << endl;
			exit(1);
		}
		return students[index];
	}

	Subject::~Subject()
	{
		delete[] students;
	}
}
