#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    srand(time(NULL));
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("Farm");
    RobotomyRequestForm* robot = new RobotomyRequestForm("Factory");
    PresidentialPardonForm* pardon = new PresidentialPardonForm("Army");

    Bureaucrat* bob = new Bureaucrat("Bob", 120);
    Bureaucrat* jim = new Bureaucrat("Jim", 140);
    Bureaucrat* james = new Bureaucrat("James", 33);
    Bureaucrat* lisa = new Bureaucrat("Lisa", 1);

    std::cout << "------------ shrub ------------" << std::endl;
    shrub->beSigned(*bob);
    shrub->execute(*bob);
    bob->executeForm(*shrub);
    shrub->beSigned(*jim);
    try
    {
        shrub->execute(*jim);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        jim->executeForm(*shrub);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "------------ robot ------------" << std::endl;
    robot->beSigned(*james);
    robot->execute(*james);
    james->executeForm(*robot);
    try
    {
        robot->beSigned(*jim);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        robot->execute(*jim);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        jim->executeForm(*robot);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "------------ pardon ------------" << std::endl;
    pardon->beSigned(*lisa);
    pardon->execute(*lisa);
    lisa->executeForm(*pardon);
    try
    {
        pardon->beSigned(*jim);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        pardon->execute(*jim);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        jim->executeForm(*robot);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete shrub;
    delete robot;
    delete pardon;

    delete bob;
    delete jim;
    delete james;
    delete lisa;

    return (0);
}