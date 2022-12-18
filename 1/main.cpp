#include <string>
#include "person.h"
#include <iostream>
#include <cassert>

int main()
{
	People people;
	people.addPerson(Person("Alice", 20));
	people.addPerson(Person("Bob", 30));
	people.addPerson(Person("Carol", 25));

	assert(people.getNumPeople() == 3);
	assert(people.getOldestPerson().getName() == "Bob");
	assert(people.getYoungestPerson().getName() == "Alice");
	return 0;
}