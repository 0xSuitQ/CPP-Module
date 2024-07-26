#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Form;

class Intern {
public:
	Intern();
	Intern(const Intern &);
	~Intern();

	Intern	&operator=(const Intern &);

	AForm	*makeForm(const std::string &type, const std::string &target);
};

#endif
