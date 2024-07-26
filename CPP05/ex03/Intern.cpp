#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

AForm	*Intern::makeForm(const std::string &type, const std::string &target) {
	AForm	*form;

	form = AForm::makeForm(type, target);
	if (!form)
		throw (AForm::InvalidFormException());
	else
		std::cout << "Intern creates form: " << form->getName() << " with target: " << form->getTarget() << std::endl;
	return form;
}
