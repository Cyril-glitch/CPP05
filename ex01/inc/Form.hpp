/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 07:59:38 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 10:03:11 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#include "colors.hpp"

class Bureaucrat;

class Form 
{
    public :

        Form();
        Form(const Form& src);
        Form(std::string name, int toSign, int toExec);
        ~Form();

        Form &operator=(const Form &rhs);


        void _setToSign(int grade);

        void beSigned(const Bureaucrat &brc);
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getToSign(void) const;
        int getToExec(void) const;

        class GradeTooHighExeption : public std::exception
        {
            public :
                const char * what() const throw();
        };

        class GradeTooLowExecption : public std::exception
        {
            public :
                const char * what() const throw();
        };

    private:

        const std::string _name;
        bool _signed;
        const int _toSign;
        const int _toExec;
};

std::ostream& operator<<(std::ostream os, const Form& frm);  

#endif