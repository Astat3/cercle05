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
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _sign(false), _SignedGrade(100), _ExecGrade(50)
{
	std::cout<<"Default Constr Called !"<<std::endl;
}

Form::Form(const std::string name, const int signedGrade, const int ExecGrade): _name(name), _sign(false), _SignedGrade(signedGrade), _ExecGrade(ExecGrade)
{
	std::cout<<"Personal Constr Called"<<std::endl;
	if (signedGrade > 150 || ExecGrade > 150)
		throw GradeTooLowException();
	if (signedGrade < 1 || ExecGrade < 1)
		throw GradeTooHighException();
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

Form::Form(const Form &cpy) : _name(cpy.GetName()), _sign(cpy.GetSign()), _SignedGrade(cpy.GetSignedGrade()),_ExecGrade(cpy.GetExec())
{
}

std::string Form::GetName(void)const{
	return this->_name;
}

bool Form::GetSign(void)const
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


void Form::beSigned(Bureaucrat &a)
{
	if (this->GetSignedGrade() < a.GetGrade())
		throw GradeTooLowException();
	this->_sign = true;
}


const char *Form::GradeTooHighException::what(void) const throw()
{
    return "Grade is too High for this Form";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return "Grade is too Low for this Form";
}


std::ostream	&operator<<(std::ostream &o, const Form &a)
{
	o << "Form " << a.GetName() <<
	":\n\tsign-grade:\t" << a.GetSignedGrade() <<
	"\n\texec-grade:\t" << a.GetExec() <<
	"\n\tis signed:\t" << (a.GetSign() ? "true" : "false") <<
	std::endl;
	return (o);
}
