/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 09:54:31 by cyril             #+#    #+#             */
/*   Updated: 2026/09/21 08:55:54 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
    std::srand(std::time(NULL));
    {
        std::cout << std::endl << LIME << "<<<TEST BUREAUCRATE GRADE TOO LOW>>>" << RESET << std::endl << std::endl;

        Bureaucrat bob("bob", 150);
        Intern intern;
        AForm* scf = intern.makeForm("shrubbery creation" , "test");  
        try
        {
            std::cout << std::endl;
            bob.executeForm(*scf);
            std::cout << std::endl;

            delete scf;
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
            delete scf;
        }
    }

    std::cout << std::endl <<  "-----------------------------------------------------------------" << std::endl;

    {
        std::cout << std::endl << LIME << "<<<TEST VALID GRADE>>>" << RESET << std::endl << std::endl;

        Bureaucrat bob("bob", 1);
        Intern intern;
        AForm *scf = intern.makeForm("shrubbery creation", "test");
        AForm *rrf = intern.makeForm("robotomy request", "test");
        AForm *ppf = intern.makeForm("presidential pardon", "test");

        try
        { 
            std::cout << std::endl;
            bob.signForm(*scf);
            bob.signForm(*ppf);
            bob.signForm(*rrf);
            std::cout << std::endl;

            std::cout << std::endl;
            bob.executeForm(*scf);
            std::cout << std::endl;

            std::cout << std::endl;
            bob.executeForm(*ppf); 
            std::cout << std::endl; 

            std::cout << std::endl;
            bob.executeForm(*rrf);
            std::cout << std::endl;

            delete scf;
            delete rrf;
            delete ppf;
            
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
            delete scf;
            delete rrf;
            delete ppf;
        }
    } 


    std::cout << std::endl <<"-----------------------------------------------------------------" <<std::endl;

    {
        std::cout << std::endl << LIME << "<<<TEST NOT SIGNED>>>" << RESET << std::endl << std::endl;

        Bureaucrat bob("bob", 137);
        Intern intern;
        AForm *ppf = intern.makeForm("shrubbery creation", "test");

        try
        {    
            std::cout << std::endl;
            bob.executeForm(*ppf);
            std::cout << std::endl;

            delete ppf;
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
            delete ppf;
        }
    } 

    std::cout << std::endl <<"-----------------------------------------------------------------" <<std::endl;

    {
        std::cout << std::endl << LIME << "<<<TEST UNKNOWNED FORM>>>" << RESET << std::endl << std::endl;

        Bureaucrat bob("bob", 137);
        Intern intern;
        AForm *ppf = intern.makeForm("unknown", "test");
        if (!ppf)
            return 0;
        try
        {    
            std::cout << std::endl;
            bob.executeForm(*ppf);
            std::cout << std::endl;

            delete ppf;
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
            delete ppf;
        }
    }
}