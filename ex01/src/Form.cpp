/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:19:07 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 10:21:15 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : _name("Default") , _signed(false) , _toSign(150) , _toExec(150)
{
    std::cout << PURPLE << "Form default constructor called." << RESET << std::endl;
}

Form::Form(const Form& src) : _name(src._name) , _signed(src._signed) , _toSign(src._toSign) , _toExec(src._toExec)
{
    std::cout << PURPLE << "Form Copy constructor called." << RESET <<std::endl;
}

Form::Form(std::string name, int toSign, int toExec) : _name(name) , _signed(false) ,  _toSign(toSign), _toExec(toExec) 
{
    std::cout << PURPLE << "Form parameters constructor called." << RESET <<std::endl;
    if (_toSign > 150 || _toExec > 150)
        throw(Form::GradeTooLowExecption());
    if (_toSign < 1 || _toExec < 1)
        throw(Form::GradeTooHighExeption());
}

Form& Form::operator=(const Form &rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

void Form::beSigned(const Bureaucrat &brc)
{ 
 
    if (brc.getGrade() > _toSign)
    {
        std::cout << ICE_BLUE << brc.getName() << " " << RESET
                  << " couldn't sign form " << MINT << _name << RESET
                  << " because ";
        throw(Form::GradeTooLowExecption());
    }
   if (_signed)
    {
        std::cout << ICE_BLUE << brc.getName() << RESET
                  << " couldn't sign form " << MINT << _name << RESET 
                  << " because it already signed"
                  << std::endl;
        return ;
    }
    else 
    {
        std::cout << ICE_BLUE << brc.getName() << RESET <<" signed " << MINT << _name << RESET << std::endl;  
        _signed = true;
    }
}

std::string  Form::getName(void) const
{
    return _name;
}

bool  Form::getIsSigned(void) const
{
    return _signed;
}

int Form::getToSign(void) const
{
    return _toSign;

}

int  Form::getToExec(void) const
{
    return _toExec;
}

const char * Form::GradeTooHighExeption::what () const throw()
{
    return "Form grade too high.";
}

const char * Form::GradeTooLowExecption::what() const throw()
{
    return "Form grade too low.";
}

Form::~Form()
{
    std::cout << PURPLE << "Form destructor called." << RESET << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Form& frm)
{
    os << MINT << "Form: " << RESET << frm.getName() << std::endl;
    os << MINT << "Grade required to Sign it: " << RESET << frm.getToSign() << std::endl;
    os << MINT << "Grade required to execute it: " << RESET << frm.getToExec() << std::endl;
    os << MINT << "Signed: " << RESET << frm.getIsSigned() << std::endl;
    return os;
}
