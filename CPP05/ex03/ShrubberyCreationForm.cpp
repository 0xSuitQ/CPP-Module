/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandroso <nandroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:28:30 by nandroso          #+#    #+#             */
/*   Updated: 2024/08/02 18:28:31 by nandroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm::AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	AForm::operator=(rhs);
	_target = rhs._target;
	return *this;
}

void	ShrubberyCreationForm::beExecuted(const Bureaucrat &bureaucrat) const {
	std::ofstream	outfile;
	
	outfile.open((_target + "_shrubbery").c_str());
	if (outfile.fail()) {
		std::cout << "Could not open output file" << std::endl;
		return ;
	}
	outfile << TREE;
	outfile.close();
	std::cout << bureaucrat.getName() << " successfully created a shrubbery" << std::endl;
}

AForm	*ShrubberyCreationForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	return (form);
}

const std::string	&ShrubberyCreationForm::getTarget() const {
	return (_target);
}


std::ostream	&operator<<(std::ostream &oStream, const ShrubberyCreationForm &form)
{
	return oStream << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExec();
}
