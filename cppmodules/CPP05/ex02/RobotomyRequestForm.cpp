/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:58:07 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 13:06:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
        (void)rhs;
    return (*this);
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    srand((unsigned) time(NULL));
    int random = rand();
    if (executor.getGrade() < this->getexecuteGrade() && this->getexecuteGrade())
    {
        if (random % 2 == 0)
            std::cout << "BZZZZZT! " << _target << " has been robotomized successfuly" << std::endl;
        else
            std::cout << "Robotomy failed" << std::endl;
    }
    else
        throw GradeTooLowException();
}