#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	const size_t _size;
	T _array[_size];

public:
	Array();
	~Array();
};

Array::Array()
{
}

Array::~Array()
{
}

#endif