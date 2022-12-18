#include <iostream>
#include "array.h"

int main()
{
	PolyArray array;
	array.push_back(new DerivedA());
	array.push_back(new DerivedB());
	array.push_back(new DerivedA());
	array.push_back(new DerivedB());

	for(int i = 0; i < array.get_count(); i++)
	{
		array.get(i)->print();
	}

	std::cout << std::endl;

	PolyArray array2 = PolyArray(array);
	array2.push_back(new DerivedA());
	array2.set(1, new DerivedA());

	for(int i = 0; i < array2.get_count(); i++)
	{
		array2.get(i)->print();
	}
	return 0;
}