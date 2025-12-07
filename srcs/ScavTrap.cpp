/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:34:35 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/03 23:06:12 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	p_name = "Default_ScavTrap";
	p_hitPoints = 100;
	p_energyPoints = 50;
	p_attackDamage = 20;
	p_gateKeeperMode = false;
	std::cout << "ScavTrap " << p_name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	p_hitPoints = 100;
	p_energyPoints = 50;
	p_attackDamage = 20;
	p_gateKeeperMode = false;
	std::cout << "ScavTrap " << p_name << " name parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap(cpy)
{
	this->p_gateKeeperMode = cpy.p_gateKeeperMode;
	std::cout << "ScavTrap " << p_name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << p_name << " destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap " << p_name << " assignation operator called" << std::endl;
	if (this != &other)
	{
		this->p_name = other.p_name;
		this->p_hitPoints = other.p_hitPoints;
		this->p_energyPoints = other.p_energyPoints;
		this->p_attackDamage = other.p_attackDamage;
		this->p_gateKeeperMode = other.p_gateKeeperMode;
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (p_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << p_name << " has no hit points left to attack." << std::endl;
		return ;
	}
	else if (p_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << p_name << " has no energy points left to attack." << std::endl;
		return ;
	}
	p_energyPoints--;
	std::cout << "ScavTrap " << p_name << " attacks " << target << ", causing " << p_attackDamage
		<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (p_gateKeeperMode)
	{
		std::cout << "Scavtrap " << p_name << " is already in Gate keeper mode." << std::endl;
		return ;
	}
	p_gateKeeperMode = true;
	std::cout << "Scavtrap " << p_name << " is now in Gate keeper mode." << std::endl;
}
