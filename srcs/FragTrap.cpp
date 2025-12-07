/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:50:03 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/03 23:07:21 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void) : ClapTrap()
{
	this->p_name = "Default_FragTrap";
	this->p_hitPoints = 100;
	this->p_energyPoints = 100;
	this->p_attackDamage = 30;
	std::cout << "FragTrap " << p_name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->p_hitPoints = 100;
	this->p_energyPoints = 100;
	this->p_attackDamage = 30;
	std::cout << "FragTrap " << p_name << " name parameter constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap " << p_name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << p_name << " destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FragTrap " << p_name << " assignment operator called" << std::endl;
	if (this != &other)
	{
		this->p_name = other.p_name;
		this->p_hitPoints = other.p_hitPoints;
		this->p_energyPoints = other.p_energyPoints;
		this->p_attackDamage = other.p_attackDamage;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << p_name << " is requesting a high five! ✋" << std::endl;
}
