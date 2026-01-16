#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char **)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}

// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}

// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror;
// 	return 0;
// }

#define TEST(x) std::cout << "============== Test: " << x << "==============" << std::endl

int main(int, char **)
{
	TEST("Different types");
	Array<int> numbers(4);
	Array<char> chars(3);
	Array<std::string> strings(2);

	for (int i = 0; i < 4; i++)
		numbers[i] = i * 10;

	for (int i = 0; i < 3; i++)
		chars[i] = 'A' + i;

	strings[0] = "Hello";
	strings[1] = "World";

	std::cout << "Int array: " << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << numbers[i] << std::endl;

	std::cout << "Char array: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << chars[i] << std::endl;

	std::cout << "String array: " << std::endl;
	for (int i = 0; i < 2; i++)
		std::cout << strings[i] << std::endl;

	TEST("Default constructor");
	Array<char> empty_array;
	if (empty_array.size() == 0)
		std::cout << "Array size is 0" << std::endl;

	TEST("Copy constructor");
	Array<char> chars_copy(chars);
	std::cout << "Char array copy: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << chars_copy[i] << std::endl;

	TEST("Assignment operator");
	Array<int> copy = numbers;
	std::cout << "Copy assignment: " << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << std::endl;

	TEST("Out of bounds");
	try
	{
		numbers[10] = 999;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << '\n';
	}

	return 0;
}