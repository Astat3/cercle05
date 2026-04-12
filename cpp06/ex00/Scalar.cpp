/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:32:06 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/01 19:26:26 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	// useless here because no data attributes or allocation memory
	if (this != &rhs)
	{
		(void)rhs;
	}
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(const std::string& literal) {
	// Case of Char
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		char c = literal[0];
		std::cout << "char: '" << c << "'\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< "float: " << static_cast<float>(c) << ".0f\n"
				<< "double: " << static_cast<double>(c) << ".0\n";
		return;
	}
	// Special Case
	if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible\n"
				<< "int: impossible\n";
		if (literal == "nan" || literal == "nanf") {
			std::cout << "float: nanf\n"
					<< "double: nan\n";
		} else if (literal == "+inf" || literal == "+inff") {
			std::cout << "float: +inff\n"
					<< "double: +inf\n";
		} else {
			std::cout << "float: -inff\n"
					<< "double: -inf\n";
		}
		return;
	}

	char* endptr = NULL;
	double val = std::strtod(literal.c_str(), &endptr);
	std::string remain(endptr);

	if (!remain.empty() && remain != "f") {
		std::cout << "char: impossible\n"
				<< "int: impossible\n"
				<< "float: impossible\n"
				<< "double: impossible\n";
		return;
	}
	// case of ""
	if (endptr == literal.c_str()) {
		std::cout << "char: impossible\n"
				<< "int: impossible\n"
				<< "float: impossible\n"
				<< "double: impossible\n";
		return;
	}

	if (val >= 0 && val <= 127) {
		if (std::isprint(static_cast<int>(val)))
			std::cout << "char: '" << static_cast<char>(val) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: impossible\n";
	}

	if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << static_cast<int>(val) << "\n";
	} else {
		std::cout << "int: impossible\n";
	}

	float fval = static_cast<float>(val);
	double dval = static_cast<double>(val);

	std::cout << "float: " << fval;
	if (fval == std::floor(fval) && fval < 1e6f && fval > -1e6f) {
		std::cout << ".0";
	}
	std::cout << "f\n";

	std::cout << "double: " << dval;
	if (dval == std::floor(dval) && dval < 1e6 && dval > -1e6) {
		std::cout << ".0";
	}
	std::cout << "\n";
}
