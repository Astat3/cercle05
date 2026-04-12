/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 04:51:01 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 04:51:03 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private: 
		const std::string _name;
		bool _sign;
		const int _SignedGrade;
		const int _ExecGrade;
	public:
		AForm(void);
		AForm(const std::string name, const int signeGrade, const int ExecGrade);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &rhs);
		virtual ~AForm();

		std::string GetName(void) const;
		bool GetSign() const;
		int GetSignedGrade() const;
		int GetExec() const;
		
		void beSigned(Bureaucrat &a);
		
		virtual void execute(Bureaucrat const & executor) const = 0;

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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const AForm &a);

#endif
