#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string _target)
: Form("Presidential Pardon", 5, 25, _target)
{ }

PresidentialPardonForm::~PresidentialPardonForm()
{ }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& _ppf)
: Form(_ppf)
{ }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &_ppf)
{
	if (&_ppf == this)
		return (*this);
	this->Form::operator=(_ppf);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExec_grade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw NotAllowSignedException();
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}