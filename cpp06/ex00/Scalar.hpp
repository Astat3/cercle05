/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:32:06 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/01 18:58:35 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <iomanip>


// Non instanciable because everything is private
class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter(void);

    public:
        static void convert(const std::string& literal);
};



#endif