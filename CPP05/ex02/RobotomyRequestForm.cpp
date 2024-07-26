#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("none") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm::AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	AForm::operator=(src);
	_target = src._target;
	return *this;
}

void	RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const {
	int	success;

	srand((unsigned) time(NULL));
	success = rand() % 2;
	(void)bureaucrat;
	if (success)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
}

std::ostream	&operator<<(std::ostream &oStream, const RobotomyRequestForm &form)
{
	return oStream << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExec();
}
