/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:08:00 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/02 18:08:19 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T& item) {
    std::cout << item << " ";
}

template <typename T>
void increment(T& item) {
    item++;
}

int main() {
    std::cout << "--- Integer Array ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original: ";
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl;

    std::cout << "Incremented: ";
    ::iter(intArray, intLen, increment<int>);
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl << std::endl;

    std::cout << "--- String Array ---" << std::endl;
    std::string strArray[] = {"Hello", "from", "42", "Paris"};
    std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original: ";
    ::iter(strArray, strLen, print<std::string>);
    std::cout << std::endl;

    return 0;
}