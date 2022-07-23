// subject.h

#pragma once

namespace EAP
{
	class Subject
	{
		int n;
		Chaeyoung::Student* students;
		void deepCopy(const Subject& s);
		static int staticN;
	public:
		Subject(int num = 1);
		Subject(const Subject& copy);
		int getN() const;
		static int getStaticN();
		Subject& operator=(const Subject& right);
		Chaeyoung::Student& operator[](int index);
		friend std::ostream& operator<<(std::ostream& out, const Subject& s);
		~Subject();
	};
}