#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		stan;
	AForm		*form;
	Bureaucrat	kim("Kim", 50);

	// Test how all forms are created properly execpt for the last one
	try {
		form = stan.makeForm("robotomy request", "Rick");
		delete form;
		form = stan.makeForm("shrubbery creation", "Danny");
		delete form;
		form = stan.makeForm("presidential pardon", "Cris");
		delete form;
		form = stan.makeForm("random request", "Pi");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Test some Actions with available form
	std::cout << "------------------------------------" << std::endl;
	form = stan.makeForm("shrubbery creation", "Dizzy");
	form->beSigned(kim);
	kim.executeForm(*form);
	delete form;
	std::cout << "------------------------------------" << std::endl;
	form = stan.makeForm("presidential pardon", "Wingman");
	kim.signForm(*form);
	kim.executeForm(*form);
	delete form;
}
