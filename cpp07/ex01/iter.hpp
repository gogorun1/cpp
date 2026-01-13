#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T_ARRAY, typename T_RETURN>
void iter(T_ARRAY *array, const size_t size, T_RETURN (*f)(T_ARRAY &))
{
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}

template <typename T_ARRAY, typename T_RETURN>
void iter(const T_ARRAY array[], const size_t size, T_RETURN (*f)(const T_ARRAY &))
{
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}

#endif