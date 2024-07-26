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

	void	beExecuted(const Bureaucrat &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &oStream, const RobotomyRequestForm &form);

#endif
