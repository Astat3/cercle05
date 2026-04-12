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
#include "Bureaucrat.hpp"

class Bureaucrate;

class Form
{
	private: 
		const std::string _name;
		bool _sign;
		const int _SignedGrade;
		const int _ExecGrade;
	public:
	Form(void);
	Form(const std::string name, bool signe,const int signeGrade,const int ExecGrade);
	Form(const Form &cpy);
	Form &operator=(const Form &rhs);
	std::string GetName(void)const;
	int GetSign()const;
	int GetSignedGrade()const;
	int GetExec()const;
	void beSigned(Bureaucrate &a);
	~Form();


	class GradeTooHighExcepetion : public std::exception
{
	public:
		virtual const char *what() const throw();
};
class GradeTooLowExcepetion : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class SignedMustBeFalse : public std::exception
{
	public:
		virtual const char *what() const throw();
};

};

std::ostream	&operator<<(std::ostream &o, const Form &a);


#endif