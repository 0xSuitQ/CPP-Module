#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	ShrubberyCreationForm shrubbery("main");
	RobotomyRequestForm robotomy("Jeniffer");
	PresidentialPardonForm pardon("Joe");
	Bureaucrat rick("Rick", 150);
	Bureaucrat bob("Bob", 120);
	Bureaucrat alan("Alan", 3);
	
	/* Try to execute forms without being signed */
	{
		try {
			std::cout << rick << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			rick.executeForm(shrubbery);
			rick.executeForm(robotomy);
			rick.executeForm(pardon);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign form and try to execute without enough grade */
	{
		try {
			std::cout << rick << std::endl;
			std::cout << bob << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			shrubbery.beSigned(bob);
			rick.executeForm(shrubbery);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign forms and execute them */
	{
		try {
			robotomy.beSigned(alan);
			pardon.beSigned(alan);
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			
			std::cout << "\n --------------------- \n\n";
			alan.executeForm(shrubbery);
			std::cout << "\n --------------------- \n\n";
			alan.executeForm(robotomy);
			std::cout << "\n --------------------- \n\n";
			alan.executeForm(pardon);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
