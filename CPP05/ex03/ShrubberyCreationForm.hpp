#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

#define TREE "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n"

class Bureaucrat;

class ShrubberyCreationForm: public AForm {
private:
	std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &);

	void				beExecuted(const Bureaucrat &bureaucrat) const;
	static	AForm		*makeForm(AForm *form, const std::string &type, const std::string &target);
	const std::string	&getTarget() const;
};

std::ostream	&operator<<(std::ostream &oStream, const ShrubberyCreationForm &form);

#endif