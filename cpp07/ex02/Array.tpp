#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array() : _size(0)
{
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size)
{
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
	{
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

// operators

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _array;
		_array = new T[other._size];
		this->_size = other._size;
		for (unsigned int i = 0; i < _size; ++i)
		{
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return "Out of range!";
}

template <typename T>
T &Array<T>::operator[](int index)
{
	if (index >= (int)_size || index < 0)
	{
		throw OutOfRangeException();
	}
	return _array[index];
}

// members
template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}