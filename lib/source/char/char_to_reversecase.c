/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_reversecase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:28:48 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/30 21:29:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

int32_t	char_to_reversecase(int32_t ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	else if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	else
		return (ch);
}
