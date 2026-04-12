/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:00:10 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/17 20:48:25 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(100)
{
	std::cout<<"Default Constr Called"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): _name(cpy._name), _grade(cpy._grade){
	std::cout<<"Cpy constructor called "<<std::endl;
}

const std::string Bureaucrat::GetName(void)const{
	return this->_name;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout<<"Overload Operator Called"<<std::endl;
	if (this != &rhs)
		this->_grade = rhs.GetGrade();
	return *this;
}
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;	
	std::cout << "Bureaucrat Constructor called for " << this->GetName() <<
	" with grade of " << grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Default Deconstructor called "<<std::endl;
}
int Bureaucrat::GetGrade(void)const
{
	return this->_grade;
}


int Bureaucrat::SetGrade(int n)
{
	if (n >150)
		throw GradeTooLowException();
	else if (n< 1)
		throw GradeTooHighException();
	this->_grade = n;
	std::cout<<"Grade is now: "<<this->_grade<<std::endl;
	return this->_grade;
}
void Bureaucrat::increment()
{
	std::cout<<"Trying to increment"<<std::endl;
	SetGrade(this->_grade - 1);
}
void Bureaucrat::decrement()
{
	std::cout<<"Trying to decrement"<<std::endl;
	SetGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High");
};

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low");
};



std::ostream	&operator<<(std::ostream &o, Bureaucrat const &e)
{
	o << e.GetName() << ", bureaucrat grade " << e.GetGrade() << ".";
	return (o);
}
