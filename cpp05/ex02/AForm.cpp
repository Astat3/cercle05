/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 04:50:54 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 04:54:19 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm(): _name("Default"), _sign(false), _SignedGrade(100), _ExecGrade(50)
{
	std::cout<<"aform Default Constr Called !"<<std::endl;
}

AForm::AForm(const std::string name, bool sign, const int signedGrade, const int ExecGrade): _name(name), _sign(sign), _SignedGrade(signedGrade), _ExecGrade(ExecGrade)
{
	std::cout<<"aform Personal Constr Called"<<std::endl;
	if (sign == true)
		throw SignedMustBeFalse();
	if (signedGrade > 150 || ExecGrade > 150)
		throw GradeTooLowException();
	if (signedGrade < 1 || ExecGrade < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
	std::cout<<"AForm Default Deconstructor Called !"<<std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout<<"AForm Operation Overload called"<<std::endl;
	if (this != &rhs)
		this->_sign = rhs._sign;
	return *this;
}

AForm::AForm(const AForm &cpy) : _name(cpy.GetName()), _SignedGrade(cpy.GetSignedGrade()), _ExecGrade(cpy.GetExec())
{
	this->_sign = cpy.GetSign();
}

std::string AForm::GetName(void) const{
	return this->_name;
}

bool AForm::GetSign(void) const
{
	return this->_sign;
}

int AForm::GetSignedGrade(void) const{
	return this->_SignedGrade;
}

int AForm::GetExec(void) const
{
	return this->_ExecGrade;
}

void AForm::beSigned(Bureaucrat &a)
{
	if (this->GetSignedGrade() < a.GetGrade())
		throw GradeTooLowException();
	this->_sign = true;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return "Grade is too High for this Form";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return "Grade is too Low for this Form";
}

const char *AForm::SignedMustBeFalse::what(void)const throw()
{
	return "Sign Must be False during Construction";
}

const char *AForm::NotSignedException::what(void)const throw()
{
	return "Form is not signed, cannot execute";
}

std::ostream	&operator<<(std::ostream &o, const AForm &a)
{
	o << "Form " << a.GetName() <<
	":\n\tsign-grade:\t" << a.GetSignedGrade() <<
	"\n\texec-grade:\t" << a.GetExec() <<
	"\n\tis signed:\t" << a.GetSign() <<
	std::endl;
	return (o);
}
