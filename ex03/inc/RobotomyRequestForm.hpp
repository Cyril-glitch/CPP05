/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:00:18 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 13:19:18 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:

        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

        void action(void) const;
        std::string getTarget(void) const;

    private:

        std::string _target;
};

#endif
