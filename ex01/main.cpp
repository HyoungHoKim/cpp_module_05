#include "Bureaucrat.hpp"

int main(void)
{
	Form* test1 = new Form("test1", 10, 30);
    Form* toHigh;
    Form* toLow;
    
    std::cout << *test1;
    
    try
    {
       toHigh = new Form("ToHigh", 0, 20);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
       toLow = new Form("toLow", 10, 199);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat* bob = new Bureaucrat("Bob", 5);
    
    std::cout << *bob;

    test1->beSigned(*bob);

    std::cout << *test1;

    bob->signForm(*test1);

    Form* test2 = new Form("test2", 1, 1);
    Bureaucrat* jim = new Bureaucrat("Jim", 12);

    jim->signForm(*test2);
    
    delete test1;
    delete bob;
    delete test2;
    delete jim;
}