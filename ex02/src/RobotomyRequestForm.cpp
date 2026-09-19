/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:00:18 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 11:00:37 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << PURPLE << "RobotomyRequestForm default constructor called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << PURPLE << "RobotomyRequestForm target constructor called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target)
{
    std::cout << PURPLE << "RobotomyRequestForm copy constructor called." << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void RobotomyRequestForm::action() const 
{
    std::cout << "\"Drilling noises...\"" << std::endl;
    if (rand() % 2)
        std::cout << GOLD <<  _target << RESET << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << GOLD << _target << RESET << " failed." << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return _target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << PURPLE << "RobotomyRequestForm destructor called." << RESET << std::endl;
}