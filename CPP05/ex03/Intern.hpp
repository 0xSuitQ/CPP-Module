/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandroso <nandroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:28:16 by nandroso          #+#    #+#             */
/*   Updated: 2024/08/02 18:28:17 by nandroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
