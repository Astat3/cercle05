/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:39:34 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 04:14:33 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--- Test 1: Valid Form Creation & Signing ---" << std::endl;
	try {
		Bureaucrat hermes("Hermes", 100);
		Form easy("EasyForm", 100, 100);
		std::cout << hermes << std::endl;
		std::cout << easy << std::endl;
		
		hermes.signForm(easy);
		std::cout << easy << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}
	
	std::cout << "\n--- Test 2: Form Grade Too High Creation ---" << std::endl;
	try {
		Form tooHigh("TooHighForm", 0, 100);
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Test 3: Form Grade Too Low Creation ---" << std::endl;
	try {
		Form tooLow("TooLowForm", 100, 151);
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Test 4: Bureaucrat Grade Too Low To Sign ---" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		Form hardForm("HardForm", 10, 10);
		intern.signForm(hardForm);
	} catch(const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	return 0;
}