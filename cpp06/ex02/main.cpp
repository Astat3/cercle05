/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:32:51 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/02 17:32:53 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "--- Generating Objects ---\n";
    Base* obj1 = generate();
    Base* obj2 = generate();
    Base* obj3 = generate();

    std::cout << "\n--- Testing identify(Base* p) ---\n";
    std::cout << "obj1 is formally identified as: ";
    identify(obj1);
    std::cout << "obj2 is formally identified as: ";
    identify(obj2);
    std::cout << "obj3 is formally identified as: ";
    identify(obj3);

    std::cout << "\n--- Testing identify(Base& p) ---\n";
    std::cout << "obj1 is formally identified as: ";
    identify(*obj1);
    std::cout << "obj2 is formally identified as: ";
    identify(*obj2);
    std::cout << "obj3 is formally identified as: ";
    identify(*obj3);

    // Clean up memory
    delete obj1;
    delete obj2;
    delete obj3;

    return 0;
}
