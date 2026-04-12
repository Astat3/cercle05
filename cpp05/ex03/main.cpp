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
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));

	std::cout << "--- Testing ShrubberyCreationForm ---" << std::endl;
	try
	{
		Bureaucrat high("HighRank", 1);
		Bureaucrat low("LowRank", 150);
		ShrubberyCreationForm shrub("home");

		std::cout << shrub;
		low.executeForm(shrub); // fails: not signed
		
		high.signForm(shrub); // successes
		std::cout << shrub;

		low.executeForm(shrub); // fails: grade too low
		high.executeForm(shrub); // accesses file output
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
	try
	{
		Bureaucrat mid("MidRank", 50);
		RobotomyRequestForm robo("Bender");

		std::cout << robo;
		mid.signForm(robo); // succeeds (50 < 72)
		mid.executeForm(robo); // fails (50 > 45)
		
		Bureaucrat high("HighRank", 1);
		high.executeForm(robo); // succeeds
		high.executeForm(robo); // might succeed or fail (50% chance)
		high.executeForm(robo); // might succeed or fail
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
	try
	{
		Bureaucrat superHigh("President", 1);
		Bureaucrat peon("Peon", 150);
		PresidentialPardonForm pardon("Thief");

		peon.signForm(pardon); // fails
		superHigh.signForm(pardon); // succeeds
		superHigh.executeForm(pardon); // succeeds
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	return 0;
}