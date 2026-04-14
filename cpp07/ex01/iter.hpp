/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:07:31 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/02 18:20:13 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP


#include <cstddef>
#include <iostream>

template<typename T, typename F> void iter(T *array, const std::size_t length, F func)
{
    size_t i = 0;
    while (i < length) {
        func(array[i]);
        i++;
    }
} 


#endif