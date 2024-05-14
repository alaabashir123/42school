/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:37:12 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 12:09:01 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, const int signGrade, const int excuteGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(excuteGrade) 
{
    if (signGrade < 1 || excuteGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || excuteGrade > 150)
        throw AForm::GradeTooLowException();
}
AForm::~AForm() {}
AForm::AForm() : _name(""), _isSigned(false), _signGrade(0), _executeGrade(0) {}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) 
{
}

AForm& AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
    {   
        this->_isSigned = rhs.getIsSigned();
    }
    return (*this);
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecuteGrade() const
{
    return _executeGrade;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (_isSigned)
    {
        std::cout << "AForm is already signed" << std::endl;
        return;
    }
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<( std::ostream& o, const AForm& rhs)
{
    o << rhs.getName() << " status is " << rhs.getIsSigned() << ", sign grade " << rhs.getSignGrade() << ", execute grade " << rhs.getExecuteGrade(); 
    return o;
}
