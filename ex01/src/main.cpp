/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 09:54:31 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 10:23:19 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    {
        std::cout << std::endl << LIME << "<<<TEST BUREAUCRATE GRADE TOO LOW>>>" << RESET << std::endl << std::endl;
        Bureaucrat bob("bob", 150) ;
        Form a1("a1", 1, 1);
        try
        {
            bob.signForm(a1); 
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }
    }

    std::cout << std::endl <<  "-----------------------------------------------------------------" << std::endl;

    {
        std::cout << std::endl << LIME << "<<<TEST VALID GRADE>>>" << RESET << std::endl << std::endl;
        Bureaucrat bob("bob", 1) ;
        Form a1("a1", 1, 1);
        try
        { 
            bob.signForm(a1); 
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }
    } 


    std::cout << std::endl <<"-----------------------------------------------------------------" <<std::endl;

    {
        std::cout << std::endl << LIME << "<<<TEST ALREADY SIGNED>>>" << RESET << std::endl << std::endl;
        Bureaucrat bob("bob", 1) ;
        Form a1("a1", 1, 1);
        try
        {
            bob.signForm(a1); 
            bob.signForm(a1); 
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }
    }

    std::cout << std::endl <<"-----------------------------------------------------------------" <<std::endl;

    {
        std::cout << std::endl << LIME << "<<<TEST FORM INVALID PARAMATERS>>>" << RESET << std::endl << std::endl;  
        try
        {
            Bureaucrat bob("bob", 1) ;
            Form a1("a1", 20000, -65465);
            bob.signForm(a1); 
            bob.signForm(a1); 
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }
    }
}