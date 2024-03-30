/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_check_parity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:37:30 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:33:56 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	bit_check_parity(uint64_t num)
{
	uint64_t	parity;

	parity = 0;
	while (num)
	{
		parity ^= 1;
		num &= (num - 1);
	}
	return (parity);
}
