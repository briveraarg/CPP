#include "FragTrap.hpp"


/* 
 * Valores que pide el subjet
 * this->_hitPoints = 100;
 * this->_energyPoints = 100;
 * this->_attackDamage = 30;
 * 
 * */

FragTrap::FragTrap(): ClapTrap("Default", 100, 100, 30)
{
	std::cout << "FragTrap " << BOLD << this->_name
			<< RESET << " default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << BOLD << this->_name
			<< RESET << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
	std::cout << "FragTrap " << BOLD << this->_name
			<< RESET << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << BOLD << this->_name
			<< RESET << " copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << BOLD << this->_name
			<< RESET << " destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << BOLD << this->_name << RESET
			<< " requests a positive high five!" << std::endl;
}
