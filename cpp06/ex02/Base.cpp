/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:32:37 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/02 17:43:15 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

Base::~Base(void) {}

Base* generate(void) {
    // Generate a random number between 0 and 2
    int random = std::rand() % 3;
    
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) // doing a downcasting -> from parents to child
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p) {
    /* 
    reference can't be null -> if it does -> execption bad_cast
    */
    try {
        (void)dynamic_cast<A&>(p); //flag oblige
        std::cout << "A\n";
        return;
    } catch (std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (std::exception& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (std::exception& e) {}
    
    std::cout << "Unknown type\n";
}
