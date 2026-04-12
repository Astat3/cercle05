/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:00:10 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 04:32:21 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrate::Bureaucrate() : _name("Default"), _grade(100)
{
	std::cout<<"Default Constr Called"<<std::endl;
}

Bureaucrate::Bureaucrate(const Bureaucrate &cpy): _name(cpy._name), _grade(cpy._grade){
	std::cout<<"Cpy constructor called "<<std::endl;
}

const std::string Bureaucrate::GetName(void)const{
	return this->_name;
}

Bureaucrate &Bureaucrate::operator=(const Bureaucrate &rhs)
{
	std::cout<<"Overload Operator Called"<<std::endl;
	if (this != &rhs)
		this->_grade = rhs.GetGrade();
	return *this;
}
Bureaucrate::Bureaucrate(const std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw GradeTooLowExcepetion();
	if (grade < 1)
		throw GradeTooHighExcepetion();
	this->_grade = grade;	
	std::cout << "Bureaucrat Constructor called for " << this->GetName() <<
	" with grade of " << grade << std::endl;
}

Bureaucrate::~Bureaucrate()
{
	std::cout<<"Default Deconstructor called "<<std::endl;
}
int Bureaucrate::GetGrade(void)const
{
	return this->_grade;
}


int Bureaucrate::SetGrade(int n)
{
	if (n >150)
		throw GradeTooLowExcepetion();
	else if (n< 1)
		throw GradeTooHighExcepetion();
	this->_grade = n;
	std::cout<<"Grade is now: "<<this->_grade<<std::endl;
	return this->_grade;
}
void Bureaucrate::increment()
{
	std::cout<<"Trying to increment"<<std::endl;
	SetGrade(this->_grade  - 1);
}
void Bureaucrate::decrement()
{
	std::cout<<"Trying to decrement"<<std::endl;
	SetGrade(this->_grade + 1);
}

const char *Bureaucrate::GradeTooHighExcepetion::what(void) const throw()
{
	return ("Grade too High");
};

const char *Bureaucrate::GradeTooLowExcepetion::what(void) const throw()
{
	return ("Grade too Low");
};

void Bureaucrate::signForm( Form &a)
{
	try
	{
		a.beSigned(*this);
		std::cout<<this->_name<<" signed "<<a.GetName()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " <<a.GetName()<< " because "<<e.what()<<'\n';
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrate &e) {
	o << e.GetName() << ", bureaucrat grade " << e.GetGrade() << ".";
	return o;
}
