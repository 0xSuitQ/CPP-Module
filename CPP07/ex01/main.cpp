#include "iter.hpp"

int main() {
	std::string str = "Hello World";

	iter(&str[0], str.length(), to_upper);
}