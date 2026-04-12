/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:39:34 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/17 20:21:56 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrate hermes("caca", 100);

	try
	{
		hermes.GetGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr<<" Erreur Catch"<<e.what() << '\n';
	}
	
}