/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:00:18 by cyril             #+#    #+#             */
/*   Updated: 2026/09/19 13:20:31 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << PURPLE << "ShrubberyCreationForm default constructor called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << PURPLE << "ShrubberyCreationForm target constructor called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), _target(src._target)
{
    std::cout << PURPLE << "ShrubberyCreationForm copy constructor called." << RESET << std::endl;
}



ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void ShrubberyCreationForm::action() const
{
    std::string outfile = _target + "_shrubberry";
    std::ofstream ofs(outfile.c_str());

    if (ofs.bad())
    {
        std::cerr << BL_RED << "Error: can't create outile: " << outfile << std::endl;
        return ;
    }
    ofs << BL_GREEN;
    ofs << "                                                          ." << std::endl;
    ofs << "                                               .         ;  " << std::endl;
    ofs << "                 .              .              ;%     ;;   " << std::endl;
    ofs << "                   ,           ,                :;%  %;   " << std::endl;
    ofs << "                    :         ;                   :;%;'     .,   " << std::endl;
    ofs << "           ,.        %;     %;            ;        %;'    ,; " << std::endl;
    ofs << "             ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl;
    ofs << "              %;       %;%;     ,  ;       %;  ;%;   ,%;'  " << std::endl;
    ofs << "               ;%;      %;        ;%;        % ;%;  ,%;' " << std::endl;
    ofs << "                `%;.     ;%;     %;'         `;%%;.%;' " << std::endl;
    ofs << "                 `:;%.    ;%%. %@;        %; ;@%;%' " << std::endl;
    ofs << "                    `:%;.  :;bd%;          %;@%;' " << std::endl;
    ofs << "                      `@%:.  :;%.         ;@@%;'    " << std::endl;
    ofs << "                        `@%.  `;@%.      ;@@%;          " << std::endl;
    ofs << "                          `@%%. `@%%    ;@@%;         " << std::endl;
    ofs << "                            ;@%. :@%%  %@@%;        " << std::endl;
    ofs << "                              %@bd%%%bd%%:;      " << std::endl;
    ofs << "                                #@%%%%%:;; " << std::endl;
    ofs << "                                %@@%%%::; " << std::endl;
    ofs << "                                %@@@%(o);  . '          " << std::endl;
    ofs << "                                %@@@o%;:(.,'          " << std::endl;
    ofs << "                            `.. %@@@o%::;          " << std::endl;
    ofs << "                               `)@@@o%::;          " << std::endl;
    ofs << "                                %@@(o)::;         " << std::endl;
    ofs << "                               .%@@@@%::;          " << std::endl;
    ofs << "                               ;%@@@@%::;.           " << std::endl;
    ofs << "                              ;%@@@@%%:;;;.  " << std::endl;
    ofs << "                          ...;%@@@@@%%:;;;;,..    Gilo97" << RESET<< std::endl;
    ofs.close();
    std::cout << GOLD << outfile << RESET <<  " created successfully." << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return _target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << PURPLE << "ShrubberyCreationForm destructor called." << RESET << std::endl;
}

