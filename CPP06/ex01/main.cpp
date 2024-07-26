#include "Serializer.hpp"

int main() {
	Data data;
	data.name = "Ali";
	data.age = 19;

	Data *dataptr;
	uintptr_t uintptr;

	std::cout << "data: " << data.name << " is " << data.age << std::endl << std::endl;

	uintptr = Serializer::serialize(&data);
	std::cout << "Serializing data in uintptr" << std::endl;
	std::cout << "data: " << data.name << " is " << data.age << std::endl << std::endl;

	dataptr = Serializer::deserialize(uintptr);
	std::cout << "data:   " << data.name << " is " << data.age << std::endl;
	std::cout << "dataptr: " << dataptr->name << " is " << dataptr->age << std::endl;
}
