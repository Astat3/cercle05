/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:59:34 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 03:40:40 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		int SetGrade(int grade);
	public: 
		Bureaucrat();
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();
		void increment();
		void decrement();
		int GetGrade(void)const;
		const std::string GetName(void)const;
		void signForm( Form &a);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream&o, Bureaucrat const &e);

#endif