/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:16:45 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/04 00:38:01 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(void) : ClapTrap("DefaultDiamond_clap_name"), p_name("DefaultDiamond")
{
	this->p_hitPoints = FragTrap::p_hitPoints;
	this->p_energyPoints = ScavTrap::p_energyPoints;
	this->p_attackDamage = FragTrap::p_attackDamage;
	std::cout << "DiamondTrap " << this->p_name << " created with default constructor"
		<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), p_name(name)
{
	this->p_hitPoints = FragTrap::p_hitPoints;
	this->p_energyPoints = ScavTrap::p_energyPoints;
	this->p_attackDamage = FragTrap::p_attackDamage;
	std::cout << "DiamondTrap " << this->p_name
		<< " created with parameterized constructor" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) : ClapTrap(cpy.p_name + "_clap_name"), ScavTrap(cpy),
	FragTrap(cpy), p_name(cpy.p_name)
{
	this->p_hitPoints = cpy.p_hitPoints;
	this->p_energyPoints = cpy.p_energyPoints;
	this->p_attackDamage = cpy.p_attackDamage;
	std::cout << "DiamondTrap " << this->p_name << " created with copy constructor"
		<< std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->p_name << " destroyed" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondTrap " << this->p_name << " assigned" << std::endl;
	if (this != &other)
	{
		this->p_name = other.p_name;
		this->p_hitPoints = other.p_hitPoints;
		this->p_energyPoints = other.p_energyPoints;
		this->p_attackDamage = other.p_attackDamage;
		this->ClapTrap::p_name = other.p_name + "_clap_name";
	}
	return *this;
}

void	DiamondTrap::attack(std::string const &target)
{
	std::cout << "DiamondTrap " << this->p_name << " uses ScavTrap's attack!" << std::endl;
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap name: " << this->p_name << ", ClapTrap name: "
		<< ClapTrap::p_name << std::endl;
}
