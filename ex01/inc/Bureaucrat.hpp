/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 08:28:32 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 09:58:51 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "colors.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    public :
        
        Bureaucrat(void);
        Bureaucrat(const std::string & name, int grade);
        Bureaucrat(const Bureaucrat& src);
        ~Bureaucrat(void);

        Bureaucrat& operator=(const Bureaucrat& rhs);
        std::string getName(void) const ;
        int         getGrade(void) const;
        void        incrementGrade(void);
        void        decrementGrade(void);
        bool        signForm(Form& form);

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
    
    private :

        const std::string _name;
        int         _grade;
        void    _setGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& brc);

#endif