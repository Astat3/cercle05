/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:51:46 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 04:15:25 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form(): _name("Default"), _sign(false), _SignedGrade(100), _ExecGrade(50)
{
	std::cout<<"Default Constr Called !"<<std::endl;
}

Form::Form(const std::string name, bool sign,const int signedGrade, const int ExecGrade): _name(name), _sign(sign), _SignedGrade(signedGrade), _ExecGrade(ExecGrade)
{
	std::cout<<"Personal Constr Called"<<std::endl;
	if (sign == true)
		throw SignedMustBeFalse();
	if (signedGrade > 150 || ExecGrade > 150)
		throw GradeTooLowExcepetion();
	if (signedGrade < 1 || ExecGrade < 1)
		throw GradeTooHighExcepetion();
}

Form::~Form()
{
	std::cout<<"Default Deconstructor Called !"<<std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout<<"Operation Overload called"<<std::endl;
	if (this != &rhs)
		this->_sign = rhs._sign;
	return *this;
}

Form::Form(const Form &cpy) : _name(cpy.GetName()), _SignedGrade(GetSignedGrade()),_ExecGrade(cpy.GetExec())
{
	this->_sign = cpy.GetSign();
}

std::string Form::GetName(void)const{
	return this->_name;
}

int Form::GetSign(void)const
{
	return this->_sign;
}

int Form::GetSignedGrade(void)const{
	return this->_SignedGrade;
}

int Form::GetExec(void)const
{
	return this->_ExecGrade;
}


void Form::beSigned(Bureaucrate &a)
{
	if (this->GetSignedGrade() < a.GetGrade())
		throw GradeTooLowExcepetion();
	this->_sign = true;
}


const char *Form::GradeTooHighExcepetion::what(void) const throw()
{
    return "Grade is too High for this Form";
}

const char *Form::GradeTooLowExcepetion::what(void) const throw()
{
    return "Grade is too Low for this Form";
}

const char *Form::SignedMustBeFalse::what(void)const throw()
{
	return "Signe Must be False during Construction";
}

std::ostream	&operator<<(std::ostream &o, const Form &a)
{
	o << "Form " << a.GetName() <<
	":\n\tsign-grade:\t" << a.GetSignedGrade() <<
	"\n\texec-grade:\t" << a.GetExec() <<
	"\n\tis signed:\t" << a.GetSign() <<
	std::endl;
	return (o);
}
