#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &);

		void	beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &oStream, PresidentialPardonForm const &form);

#endif