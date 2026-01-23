#include <iostream>
#include "easyfind.hpp"

#define MAX_VAL 750

int main(void)
{
	std::vector<int> vec;
	for(int i = 0; i < MAX_VAL; i++)
	{
		vec.push_back(i);
		// if (i % 10 == 0)
		// 	std::cout << i << "vec.capacity() = " << vec.capacity() << std::endl;
	}

	try
	{
		easyfind(vec, 42);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		easyfind(vec, 1000);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}