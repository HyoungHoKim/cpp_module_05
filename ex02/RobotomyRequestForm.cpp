#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string _target)
: Form("Roboto myRequest", 45, 72, _target)
{ }

RobotomyRequestForm::~RobotomyRequestForm()
{ }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& _rrf)
: Form(_rrf)
{ }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &_rrf)
{
	if (&_rrf == this)
		return (*this);
	this->Form::operator=(_rrf);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExec_grade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw NotAllowSignedException();
	std::cout << "Zing...Zing...Zing..." << std::endl;
	if ((rand() % 100) > 50)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotomization is a failure" << std::endl;
}