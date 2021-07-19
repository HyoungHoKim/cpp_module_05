#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>

# include "Form.hpp" 

class Form;

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();

public:
	PresidentialPardonForm(const std::string _target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& _ppf);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &_ppf);

	void execute(Bureaucrat const &executor) const;
};

#endif