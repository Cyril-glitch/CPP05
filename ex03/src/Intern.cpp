/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 06:54:46 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/21 08:03:22 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/colors.hpp"
#include <iostream>

Intern::Intern(void)
{
    std::cout << BLUE << "Intern default constructor called." << RESET << std::endl;
}

Intern::Intern(const Intern& src)
{
    (void)src;
    std::cout << BLUE << "Intern copy constructor called." << RESET << std::endl;
}

Intern::~Intern(void)
{
    std::cout << BLUE << "Intern destructor called." << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return *this;
}

static AForm* makeShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomyRequestForm(const std::string& target) 
{
    return new RobotomyRequestForm(target);
}

static AForm* makePresidentialPardonForm(const std::string& target) 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    AForm *(*f[])(const std::string& target) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm}; 
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (size_t i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << MINT << "Intern creates " << GOLD << formName << RESET << std::endl;
            return f[i](target);
        }
    }

    std::cerr << "Intern can't creates " << GOLD << formName << RESET << std::endl; 
    std::cerr << BL_RED << "Error:: Unknown Form" << RESET << std::endl;
    return NULL;
}
