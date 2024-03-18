/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:11:33 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 14:56:48 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* _ideas; 
    public:
        Cat();
        ~Cat();
        Cat(Cat const &copy);
        Cat &operator=(Cat const &rhs);
        void makeSound() const;
        void getIdea(int index) const;
};

#endif