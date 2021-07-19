#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& _intern);
	~Intern();
	Intern &operator=(const Intern &op);

	Form* makeForm(const std::string &form_name, const std::string &target);

	class CannotCreateForm : public std::exception {
		virtual const char *what() const throw();
	};
};

#endif
