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
	Bureaucrat high("HighRank", 1);
	Bureaucrat mid("MidRank", 50);
	Bureaucrat low("LowRank", 150);

	std::cout << "--- Testing ShrubberyCreationForm ---" << std::endl;
	ShrubberyCreationForm shrub("home");
	std::cout << shrub;
	
	try {
		low.executeForm(shrub); // fails: not signed
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}
	
	try {
		high.signForm(shrub); // successes
		std::cout << shrub;
		low.executeForm(shrub); // fails: grade too low
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try {
		high.executeForm(shrub); // accesses file output
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
	RobotomyRequestForm robo("Bender");
	std::cout << robo;

	try {
		mid.signForm(robo); // succeeds (50 < 72)
		mid.executeForm(robo); // fails (50 > 45)
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try {
		high.executeForm(robo); // succeeds
		high.executeForm(robo); // might succeed or fail (50% chance)
		high.executeForm(robo); // might succeed or fail
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
	PresidentialPardonForm pardon("Thief");

	try {
		low.signForm(pardon); // fails
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try {
		high.signForm(pardon); // succeeds
		high.executeForm(pardon); // succeeds
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	return 0;
}