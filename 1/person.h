class Person
{
public:
	Person(std::string, int);
	Person();
	std::string getName() const;
	int getAge() const;
private:
	std::string name;
	int age;	
};


class People
{
public:
	People();
	void addPerson(Person);
	int getNumPeople() const;
	Person getOldestPerson() const;
	Person getYoungestPerson() const;
private:
	int numPeople;
	int lena;
	Person oldestPerson;
	Person youngestPerson;
	Person** allPeople;
};