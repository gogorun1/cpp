#include "Array.hpp"

template<typename T >
Array<T>::Array(): _size(0)
{
}

template<typename T >
Array<T>::Array(int n): _size(n)
{
	_array = new T[n];
}

template<typename T >
Array<T>::Array(const Array<T> &other):_size(other._size)
{

}