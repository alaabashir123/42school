/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:10:40 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 14:08:51 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
        (void)rhs;
    return (*this);
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() < this->getexecuteGrade() && this->getexecuteGrade())
    {
        std::ofstream outfile ((_target + "_shrubbery").c_str());
        outfile << "             .        +          .      .          ." << std::endl;
        outfile << "     .            _        .                    ." << std::endl;
        outfile << "  ,              /;-._,-.____        ,-----.__" << std::endl;
        outfile << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
        outfile << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
        outfile << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
        outfile << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
        outfile << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
        outfile << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
        outfile << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
        outfile << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
        outfile << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
        outfile << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
        outfile << "                    \\::.  :\\/:'  /              +" << std::endl;
        outfile << "   .                 `.:.  /:'  }      ." << std::endl;
        outfile << "           .           ):_(:;   \\           ." << std::endl;
        outfile << "                      /:. _/ ,  |" << std::endl;
        outfile << "                   . (|::.     ,`                  ." << std::endl;
        outfile << "     .                |::.    {\"" << std::endl;
        outfile << "                      |::.\\  \\ `" << std::endl;
        outfile << "                      |:::(\\    |" << std::endl;
        outfile << "              O       |:::/{ }  |                  (o" << std::endl;
        outfile << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
        outfile << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
        outfile << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~" << std::endl;
        outfile.close();
    }
    else
        throw GradeTooLowException();
}

ShrubberyCreationForm *ShrubberyCreationForm::clone()
{
    return (new ShrubberyCreationForm(*this));
}