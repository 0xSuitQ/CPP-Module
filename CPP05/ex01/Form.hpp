/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandroso <nandroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:26:21 by nandroso          #+#    #+#             */
/*   Updated: 2024/08/02 18:26:33 by nandroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExec;

public:
	Form();
	Form(std::string name, int gradeToSing, int gradeToExec);
	Form(const Form &);
	~Form();

	Form &operator=(const Form &);

	std::string	getName() const;
	int			getGradeToSign() const;
	int			getGradeToExec() const;
	bool		getIsSigned() const;

	void	beSigned(Bureaucrat &bureaucrat);
	class GradeTooHighException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &oStream, const Form &form);


#endif