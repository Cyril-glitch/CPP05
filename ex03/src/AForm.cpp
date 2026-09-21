/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:19:07 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 13:03:07 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name("Default") , _signed(false) , _toSign(150) , _toExec(150)
{
    std::cout << PURPLE << "Form default constructor called." << RESET << std::endl;
}

AForm::AForm(const AForm& src) : _name(src._name) , _signed(src._signed) , _toSign(src._toSign) , _toExec(src._toExec)
{
    std::cout << PURPLE << "Form Copy constructor called." << RESET <<std::endl;
}

AForm::AForm(std::string name, int toSign, int toExec) : _name(name) , _signed(false) ,  _toSign(toSign), _toExec(toExec) 
{
    std::cout << PURPLE << "Form parameters constructor called." << RESET <<std::endl;
    if (_toSign > 150 || _toExec > 150)
        throw(AForm::GradeTooLowExecption());
    if (_toSign < 1 || _toExec < 1)
        throw(AForm::GradeTooHighExeption());
}

AForm& AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

void AForm::beSigned(const Bureaucrat &brc)
{ 
 
    if (brc.getGrade() > _toSign)
    {
        std::cout << ICE_BLUE << brc.getName() << " " << RESET
                  << " couldn't sign form " << MINT << _name << RESET
                  << " because ";
        throw(AForm::GradeTooLowExecption());
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

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > _toExec)
    {
        std::cout << ICE_BLUE << executor.getName() << " " << RESET
                  << " couldn't execute form " << MINT << _name << RESET
                  << " because his grade is too low." << std::endl << std::endl;
        throw(AForm::GradeTooLowExecption());
    }
   if (_signed == false)
    {
        std::cout << ICE_BLUE << executor.getName() << RESET
                  << " couldn't execute form " << MINT << _name << RESET 
                  << " because it is not signed"
                  << std::endl << std::endl;
        throw(AForm::FormIsNotSignedExecption());
    }
    else 
    {
        std::cout << ICE_BLUE << executor.getName() << RESET <<" execute " << MINT << _name << RESET << std::endl;  
        action();
    } 
}

std::string  AForm::getName(void) const
{
    return _name;
}

bool  AForm::getIsSigned(void) const
{
    return _signed;
}

int AForm::getToSign(void) const
{
    return _toSign;

}

int  AForm::getToExec(void) const
{
    return _toExec;
}

const char * AForm::GradeTooHighExeption::what () const throw()
{
    return "Form grade too high.";
}

const char * AForm::GradeTooLowExecption::what() const throw()
{
    return "Form grade too low.";
}


const char * AForm::FormIsNotSignedExecption::what() const throw()
{
    return "Form is not signed.";
}

AForm::~AForm()
{
    std::cout << PURPLE << "Form destructor called." << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& frm)
{
    os << MINT << "Form: " << RESET << frm.getName() << std::endl;
    os << MINT << "Grade required to Sign it: " << RESET << frm.getToSign() << std::endl;
    os << MINT << "Grade required to execute it: " << RESET << frm.getToExec() << std::endl;
    os << MINT << "Signed: " << RESET << frm.getIsSigned() << std::endl;
    return os;
}
