#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>

# include "Form.hpp" 

class Form;

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(const std::string _target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& _scf);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &_scf);

	void execute(Bureaucrat const &executor) const;
};

#endif