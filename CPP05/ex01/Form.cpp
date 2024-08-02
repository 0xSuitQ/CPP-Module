/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandroso <nandroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:26:19 by nandroso          #+#    #+#             */
/*   Updated: 2024/08/02 18:26:20 by nandroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("None"), _isSigned(0), _gradeToSign(30), _gradeToExec(30) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign < 1)
		throw (Form::GradeTooHighException());
	else if (_gradeToSign > 150)
		throw (Form::GradeTooLowException());
	if (_gradeToExec < 1)
		throw (Form::GradeTooHighException());
	else if (_gradeToExec > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;
}

Form::~Form() {}

Form& Form::operator=(const Form& src) {
    if (this != &src) {
        _isSigned = src._isSigned;
    }
    return *this;
}

std::string	Form::getName() const {
	return _name;
}

int	Form::getGradeToSign() const {
	return _gradeToSign;
}

int	Form::getGradeToExec() const {
	return _gradeToExec;
}

bool	Form::getIsSigned() const {
	return _isSigned;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw (Form::GradeTooLowException());
	else {
		_isSigned = 1;
		std::cout << bureaucrat.getName() << " successfully signed " << _name << std::endl;
	}
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream	&operator<<(std::ostream &oStream, const Form &form) {
	return oStream << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExec();
}

