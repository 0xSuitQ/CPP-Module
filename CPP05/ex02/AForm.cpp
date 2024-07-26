#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("None"), _isSigned(0), _gradeToSign(30), _gradeToExec(30) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign < 1)
		throw (AForm::GradeTooHighException());
	else if (_gradeToSign > 150)
		throw (AForm::GradeTooLowException());
	if (_gradeToExec < 1)
		throw (AForm::GradeTooHighException());
	else if (_gradeToExec > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& src) {
    if (this != &src) {
        _isSigned = src._isSigned;
    }
    return *this;
}

std::string	AForm::getName() const {
	return _name;
}

int	AForm::getGradeToSign() const {
	return _gradeToSign;
}

int	AForm::getGradeToExec() const {
	return _gradeToExec;
}

bool	AForm::getIsSigned() const {
	return _isSigned;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw (AForm::GradeTooLowException());
	else {
		_isSigned = 1;
		std::cout << bureaucrat.getName() << " successfully signed " << _name << std::endl;
	}
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > _gradeToSign)
		throw (AForm::GradeTooLowException());
	else {
		std::cout << executor.getName() << " executes form: " << _name << std::endl;
		beExecuted(executor);
	}
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream	&operator<<(std::ostream &oStream, const AForm &form) {
	return oStream << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExec();
}

