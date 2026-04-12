/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:54:00 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/30 17:54:00 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data originalData;
    originalData.id = 42;
    originalData.name = "Adams";
    originalData.salary = 42.42f;

    std::cout << "--- Original Data ---\n";
    std::cout << "Address: " << &originalData << "\n";
    std::cout << "ID:      " << originalData.id << "\n";
    std::cout << "Name:    " << originalData.name << "\n";
    std::cout << "Salary:  " << originalData.salary << "\n\n";

    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "--- Serialized Data ---\n";
    std::cout << "uintptr_t value: " << serialized << " (0x" << std::hex << serialized << std::dec << ")\n\n";

    Data* deserializedData = Serializer::deserialize(serialized);
    std::cout << "--- Deserialized Data ---\n";
    std::cout << "Address: " << deserializedData << "\n";
    std::cout << "ID:      " << deserializedData->id << "\n";
    std::cout << "Name:    " << deserializedData->name << "\n";
    std::cout << "Salary:  " << deserializedData->salary << "\n\n";

    if (deserializedData == &originalData) {
        std::cout << "SUCCESS: The deserialized pointer matches the original pointer!\n";
    } else {
        std::cout << "FAILURE: The pointers do not match.\n";
    }

    return 0;
}
