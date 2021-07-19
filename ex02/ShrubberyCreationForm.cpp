#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target)
: Form("Shrubbery Creation", 137, 145, _target)
{ }

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& _scf)
: Form(_scf)
{ }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &_scf)
{
	if (&_scf == this)
		return (*this);
	this->Form::operator=(_scf);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExec_grade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw NotAllowSignedException();

	std::ofstream file(std::string(this->getTarget() + "_shrubbery").c_str(),
		std::ios::out | std::ios::app);
	
	if (file.is_open())
	{	
        file << "			>X<				" << std::endl; 
        file << "	 		 A				" << std::endl;
        file << "			d$b				" << std::endl;
      	file << "		  .d$$b.			" << std::endl;
    	file << "		.d$i$$$$b.			" << std::endl;
       	file << "		   d$$@b			" << std::endl;
      	file << "		  d$$$ib			" << std::endl;
    	file << "		.d$$$$$$b			" << std::endl;
  		file << "	  .d$$@$$$$$$ib.		" << std::endl;
      	file << "		  d$$i$$b			" << std::endl;
     	file << "		 d$$$$@$b			" << std::endl;
  		file << "	  .d$@$$$$$$$@b.		" << std::endl;
		file << "   .d$$$$i$$$$$$$$$b.		" << std::endl;
        file <<	"			###				" << std::endl;
        file << "			###				" << std::endl;
        file << "			###				" << std::endl;
		
		file.close();
	}
}