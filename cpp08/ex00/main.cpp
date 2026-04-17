/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:34:27 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/17 16:34:30 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::cout << "--- Testing with std::vector ---" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i * 10);
    }

    try {
        std::cout << "Trying to find 20..." << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found value: " << *it << std::endl;

        std::cout << "Trying to find 100..." << std::endl;
        it = easyfind(vec, 100);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing with const std::vector ---" << std::endl;
    const std::vector<int> cvec(vec);
    try {
        std::cout << "Trying to find 30 in const vector..." << std::endl;
        std::vector<int>::const_iterator cit = easyfind(cvec, 30);
        std::cout << "Found value: " << *cit << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing with std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(21);
    lst.push_back(84);

    try {
        std::cout << "Trying to find 42..." << std::endl;
        std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "Found value: " << *it << std::endl;

        std::cout << "Trying to find 43..." << std::endl;
        it = easyfind(lst, 43);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
