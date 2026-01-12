#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <string>
#include <stdint.h>

#define PRINT(x) std::cout << x << std::endl

struct Data
{
	int id;
	std::string name;
	double value;
};

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif