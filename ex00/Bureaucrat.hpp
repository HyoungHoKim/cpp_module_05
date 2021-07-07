#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
	Bureaucrat();
	const std::string name;
	int grade;
public:
	Bureaucrat(std::string _name, int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &_bc);
	Bureaucrat &operator=(const Bureaucrat &_bc);

	const std::string &getName(void) const;
	int getGrade(void) const;

	void increment_grade(void);
	void decrement_grade(void);

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &_bc);

#endif