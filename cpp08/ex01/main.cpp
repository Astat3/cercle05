/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:34:04 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/17 16:34:05 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::cout << "--- Subject Test ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n--- Large Test ---" << std::endl;
    Span largeSp(10005);
    std::vector<int> randomNumbers;
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (int i = 0; i < 10000; ++i) {
        randomNumbers.push_back(std::rand());
    }

    try {
        largeSp.addNumber(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Successfully added 10000 numbers using iterators." << std::endl;
        std::cout << "Shortest span: " << largeSp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << largeSp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Exception Tests ---" << std::endl;
    Span tinySp(1);
    tinySp.addNumber(42);
    try {
        tinySp.shortestSpan();
    } catch (std::exception &e) {
        std::cerr << "Caught (shortestSpan on size 1): " << e.what() << std::endl;
    }

    try {
        tinySp.addNumber(43);
    } catch (std::exception &e) {
        std::cerr << "Caught (adding past capacity): " << e.what() << std::endl;
    }

    return 0;
}
