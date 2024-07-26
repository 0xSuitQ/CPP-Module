#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &);
	~RobotomyRequestForm();

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &);

	void				beExecuted(const Bureaucrat &bureaucrat) const;
	static	AForm		*makeForm(AForm *form, const std::string &type, const std::string &target);
	const std::string	&getTarget() const;
};

std::ostream	&operator<<(std::ostream &oStream, const RobotomyRequestForm &form);

#endif
