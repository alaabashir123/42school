/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:35:27 by abashir           #+#    #+#             */
/*   Updated: 2024/05/14 17:29:52 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &copy)
{
    *this = copy;
}
Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return (*this);
}
AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[] = {"presidential request", "robotomy request", "shrubbery creation"};
    AForm *formArray[] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
    AForm *clone = NULL;

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            clone = formArray[i]->clone();
            break;
        }
    }

    if (clone == NULL)
        std::cout << "Form is not found" << std::endl;

    for (int j = 0; j < 3; j++)
    {
        if (formArray[j])
            delete formArray[j];
    }
    return clone;
}
