/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:14:33 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 12:06:47 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"
class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
        Bureaucrat();
    
    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat& operator=(const Bureaucrat &rhs);
        
        std::string getName() const;
        int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
        class GradeTooHighException : public std::exception
        {
            virtual const char * what() const throw()  
            {  
                return "Grade is too high!\n";
            }  
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char * what() const throw()  
            {  
                return "Grade is too low!\n";
            }  
        };    
};

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs);

#endif