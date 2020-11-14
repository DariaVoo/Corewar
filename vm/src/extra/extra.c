/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:01:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 21:01:39 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_champ(t_champion *champ[])
{
	uint8_t	i;

	i = 0;
	if (!champ)
		return ;
	while (champ[i])
	{
		free(champ[i]->code);
		free(champ[i]);
		champ[i] = NULL;
		i++;
	}
}

void		free_carriage(t_carriage *carriage)
{
	if (!carriage)
		return ;
	free(carriage->args);
	free(carriage);
}

void		free_carriage_list(t_carriage **head_carriage)
{
	t_carriage *current_carriage;

	if (!head_carriage)
		return ;
	while (*head_carriage)
	{
		current_carriage = (*head_carriage);
		*head_carriage = (*head_carriage)->next;
		free_carriage(current_carriage);
	}
}

void		free_arrptr(void *array[])
{
	uint32_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
}

/*
** функция для инициализации массива указателей на что-либо
*/

void		init_arrptr(void **array, uint32_t size)
{
	uint32_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
}
