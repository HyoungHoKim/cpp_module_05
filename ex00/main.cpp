#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat test("test", 100);
	std::cout << test << std::endl;
	test.increment_grade();
	std::cout << test << std::endl;
	test.decrement_grade();
	std::cout << test << std::endl;
	return (0);
}