#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    srand(time(NULL));
	Intern someIntern;

	Bureaucrat bob("Bob", 1);
	std::cout << bob;
	Bureaucrat jim("Jim", 25);
	std::cout << jim << std::endl;

	Form *shrub = someIntern.makeForm("shrubbery creation", "Farm");
	std::cout << *shrub << std::endl;
	shrub->beSigned(jim);
	shrub->execute(jim);
    jim.executeForm(*shrub);

	Form *pres = someIntern.makeForm("presidential pardon", "police");
	std::cout << *pres << std::endl;
	pres->beSigned(bob);
	pres->execute(bob);
    bob.executeForm(*pres);

	Form *robot = someIntern.makeForm("robotomy request", "factory");
	std::cout << *robot;
	robot->beSigned(jim);
	robot->execute(jim);
	jim.executeForm(*robot);

	std::cout << "\n---\n" << std::endl;

	try
	{
		Form *ran = someIntern.makeForm("Random Form", "nobody");
		std::cout << ran << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	try
	{
		jim.executeForm(*pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	try
	{
		RobotomyRequestForm robot = RobotomyRequestForm("factory");
		std::cout << robot;
		robot.execute(bob);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("jim");
		std::cout << pres;
		bob.signForm(pres);
		pres.execute(jim);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("jim");
		std::cout << pres;
		bob.signForm(pres);
		jim.executeForm(pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\n---\n" << std::endl;

	delete shrub;
	delete pres;
	delete robot;

	return (0);
}