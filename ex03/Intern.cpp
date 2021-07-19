#include "Intern.hpp"

Form *createShrubberyForm(const std::string &target);
Form *createRobotoForm(const std::string &target);
Form *createPresidentialForm(const std::string &target);

Intern::Intern()
{ }

Intern::Intern(const Intern& _intern)
{
	(void)_intern;
}

Intern::~Intern()
{ }

Intern &Intern::operator=(const Intern &_intern)
{
	if (this == &_intern)
		return (*this);
	return (*this);
}

Form* Intern::makeForm(const std::string &form_name, const std::string &target)
{
	std::string targets[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *(*fp[3])(const std::string &);
	fp[0] = createShrubberyForm;
	fp[1] = createRobotoForm;
	fp[2] = createPresidentialForm;

	for (int i = 0; i < 3; i++)
	{
		if (targets[i] == form_name)
		{
			std::cout << "Intern creates " << targets[i] << std::endl;
			return (fp[i](target));
		}
	}
	throw Intern::CannotCreateForm();
	return (nullptr);
}

const char *Intern::CannotCreateForm::what() const throw()
{
	return ("Not Correct Form Name, Cannot Create Form!!!!");
}

Form *createShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form *createRobotoForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form *createPresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

