#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	int _size;
	T *_array;

public:
	Array();
	Array(int n);
	Array(const Array<T> &other);
	Array<T> &operator=(const Array<T> &other);

	~Array();
};

#include "Array.tpp"

#endif