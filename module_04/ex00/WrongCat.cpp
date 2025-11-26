/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:30:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/26 12:15:31 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << BOLD << "WrongCat" << RESET
              << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
    std::cout << BOLD << "WrongCat" << RESET
              << " copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << BOLD << "WrongCat" << RESET
              << " copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << BOLD << "WrongCat" << RESET
              << " destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << BOLD << "WrongCat" << RESET
              << " says: meow! (but as WrongAnimal)" << std::endl;
}
