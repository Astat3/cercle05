/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:34:22 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/17 16:34:24 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Value not found in container";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int val) {
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int val) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

#endif
