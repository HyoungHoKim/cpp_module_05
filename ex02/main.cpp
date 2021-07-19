#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("Patrick");
    //RobotmyRequestForm* robot = new RobotmyRequestForm("Bob");
    //PresidentialPardonForm* pardon = new PresidentialPardonForm("Pef");

    Bureaucrat* bob = new Bureaucrat("Bob", 120);
    //Bureaucrat* james = new Bureaucrat("James", 33);
    //Bureaucrat* meg = new Bureaucrat("Meg", 1);

    shrub->beSigned(*bob);
    bob->signForm(*shrub);
    //bob->executeForm(*shrub);
    //testForm(james, robot);
    //testForm(meg, pardon);

    //testForm(bob, pardon);

    delete shrub;
    //delete robot;
    //delete pardon;

    delete bob;
    //delete james;
    //delete meg;

    return (0);
}