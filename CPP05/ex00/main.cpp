#include "Bureaucrat.hpp"

int main() {
	Bureaucrat n_bureaucrat("Nikita", 2);
	Bureaucrat a_bureaucrat("Andrey", 149);

	try {
		n_bureaucrat.decreaseGrade();
		n_bureaucrat.increaseGrade();
		n_bureaucrat.increaseGrade();
		n_bureaucrat.increaseGrade();
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		a_bureaucrat.decreaseGrade();
		a_bureaucrat.decreaseGrade();
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat n_bureaucrat("Noname", 0);
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat n_bureaucrat("Kriss", 150);
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}