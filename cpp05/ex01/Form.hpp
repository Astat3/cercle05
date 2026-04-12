/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:28:43 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 04:15:39 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private: 
		const std::string _name;
		bool _sign;
		const int _SignedGrade;
		const int _ExecGrade;
	public:
		Form(void);
		Form(const std::string name, const int signeGrade, const int ExecGrade);
		Form(const Form &cpy);
		Form &operator=(const Form &rhs);
		~Form();

		std::string GetName(void)const;
		bool GetSign()const;
		int GetSignedGrade()const;
		int GetExec()const;
		void beSigned(Bureaucrat &a);

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

std::ostream	&operator<<(std::ostream &o, const Form &a);

#endif