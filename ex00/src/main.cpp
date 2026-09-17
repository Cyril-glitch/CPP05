/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 09:54:31 by cyril             #+#    #+#             */
/*   Updated: 2026/09/17 11:56:10 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    {
        std::cout << std::endl << LIME << "<<<TEST INVALID DECREMENTATION>>>" << RESET << std::endl << std::endl;
        Bureaucrat a("Bob", 150);
        Bureaucrat b("Bill", 1);
        try
        {


            std::cout << std::endl << a << std::endl;
            std::cout << MINT << "Try decrement " << a.getName() << "'s grade"  << RESET << std::endl;
            a.decrementGrade();


            std::cout << b << std::endl;
            std::cout << MINT << "Try increment " << b.getName() << "'s grade"  << RESET <<std::endl;
            b.incrementGrade();

            std::cout << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }
    }

    std::cout << std::endl <<  "-----------------------------------------------------------------" << std::endl;

    {
        std::cout << std::endl << LIME << "<<<TEST VALID GRADES>>>" << RESET << std::endl << std::endl;
        Bureaucrat a("Bob", 150);
        Bureaucrat b("Bill", 1);
        try
        {

            std::cout << std::endl << a << std::endl;
            std::cout << MINT << "Try increment " << a.getName() << "'s grade"  << std::endl;
            a.incrementGrade();

            std::cout << std::endl << b << std::endl;
            std::cout << MINT << "Try to increment " << b.getName() << "'s grade"  << std::endl;
            b.decrementGrade();
            
            std::cout << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }
    } 


    std::cout << std::endl <<"-----------------------------------------------------------------" <<std::endl;

    {
        std::cout << std::endl << LIME << "<<<TEST INVALID CONSTRUCOR PARAMETERS>>>" << RESET << std::endl << std::endl;
        try
        {
            Bureaucrat a("Bob", -1);
        }
        catch (const std::exception &e)
        {
            std::cerr << BL_RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }
    }
}