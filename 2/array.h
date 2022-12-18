class Base
{
public:
	virtual void print() const = 0;
};


class DerivedA : public Base
{
public:
	void print() const
	{
		std::cout << "A" << std::endl;
	}
};

class DerivedB : public Base
{
public:
	void print() const
	{
		std::cout << "B" << std::endl;
	}
};

class PolyArray
{
public:
	PolyArray();
	~PolyArray();
	PolyArray(const PolyArray& other);
	void push_back(Base* value);
	Base* get(int index);
	void set(int index, Base* value);
// Вместо ф-ии size(), как написано в задании, у меня get_count()
	int get_count() const;
	int get_size() const;
	Base** get_arr() const;
private:
	int size;//размер массива
	int count;//кол-во элементов в массиве
	Base** arr;
};