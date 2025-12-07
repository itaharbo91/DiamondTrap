/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:55:34 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/04 00:41:27 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n=== [CONSTRUCTION] ===\n" << std::endl;
	ClapTrap	ct("Clappy");
	ScavTrap	st("Scavy");
	FragTrap	ft("Fraggy");
	DiamondTrap	dt("Diamondy");

	std::cout << "\n=== [COPIE & ASSIGNATION] ===\n" << std::endl;
	ClapTrap	ct2 = ct;
	ScavTrap	st2(st);
	FragTrap	ft2;
	ft2 = ft;
	DiamondTrap	dt2(dt);
	dt2.whoAmI();
	DiamondTrap	dt3;
	dt3 = dt;
	dt3.whoAmI();

	std::cout << "\n=== [ACTIONS DE BASE] ===\n" << std::endl;
	ct.attack("Scavy");
	st.takeDamage(5);
	st.beRepaired(3);

	st.attack("Fraggy");
	ft.takeDamage(20);
	ft.beRepaired(10);

	std::cout << "\n=== [CAPACITÉS SPÉCIALES] ===\n" << std::endl;
	st.guardGate();
	ft.highFivesGuys();

	std::cout << "\n=== [ACTIONS DIAMONDTRAP] ===\n" << std::endl;
	dt.attack("Fraggy");
	dt.takeDamage(30);
	dt.beRepaired(5);
	dt.guardGate();
	dt.highFivesGuys();
	dt.whoAmI();

	std::cout << "\n=== [CAS LIMITES] ===\n" << std::endl;
	for (int i = 0; i < 11; ++i)
		ct.attack("Scavy");
	st.takeDamage(200);
	st.beRepaired(10);
	st.attack("Fraggy");

	dt.takeDamage(200);
	dt.attack("Fraggy");
	dt.beRepaired(10);

	std::cout << "\n=== [DESTRUCTION AUTOMATIQUE] ===\n" << std::endl;

	return 0;
}
