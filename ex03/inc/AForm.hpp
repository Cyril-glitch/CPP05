/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 07:59:38 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 12:35:37 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <fstream>

#include "colors.hpp"

class Bureaucrat;

class AForm 
{
    public :

        AForm();
        AForm(const AForm& src);
        AForm(std::string name, int toSign, int toExec);
        virtual ~AForm();

        AForm &operator=(const AForm &rhs);


        void _setToSign(int grade);

        void beSigned(const Bureaucrat &brc);
        void execute(Bureaucrat const & executor) const;
        virtual void action() const = 0;
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

        class FormIsNotSignedExecption : public std::exception
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

std::ostream& operator<<(std::ostream os, const AForm& frm);  

#endif