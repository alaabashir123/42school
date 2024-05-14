/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:18:23 by abashir           #+#    #+#             */
/*   Updated: 2024/05/14 16:52:13 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
        Form();
        
    public:
        Form(const std::string name, const int signGrade, const int excuteGrade);
        ~Form();
        Form(const Form &copy);
        Form& operator=(const Form &rhs);
        
        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &b);
        
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

std::ostream& operator<<( std::ostream& o, const Form& rhs);

#endif