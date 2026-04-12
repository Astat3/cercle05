/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:54:00 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/01 20:10:52 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& src) {
    *this = src;
}

Serializer& Serializer::operator=(const Serializer& rhs) {
    (void)rhs;
    return *this;
}

Serializer::~Serializer(void) {}

// pointer to unsigned int unitptr_t (giant unsigned int-> guaranteed by the os to be big enought)
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// unsigned int to a pointer to data
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
