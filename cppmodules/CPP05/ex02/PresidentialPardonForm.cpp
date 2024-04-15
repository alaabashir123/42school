/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:33:49 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 12:54:44 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
    {
        (void)rhs;
    }
    return (*this);
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() < this->getexecuteGrade() && this->getexecuteGrade())
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
        throw GradeTooLowException();
}