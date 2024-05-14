/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:33:49 by abashir           #+#    #+#             */
/*   Updated: 2024/05/14 16:58:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}
PresidentialPardonForm::PresidentialPardonForm() : AForm("", 0, 0), _target("") {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target) {}
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
    if (this->getIsSigned())
    {
        if (executor.getGrade() <= this->getExecuteGrade())
            std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
        else
            throw GradeTooLowException();
    }
    else
        throw AForm::FormNotSignedException();
}

PresidentialPardonForm* PresidentialPardonForm::clone()
{
    return (new PresidentialPardonForm(*this));
}