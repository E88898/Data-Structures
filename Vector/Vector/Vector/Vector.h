#ifndef VECTOR_H
#define VECTOR_H

#include <string>

class Vector
{
	friend std::ostream& operator<<(std::ostream& out, const Vector& obj);
	friend std::istream& operator>>(std::istream& input, Vector& obj);
public:
	Vector();
	Vector(int size);
	Vector(int size, int element);
	Vector(const Vector& object);
	Vector& operator=(const Vector& object);

	int& operator[](int index);
	int operator[](int index) const;

	void push_back(int element);
	void insert(int index, int element);

	void pop_back();
	void remove(int index);

	~Vector();

	int getSize() const;
	bool empty() const;

	bool operator==(const Vector& obj);
	bool operator!=(const Vector& obj);
	bool operator<(const Vector& obj);
	bool operator>(const Vector& obj);

	void reserve(int number);

	struct VectorException
	{
		std::string s;
	};

private:
	int* _data;
	int _size;
	int _capacity;

	void validateSize();
	void handleFullCondition();
};

#endif