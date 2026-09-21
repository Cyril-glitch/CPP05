/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:00:18 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 11:35:02 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:

        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

        void action(void) const;
        std::string getTarget(void) const;

    private:

        std::string _target;
};

#endif

