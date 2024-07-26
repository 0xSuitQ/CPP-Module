#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct	Data {
	std::string name;
	int			age;
} Data;

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();
	Serializer &operator=(const Serializer &rhs);
};

#endif