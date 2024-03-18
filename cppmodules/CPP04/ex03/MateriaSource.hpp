/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:54:32 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 11:33:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
class IMateriaSource;

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _inventory[4];
    
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &rhs);    
        void learnMateria(AMateria*m);
        AMateria* createMateria(std::string const & type);
};
#endif