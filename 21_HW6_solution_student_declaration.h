// student.h

#pragma once
#include <string>

namespace Chaeyoung
{
	class Student
	{
		std::string id;
		int grade;
		void testId();
		void testGrade();
	public:
		Student(std::string d = "1234567", int g = 1);
		void setId(std::string d);
		void setGrade(int g);
		friend std::ostream& operator<<(std::ostream& out, const Student& s);
		friend std::istream& operator>>(std::istream& in, Student& s);
	};
}