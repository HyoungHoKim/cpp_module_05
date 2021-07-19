#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>

# include "Form.hpp" 

class Form;

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();

public:
	RobotomyRequestForm(const std::string _target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& _rrf);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &_rrf);

	void execute(Bureaucrat const &executor) const;
};

#endif