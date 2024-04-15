/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:37:12 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 12:09:01 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int signGrade, const int excuteGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(excuteGrade) 
{
    if (signGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
}
Form::~Form() {}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) 
{
}

Form& Form::operator=(const Form &rhs)
{
    if (this != &rhs)
    {   
        this->_isSigned = rhs.getisSigned();
    }
    return (*this);
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getisSigned() const
{
    return _isSigned;
}

int Form::getsignGrade() const
{
    return _signGrade;
}

int Form::getexecuteGrade() const
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
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<( std::ostream& o, const Form& rhs)
{
    o << rhs.getName() << " status is " << rhs.getisSigned() << ", sign grade " << rhs.getsignGrade() << ", execute grade " << rhs.getexecuteGrade(); 
    return o;
}
