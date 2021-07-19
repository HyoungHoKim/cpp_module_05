#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool _signed;
	const int exec_grade;
	const int signed_grade;
	const std::string target;

	Form();
public:
	Form(const std::string _name, const int _exec_grade, const int _signed_grade);
	Form(const std::string _name, const int _exec_grade,
		const int _signed_grade, const std::string _target);
	virtual ~Form();
	Form(const Form &_form);
	Form &operator=(const Form &_form);

	const std::string &getName(void) const;
	bool getSigned(void) const;
	int getExec_grade(void) const;
	int getSigned_grade(void) const;
	const std::string &getTarget(void) const;

	void beSigned(Bureaucrat &_bc);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class NotAllowSignedException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &_form);

#endif