#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat* test1 = new Bureaucrat("test1", 2);
    Bureaucrat* test2 = new Bureaucrat("test2", 149);
    
    // Test --
    try
    {
        std::cout << *test1;
        test1->increment_grade();
        std::cout << test1->getName() << " upgraded!!! " << std::endl;
        std::cout << *test1;
        test1->increment_grade();
    }
    catch (std::exception & e)
    {
        std::cerr << "1. Exception : " << e.what() << std::endl;
    }

    // Test ++
    try
    {
        std::cout << *test2;
        test2->decrement_grade();
        std::cout << test2->getName() << " downgraded!" << std::endl;
        std::cout << *test2;
        test2->decrement_grade();
    }
    catch (std::exception & e)
    {
        std::cerr << "2. Exception : " << e.what() << std::endl;
    }

    Bureaucrat* test3;
    Bureaucrat* test4;

    // Test ToHigh
    try
    {
        test3 = new Bureaucrat("test3", 0);
    }
    catch (std::exception & e)
    {
        std::cerr << "3. Exception : " << e.what() << std::endl;
    }
    
    try
    {
        test4 = new Bureaucrat("test4", 420);
    }
    catch (std::exception & e)
    {
        std::cerr << "4. Exception : " << e.what() << std::endl;
    }
    
    delete test1;
    delete test2;
}