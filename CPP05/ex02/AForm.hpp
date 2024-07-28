#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExec;

public:
	AForm();
	AForm(std::string name, int gradeToSing, int gradeToExec);
	AForm(const AForm &);
	virtual ~AForm();

	AForm &operator=(const AForm &);

	std::string	getName() const;
	int			getGradeToSign() const;
	int			getGradeToExec() const;
	bool		getIsSigned() const;

	void			beSigned(Bureaucrat &bureaucrat);
	void			execute(const Bureaucrat &executor) const;
	virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;

	class GradeTooHighException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};
	class FormNotSignedException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &oStream, const AForm &AForm);


#endif