/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:59:34 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/17 20:20:01 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP


#include <iostream>
#include <string>
#include <exception>

class Bureaucrate
{
	private:
		const std::string _name;
		int _grade;
        int SetGrade(int grade);
	public: 
	Bureaucrate();
    Bureaucrate(const Bureaucrate &cpy);
    Bureaucrate(const std::string, int grade);
    Bureaucrate &operator=(const Bureaucrate &rhs);
	~Bureaucrate();
	void increment();
	void decrement();
	int GetGrade(void)const;
    const std::string GetName(void)const;


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
};

std::ostream &operator<<(std::ostream&o, Bureaucrate *e);



#endif