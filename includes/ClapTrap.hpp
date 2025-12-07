/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:55:39 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/03 21:33:01 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
public:

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int attackDamage);
	ClapTrap(ClapTrap const &cpy);
	virtual ~ClapTrap(void);

	ClapTrap&			operator=(ClapTrap const &other);

	void				attack(const std::string &target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);

protected:

	std::string		p_name;
	unsigned int	p_hitPoints;
	unsigned int	p_energyPoints;
	unsigned int	p_attackDamage;

};

#endif
