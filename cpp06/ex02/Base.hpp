/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:32:43 by adamgallot        #+#    #+#             */
/*   Updated: 2026/04/02 17:32:44 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP

class Base {
    public:
        virtual ~Base(void);
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
