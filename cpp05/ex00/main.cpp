/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:39:34 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/17 20:21:56 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- Test 1: Valid Bureaucrat ---" << std::endl;
	try {
		Bureaucrat hermes("Hermes", 100);
		std::cout << hermes << std::endl;
		hermes.increment();
		std::cout << hermes << std::endl;
		hermes.decrement();
		std::cout << hermes << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Invalid Too High Creation ---" << std::endl;
	try {
		Bureaucrat boss("Boss", 0);
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Invalid Too Low Creation ---" << std::endl;
	try {
		Bureaucrat intern("Intern", 151);
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Increment past bound ---" << std::endl;
	try {
		Bureaucrat maxB("Max", 1);
		std::cout << maxB << std::endl;
		maxB.increment(); // Should throw
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Decrement past bound ---" << std::endl;
	try {
		Bureaucrat minB("Min", 150);
		std::cout << minB << std::endl;
		minB.decrement(); // Should throw
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}