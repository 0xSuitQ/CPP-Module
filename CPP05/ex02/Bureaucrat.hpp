#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &);
	~Bureaucrat();

	Bureaucrat	&operator=(Bureaucrat const &rhs);

	std::string	getName(void) const;
	int 		getGrade(void) const;

	void	increaseGrade(void);
	void	decreaseGrade(void);

	void	signForm(AForm &form);
	void	executeForm(const AForm &form);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};
};

std::ostream &operator<<(std::ostream &oStream, const Bureaucrat &value);

#endif