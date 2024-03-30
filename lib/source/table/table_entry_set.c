/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_entry_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:26:01 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:47:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	table_entry_set(t_table *table, char *key, uintptr_t value)
{
	uint64_t	index;

	index = table_body_find_empty(table, key);
	if (table->body[index].key != 0)
		table->body[index].value = value;
	else
	{
		table->size++;
		if ((float)table->size / (float)table->capacity > 0.8)
		{
			table_body_resize(table, table->capacity * 2);
			index = table_body_find_empty(table, key);
		}
		table->body[index].key = key;
		table->body[index].value = value;
	}
}
