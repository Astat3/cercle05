/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 04:52:02 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 05:09:33 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), _target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), _target(cpy._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->GetSign() == false)
		throw AForm::NotSignedException();
	if (executor.GetGrade() > this->GetExec())
		throw AForm::GradeTooLowException();

	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "      /\\      \n"
			<< "     /\\*\\     \n"
			<< "    /\\O\\*\\    \n"
			<< "   /*/\\/\\/\\   \n"
			<< "  /\\O\\/\\*\\/\\  \n"
			<< " /\\*\\/\\*\\/\\/\\ \n"
			<< "/\\O\\/\\/*/\\/O/\\\n"
			<< "      ||      \n"
			<< "      ||      \n"
			<< "      ||      \n";
		file.close();
	}
}
