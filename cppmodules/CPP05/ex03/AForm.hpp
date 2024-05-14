/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:18:23 by abashir           #+#    #+#             */
/*   Updated: 2024/05/14 16:56:49 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
        AForm();
        
    public:
        AForm(const std::string name, const int signGrade, const int excuteGrade);
        virtual ~AForm();
        AForm(const AForm &copy);
        AForm& operator=(const AForm &rhs);
        
        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        void beSigned(Bureaucrat &b);
        virtual AForm *clone() = 0;
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
        class FormNotSignedException : public std::exception
        {
            virtual const char * what() const throw()  
            {  
                return "Form is not signed!\n";
            }  
        }; 
};

std::ostream& operator<<( std::ostream& o, const AForm& rhs);

#endif