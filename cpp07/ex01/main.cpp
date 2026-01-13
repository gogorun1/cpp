#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void f(T &a)
{
	std::cout << "array element: " << a << std::endl;
}

int main()
{
	const size_t size1 = 4;
	int arr1_1[size1] = {1, 2, 3, 4};
	const int arr1_2[size1] = {1, 2, 3, 4};

	std::cout << "============= Test       Int =============" << std::endl;
	iter<int, void>(arr1_1, size1, &f);
	std::cout << "============= Test const Int =============" << std::endl;

	iter<int, void>(arr1_2, size1, &f);

	const size_t size2 = 6;
	char arr2_1[size2] = {'a', 'b', 'c', 'd', 'e', 'f'};
	const char arr2_2[size2] = {'h', 'i', 'j', 'k', 'l', 'm'};
	
	std::cout << "============= Test       Char =============" << std::endl;
	iter<char, void>(arr2_1, size2, &f);
	std::cout << "============= Test Const Char =============" << std::endl;
	iter<char, void>(arr2_2, size2, &f);

	const size_t size3 = 3;
	std::string arr3_1[size3] = {"hello", "world", "!"};
	const std::string arr3_2[size3] = {"hello", "world", "!"};
	
	std::cout << "============= Test       String =============" << std::endl;
	iter<std::string, void>(arr3_1, size3, &f);
	std::cout << "============= Test Const String =============" << std::endl;
	iter<std::string, void>(arr3_2, size3, &f);
}