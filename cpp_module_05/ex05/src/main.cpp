/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:01:10 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/28 07:38:13 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"

int			main(void)
{
	Bureaucrat				*bc;
	CentralBureaucracy		cb;
	std::string				bc_names[] =
	{
		"Randal Coffin",
		"Vigdis Thornburg",
		"Youlanda Daly",
		"Reinaldo Bartley",
		"Daffi Hood",
		"Savion Webber",
		"Van Kemp",
		"Delynden Landers",
		"Iliana Daily",
		"Gemal Langston",
		"Jinia Banks",
		"Haunani Kohl",
		"Bowden Williamson",
		"Khaleel Renfro",
		"Veleslav Mckenney",
		"Glaucilena Bethel",
		"Reuben Chism",
		"Alixyvetta Reeder",
		"Alene Huntington",
		"Sallianne Lee",
		"Carrieann Breeden",
		"Natty Coon",
		"Keesha Holman",
		"Sinclare Marsh",
		"Amoretta Guzman",
		"Georges Salcedo",
		"Jagur Zavala",
		"Charleen Schultz",
		"Steffanie Trotter",
		"Kitra Estes",
		"Amellinda Thorton",
		"Antwoine Potter",
		"Randee Tyson",
		"Barrey Voss",
		"Lilit Mena",
		"Hanny Vela",
		"Jimahl Phipps",
		"Brina Cross",
		"Tremayne Vernon",
		"Wallda Santos"
	};
	std::string				tg_names[] =
	{
		"Haile Giron",
		"Romney Peel",
		"Clairesa Batts",
		"Sarrey Caruso",
		"Gun Lyman",
		"Hediah Dorman",
		"Lateiffa Currier",
		"Lew Richard",
		"Skie Bayne",
		"Junko Jorgensen",
		"Amelida Huey",
		"Graeham Wilkinson",
		"Siprien Churchill",
		"Burne Pratt",
		"Salyssa Gavin",
		"Nadia Mock",
		"Lindsee Velasquez",
		"Dennis Sizemore",
		"Lativia Rodriquez",
		"Alexandria Manns",
		"Trillby Easter",
		"Krystalline Dickerson",
		"Sondya Harris",
		"Tiffinie Currie",
		"Fabio Hatley",
		"Brandell Hillman",
		"Jourdanne Smiley",
		"Trasey Turnbull",
		"Godiva Arevalo",
		"Dariane Platt",
		"Preciosa Dobbins",
		"Kamanika Joyner",
		"Dalten Sharp",
		"Kallesta Bedard",
		"Adamik Dockery",
		"Adayre Wheeler",
		"Marrinor Rosenthal",
		"Megaraline Alba",
		"Cleevant Fink",
		"Magnusson Shirley"
	};

	std::srand(std::time(NULL));
	for (size_t i = 0; i < 40; ++i)
	{
		// Note: it leaks but who cares?
		bc = new Bureaucrat(bc_names[i], std::rand() % 50 + 1);
		cb.feedBureaucrat(*bc);
	}
	while (true)
	{
		for (size_t i = 0; i < 40; ++i)
			cb.queueUp(tg_names[i]);
		cb.doBureaucracy();
	}

	return (0);
}
