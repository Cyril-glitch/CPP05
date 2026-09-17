/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:00:55 by cyril             #+#    #+#             */
/*   Updated: 2026/09/17 11:42:59 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default") , _grade(150)
{
    std::cout << PURPLE << "Bureaucrat Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name, int grade) : _name(name)
{
    _setGrade(grade);
    std::cout << PURPLE << "Bureaucrat parameters constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name) , _grade(src._grade)
{
    std::cout << PURPLE << "Bureaucrat Copy constructor called" << RESET << std::endl; 
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        _grade = rhs._grade;
    return *this;
}

std::string Bureaucrat::getName(void) const 
{
    return _name;
}

int Bureaucrat::getGrade(void) const 
{
    return _grade;
}

void Bureaucrat::_setGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowExecption();
    else if (grade < 1)
        throw GradeTooHighExeption();
    _grade = grade;
}

void Bureaucrat::incrementGrade(void)
{
       _setGrade(_grade - 1); 
}

void Bureaucrat::decrementGrade(void)
{
       _setGrade(_grade + 1); 
}

const char * Bureaucrat::GradeTooHighExeption::what () const throw()
{
    return "Grade too high.";
}

const char * Bureaucrat::GradeTooLowExecption::what() const throw()
{
    return "Grade too low.";
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << PURPLE << "Bureaucrat destructor called" << RESET << std::endl; 
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& brc)
{
    os << ICE_BLUE << brc.getName() << ", bureaucrat grade " << brc.getGrade() << RESET;
    return os;
}