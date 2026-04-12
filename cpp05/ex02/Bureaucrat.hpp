/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 04:51:13 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/12 14:15:00 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

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
    
	void signForm(AForm &a);
	void executeForm(AForm const & form);

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

std::ostream &operator<<(std::ostream&o, Bureaucrat const & e);

#endif