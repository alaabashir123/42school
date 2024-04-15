/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:18:23 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 12:28:39 by abashir          ###   ########.fr       */
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
        bool getisSigned() const;
        int getsignGrade() const;
        int getexecuteGrade() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
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

std::ostream& operator<<( std::ostream& o, const AForm& rhs);

#endif