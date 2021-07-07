#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string _name, int _grade)
: name(_name)
{ 
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = _grade;
}

Bureaucrat::~Bureaucrat()
{ }

Bureaucrat::Bureaucrat(const Bureaucrat &_bc)
: name(_bc.getName())
{
	if (_bc.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_bc.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = _bc.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &_bc)
{
	if (this == &_bc)
		return (*this);
	if (_bc.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_bc.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = _bc.getGrade();
	return (*this);
}

const std::string &Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::increment_grade(void)
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
		
}

void Bureaucrat::decrement_grade(void)
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High!!!!";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!!!!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &_bc)
{
	os << _bc.getName() << ", bureaucrat grade " << _bc.getGrade() <<"." << std::endl;
	return (os);
}