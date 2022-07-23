#include <iostream>
#include <string>
using namespace std;

class Pet
{
	string name;
public:
	Pet(string n = "no name yet") : name(n) {}
	virtual const string cry()=0;
	virtual ~Pet() { cout << "~Pet()" << endl; }
	friend ostream& operator <<(ostream& out, Pet& pet);
};

class Dog : public Pet
{
public:
	Dog(string n = "no name yet") : Pet(n) {}
	virtual const string cry() { return "woof"; }
	virtual ~Dog() { cout << "~Dog()" << endl; }
};

class Cat : public Pet
{
public:
	Cat(string n = "no name yet") : Pet(n) {}
	virtual const string cry() { return "meow"; }
	virtual ~Cat() { cout << "~Cat()" << endl; }
};

int main()
{
	Dog* pdog = new Dog("Tiny");
	Cat* pcat = new Cat("Candy");
	Pet* ppet;

	ppet = pdog;
	cout << *ppet << endl;
	delete pdog;

	ppet = pcat;
	cout << *ppet << endl;
	delete pcat;

	return 0;
}

const string cry (Pet& p)
{
	return p.cry();
}

ostream& operator <<(ostream& out, Pet& pet)
{
	out << pet.name << " crys " << pet.cry();
	return out;
}

