/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:27:24 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 16:17:40 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"
#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"

#include "Comet.hpp"
#include "Asteroid.hpp"

int			main(void)
{
	MiningBarge		usg_ishimura;
	StripMiner		sm_laser;
	DeepCoreMiner	dcm_laser;

	Comet			helfenzrieder;
	Asteroid		vesta;

	usg_ishimura.mine(&helfenzrieder);
	usg_ishimura.mine(&vesta);
	std::cout << std::endl;

	usg_ishimura.equip(&sm_laser);
	usg_ishimura.equip(&sm_laser);
	usg_ishimura.equip(&dcm_laser);
	usg_ishimura.equip(&dcm_laser);

	std::cout << "[USG Ishimura is mining " << helfenzrieder.getName() << " Helfenzrieder]" << std::endl;
	usg_ishimura.mine(&helfenzrieder);
	std::cout << std::endl;

	std::cout << "[USG Ishimura is mining " << vesta.getName() << " Vesta]" << std::endl;
	usg_ishimura.mine(&vesta);

	return (0);
}
