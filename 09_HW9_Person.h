#pragma once
#include <string>
#include <iostream>

class Person
{
protected:
	std::string name;
public:
	Person(const std::string& theName = "No name yet")
		: name(theName)
	{
		std::cout << "Person constructor" << std::endl;
	}
	std::string getName() const { return name; }
	void setName(const std::string& newName) { name = newName; }
	~Person()
	{
		std::cout << "~Person destructor" << std::endl;
	}
};