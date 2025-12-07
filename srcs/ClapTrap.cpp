/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:55:36 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/03 22:46:39 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

// Constructeur par defaut
ClapTrap::ClapTrap(void) : p_name("Default"), p_hitPoints(10), p_energyPoints(10),
	p_attackDamage(0)
{
	std::cout << "ClapTrap " << p_name << " default constructor called" << std::endl;
}

// Constructeur surcharge
ClapTrap::ClapTrap(std::string name) : p_name(name), p_hitPoints(10),
	p_energyPoints(10), p_attackDamage(0)
{
	std::cout << "Claptrap " << p_name << " name parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int attackDamage) : p_name(name),
	p_hitPoints(10), p_energyPoints(10), p_attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << p_name << " name and attackDamage parameter constructor called" << std::endl;
}

// Constructeur de copie
ClapTrap::ClapTrap(ClapTrap const &cpy) : p_name(cpy.p_name), p_hitPoints(cpy.p_hitPoints),
	p_energyPoints(cpy.p_energyPoints), p_attackDamage(cpy.p_attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Destructeur
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << p_name << " destructor called" << std::endl;
}

// Operateur egal
ClapTrap&	ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap " << p_name << " assignation operator called" << std::endl;
	if (this != &other)
	{
		this->p_name = other.p_name;
		this->p_hitPoints = other.p_hitPoints;
		this->p_energyPoints = other.p_energyPoints;
		this->p_attackDamage = other.p_attackDamage;
	}
	return *this;
}

// Les fonctions membres utiles a ClapTrap
void	ClapTrap::attack(const std::string &target)
{
	if (this->p_hitPoints <= 0)
	{
		std::cout << "Claptrap " << p_name << " has no hit points!" << std::endl;
		return ;
	}
	else if (this->p_energyPoints <= 0)
	{
		std::cout << "Claptrap " << p_name << " has no energy points!" << std::endl;
		return ;
	}
	this->p_energyPoints--;
	std::cout << "ClapTrap " << p_name << " attacks " << target << ", causing "
		<< p_attackDamage << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << p_name << " lose 1 energy point." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->p_hitPoints <= 0)
	{
		std::cout << "Claptrap " << p_name << " has already no hit points!" << std::endl;
		return ;
	}
	if (amount >= this->p_hitPoints)
		amount = this->p_hitPoints;
	this->p_hitPoints -= amount;
	std::cout << "ClapTrap " << p_name << " took " << amount << " points of damage!" << std::endl;
	if (this->p_hitPoints <= 0)
	{
		std::cout << "He has no points now." << std::endl;
		return ;
	}
	std::cout << "He has " << p_hitPoints  << " hit points now." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->p_hitPoints <= 0)
	{
		std::cout << "Claptrap " << p_name << " has no hit points!" << std::endl;
		return ;
	}
	else if (this->p_energyPoints <= 0)
	{
		std::cout << "Claptrap " << p_name << " has no energy points!" << std::endl;
		return ;
	}
	else if (amount == 0)
	{
		std::cout << "Claptrap " << p_name << " can't repair 0 hit points!" << std::endl;
		return ;
	}
	else if (this->p_hitPoints == 10)
	{
		std::cout << "Claptrap " << p_name << " already has maximum hit points!" << std::endl;
		return ;
	}
	if (this->p_hitPoints + amount > 10)
		amount = 10 - this->p_hitPoints;
	this->p_hitPoints += amount;
	this->p_energyPoints--;
	std::cout << "ClapTrap " << p_name << " repairs itself. He has " << p_hitPoints
		<< " hit points now." << std::endl;
	std::cout << "ClapTrap " << p_name << " lose 1 energy point." << std::endl;
}
