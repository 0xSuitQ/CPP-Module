#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bob"), _grade(50) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::increaseGrade() {
	if (_grade <= 1)
		throw(Bureaucrat::GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decreaseGrade() {
	if (_grade >= 150)
		throw(Bureaucrat::GradeTooLowException());
	_grade++;
}

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &oStream, const Bureaucrat &value) {
	return oStream << "Name: " << value.getName() << " Grade: " << value.getGrade();
}