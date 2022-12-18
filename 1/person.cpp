#include <string>
#include "person.h"
#include <iostream>



Person::Person()
{
	name = "none";
	age = 0;
}
Person::Person(std::string name, int age)
{
	this->name = name;
	this->age = age;
}
std::string Person :: getName() const
{
	return name;
}
int Person :: getAge() const
{
	return age;
}

Person** copy(Person** buf1, int lena)
{
	static Person** buf2 = new Person*[lena];
	for(int i = 0; i < lena; i++) buf2[i] = buf1[i];
	return buf2;
}

People::People()
{
	numPeople = 0;
	lena = 10;
	oldestPerson = Person("none", -1);
	youngestPerson = Person("none", 1000);
	allPeople = new Person*[lena];
}

void People::addPerson(Person p)
{
	if(numPeople + 1 > lena)
	{
		Person** buf = copy(allPeople, lena);
		delete[] allPeople;
		allPeople = new Person*[lena+10];
		for(int i = 0; i < lena; i ++)
			allPeople[i] = buf[i];
		lena = lena + 10;
		delete[] buf;
	}
	allPeople[numPeople] = &p;
	numPeople += 1;
	if(p.getAge() > oldestPerson.getAge())
		oldestPerson = p;
	if(p.getAge() < youngestPerson.	getAge())
		youngestPerson = p;
}

int People::getNumPeople() const
{
	return numPeople;
}
Person People::getOldestPerson() const
{
	return oldestPerson;
}
Person People::getYoungestPerson() const
{
	return youngestPerson;
}