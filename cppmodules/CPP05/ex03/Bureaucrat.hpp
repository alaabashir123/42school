/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:14:33 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 13:22:48 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "AForm.hpp"
class AForm;

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
        void signForm(AForm &form);
        void executeForm(AForm const & form);
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