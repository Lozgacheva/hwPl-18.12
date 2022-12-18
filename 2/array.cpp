#include <iostream>
#include "array.h"


PolyArray :: PolyArray()
{
	size = 10;
	count = 0;
	arr = new Base*[size];
}

PolyArray :: ~PolyArray()
{
	delete[] arr;
}

//конструктор копирования
PolyArray :: PolyArray(const PolyArray& other)
{
	size = other.get_size();
	count = other.get_count();
	arr = new Base*[size];
	Base** other_arr = other.get_arr();
	for(int i = 0; i < count; i++)
		arr[i] = other_arr[i];
}

//делает копию массива в динмической памяти
Base** copy(Base** arr, int size)
{
	static Base** buf = new Base*[size];
	for(int i = 0; i < size; i++) buf[i] = arr[i];
	return buf;
}

void PolyArray :: push_back(Base* value)
{
	if(count + 1 > size)
	{
		Base** buf = copy(arr, size);
		delete[] arr;
		arr = new Base*[size + 10];
		for(int i = 0; i < count; i ++)
			arr[i] = buf[i];
		size = size + 10;
		delete[] buf;
	}
	arr[count] = value;
	count += 1;
}

Base* PolyArray :: get(int index)
{
	if(index > count - 1 || index < 0)
	{
		std::cout << "There's no object with index " << index << std::endl;
		exit(EXIT_FAILURE);
	}
	return arr[index];
}

void PolyArray :: set(int index, Base* value)
{
	if(index > count - 1 || index < 0)
	{
		std::cout << "There's no object with index " << index << std::endl;
		exit(EXIT_FAILURE);
	}
	arr[index] = value;
}

int PolyArray :: get_size() const
{
	return size;
}

int PolyArray :: get_count() const
{
	return count;
}

Base** PolyArray :: get_arr() const
{
	return arr;
}