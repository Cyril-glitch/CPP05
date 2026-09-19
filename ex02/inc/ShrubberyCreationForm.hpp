/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:00:18 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 11:39:29 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:

        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

        void action(void) const ;
        std::string getTarget(void) const;

    private:

        std::string _target;
};

#endif
