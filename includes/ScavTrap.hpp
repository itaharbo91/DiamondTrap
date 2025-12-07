/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:34:39 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/03 23:35:07 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &cpy);
	virtual ~ScavTrap(void);

	ScavTrap&	operator=(ScavTrap const &other);

	void		attack(const std::string &target);
	void		guardGate(void);

private:

	bool	p_gateKeeperMode;

};

#endif
