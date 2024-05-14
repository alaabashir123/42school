/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:31:18 by abashir           #+#    #+#             */
/*   Updated: 2024/05/14 16:57:10 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat( const std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}
int Bureaucrat::getGrade() const
{
    return this->_grade;
}
void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException(); 
    _grade--;
}

void Bureaucrat::signForm(AForm &form)
{
    if (form.getIsSigned())
        std::cout << "Form is already signed" << std::endl;
    else
    {
        try
        {
            form.beSigned(*this);
            std::cout << _name << " signed " << form.getName() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << _name << " couldn't sign " << form.getName() << " because ";
            std::cerr << e.what();
        }
        
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    if (form.getIsSigned())
    {
        try
        {
            form.execute(*this);
            std::cout << _name << " executed " << form.getName() << std::endl; 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
    }
    else
        throw AForm::FormNotSignedException();
    
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs )
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}