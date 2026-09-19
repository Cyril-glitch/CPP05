/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 09:54:31 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 13:18:49 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
    std::srand(std::time(NULL));
    {
        std::cout << std::endl << LIME << "<<<TEST BUREAUCRATE GRADE TOO LOW>>>" << RESET << std::endl << std::endl;



        Bureaucrat bob("bob", 150);
        AForm* scf = new ShrubberyCreationForm("test");
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
        AForm *scf = new ShrubberyCreationForm("test");
        AForm *rrf = new RobotomyRequestForm("test");
        AForm *ppf = new PresidentialPardonForm("test");

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
        AForm *ppf = new ShrubberyCreationForm("test");

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