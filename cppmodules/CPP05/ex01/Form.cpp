/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:37:12 by abashir           #+#    #+#             */
/*   Updated: 2024/05/14 13:24:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int signGrade, const int excuteGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(excuteGrade) 
{
    if (signGrade < 1 || excuteGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || excuteGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}
Form::Form() : _name(""), _isSigned(0), _signGrade(false), _executeGrade(0) {}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) 
{
}

Form& Form::operator=(const Form &rhs)
{
    if (this != &rhs)
    {   
        this->_isSigned = rhs.getIsSigned();
    }
    return (*this);
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecuteGrade() const
{
    return _executeGrade;
}

void Form::beSigned(Bureaucrat &b)
{
    if (_isSigned)
    {
        std::cout << "Form is already signed" << std::endl;
        return;
    }
    if (b.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<( std::ostream& o, const Form& rhs)
{
    o << rhs.getName() << " status is " << rhs.getIsSigned() << ", sign grade " << rhs.getSignGrade() << ", execute grade " << rhs.getExecuteGrade(); 
    return o;
}
