/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 04:51:47 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 05:10:55 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), _target(cpy._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->GetSign() == false)
		throw AForm::NotSignedException();
	if (executor.GetGrade() > this->GetExec())
		throw AForm::GradeTooLowException();

	std::cout << " drilling noises *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
}
