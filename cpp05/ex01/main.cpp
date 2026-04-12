/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:39:34 by adamgallot        #+#    #+#             */
/*   Updated: 2026/03/18 04:14:33 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrate hermes("caca", 100);
        Form caca("bonjour", true, 100, 100);

	}
	catch(const std::exception& e)
	{
		std::cerr<<" Erreur Catch"<<e.what() << '\n';
	}
	
}