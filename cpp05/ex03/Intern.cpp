#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	(void)cpy;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	std::cout << "Intern assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

static AForm *makeShrub(std::string target) { return new ShrubberyCreationForm(target); }
static AForm *makeRobo(std::string target) { return new RobotomyRequestForm(target); }
static AForm *makePardon(std::string target) { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(*funcs[])(std::string target) = {
		&makeShrub,
		&makeRobo,
		&makePardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return funcs[i](target);
		}
	}
	
	std::cerr << "Intern could not locate the required form (" << name << ")." << std::endl;
	return NULL;
}
