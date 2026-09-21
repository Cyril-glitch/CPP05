/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:00:18 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 11:00:37 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << PURPLE << "PresidentialPardonForm default constructor called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << PURPLE << "PresidentialPardonForm target constructor called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    : AForm(src), _target(src._target)
{
    std::cout << PURPLE << "PresidentialPardonForm copy constructor called." << RESET << std::endl;
}



PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void PresidentialPardonForm::action() const
{
    std::cout << GOLD << _target << RESET << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return _target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << PURPLE << "PresidentialPardonForm destructor called." << RESET << std::endl;
}