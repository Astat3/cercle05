/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 04:51:19 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 04:51:22 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));

	Intern someRandomIntern;
	AForm* rrf;
	AForm* scf;
	AForm* ppf;
	AForm* unknown;

	std::cout << "\n--- Intern creating forms ---" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "home");
	ppf = someRandomIntern.makeForm("presidential pardon", "Thief");
	unknown = someRandomIntern.makeForm("unknown form", "target");

	std::cout << "\n--- Bureaucrats interacting with forms ---" << std::endl;
	Bureaucrat boss("Boss", 1);
	
	if (rrf) {
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}
	if (scf) {
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}
	if (ppf) {
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}
	if (unknown) {
		delete unknown; // Should be null anyway
	}

	return 0;
}