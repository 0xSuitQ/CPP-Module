/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandroso <nandroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:28:23 by nandroso          #+#    #+#             */
/*   Updated: 2024/08/02 18:28:24 by nandroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &);

		void				beExecuted(Bureaucrat const &bureaucrat) const;
		static	AForm		*makeForm(AForm *form, const std::string &type, const std::string &target);
		const std::string	&getTarget() const;
};

std::ostream	&operator<<(std::ostream &oStream, PresidentialPardonForm const &form);

#endif