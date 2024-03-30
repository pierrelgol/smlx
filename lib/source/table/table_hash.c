/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:24 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:47:44 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	table_hash(char *str)
{
	unsigned long	seed;
	int				val;

	seed = 5381;
	while (*str)
	{
		val = *str++;
		seed = ((seed << 5) + seed) + (unsigned long)val;
	}
	return (seed);
}
