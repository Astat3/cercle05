/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:51:56 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/02 18:06:30 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename S> void swap(S& x, S& y) {
	S tmp = x;
	x = y;
	y = tmp;
}

template <typename T> const T& min(const T& x, const T& y) { return (x < y) ? x : y; }

template <typename T> const T& max(const T& x, const T& y) { return (x > y) ? x : y; }

#endif