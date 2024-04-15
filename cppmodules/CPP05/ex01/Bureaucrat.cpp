/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:31:18 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 12:16:05 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    
}
Bureaucrat::Bureaucrat( const std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
}

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

void Bureaucrat::signForm(Form &form)
{
    if (form.getisSigned())
        std::cout << _name << " signed " << form.getName() << " already" << std::endl;
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

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs )
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}