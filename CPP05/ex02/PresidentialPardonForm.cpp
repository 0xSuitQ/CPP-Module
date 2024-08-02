/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandroso <nandroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:27:39 by nandroso          #+#    #+#             */
/*   Updated: 2024/08/02 18:27:40 by nandroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25, 5), _target("none") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm::AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	AForm::operator=(rhs);
	_target = rhs._target;
	return *this;
}

void	PresidentialPardonForm::beExecuted(const Bureaucrat &bureaucrat) const {
	(void)bureaucrat;
	std::cout << _target << " has been pardoned by Joe Bidon" << std::endl;
}

std::ostream	&operator<<(std::ostream &oStream, const PresidentialPardonForm &form) {
	return oStream << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExec();
}
