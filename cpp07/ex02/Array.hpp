#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	unsigned int _size;
	T *_array;

public:
	// OCF
	Array();
	Array(unsigned int n);
	Array(const Array<T> &other);
	~Array();

	// operators
	Array<T> &operator=(const Array<T> &other);
	T &operator[](int index);

	// members
	unsigned int size() const;

	// // execptions
	class OutOfRangeException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif