/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:00:55 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/30 16:30:44 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Misusage of the programm" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}