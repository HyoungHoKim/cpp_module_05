#include "Form.hpp"

Form::Form(const std::string _name, const int _exec_grade, const int _signed_grade)
: name(_name), exec_grade(_exec_grade), signed_grade(_signed_grade)
{
	if (this->exec_grade > 150 || this->signed_grade > 150)
		throw Form::GradeTooLowException();
	else if (this->exec_grade < 1 || this->signed_grade < 1)
		throw Form::GradeTooHighException();
	this->_signed = false;
}

Form::Form(const std::string _name, const int _exec_grade,
	const int _signed_grade, const std::string _target)
: name(_name), exec_grade(_exec_grade), signed_grade(_signed_grade), target(_target)
{
	if (this->exec_grade > 150 || this->signed_grade > 150)
		throw Form::GradeTooLowException();
	else if (this->exec_grade < 1 || this->signed_grade < 1)
		throw Form::GradeTooHighException();
	this->_signed = false;
}

Form::~Form()
{ }

Form::Form(const Form &_form)
: name(_form.getName()), _signed(_form.getSigned()), exec_grade(_form.getExec_grade()),
signed_grade(_form.getSigned_grade()), target(_form.getTarget())
{
	if (this->exec_grade > 150 || this->signed_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->exec_grade < 1 || this->signed_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Form &Form::operator=(const Form &_form)
{
	if (&_form == this)
		return (*this);
	if (this->exec_grade > 150 || this->signed_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->exec_grade < 1 || this->signed_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_signed = _form.getSigned();
	return (*this);
}

const std::string &Form::getName(void) const
{
	return (this->name);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

int Form::getExec_grade(void) const
{
	return (this->exec_grade);
}

int Form::getSigned_grade(void) const
{
	return (this->signed_grade);
}

const std::string &Form::getTarget(void) const
{
	return (this->target);
}

void Form::beSigned(Bureaucrat &_bc)
{
	if (this->signed_grade >= _bc.getGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!!!!");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!!!!");
}

const char *Form::NotAllowSignedException::what() const throw()
{
	return ("Not Allow Signed!!!!");
}

std::ostream &operator<<(std::ostream &os, const Form &_form)
{
	std::cout << "Form Name : " << _form.getName() << std::endl;
	std::cout << "Form Signed : " << _form.getSigned() << std::endl;
	std::cout << "Form Exec_grade : " << _form.getExec_grade() << std::endl;
	std::cout << "Form Signed_grade : " << _form.getSigned_grade() << std::endl;
	return (os);
}