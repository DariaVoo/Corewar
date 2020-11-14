/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:48:28 by sweet-cacao       #+#    #+#             */
/*   Updated: 2020/11/14 21:19:52 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_sort		*get_next(t_sort *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

t_sort		*add_block(char *label)
{
	t_sort	*sort;

	sort = (t_sort*)malloc(sizeof(t_sort));
	if (!sort)
		return (NULL);
	sort->label = label;
	sort->next = NULL;
	return (sort);
}

void		push_end(char *label, t_sort **sort)
{
	t_sort	*last;
	t_sort	*tmp;

	last = get_next(*sort);
	tmp = add_block(label);
	if (last == NULL)
	{
		(*sort) = tmp;
	}
	else
	{
		last->next = tmp;
	}
}

void		sort_del(t_sort **sort)
{
	t_sort *next;

	if (!sort || !(*sort))
		return ;
	while (*sort)
	{
		next = (*sort)->next;
		if ((*sort)->label)
			ft_strdel(&(*sort)->label);
		free((*sort));
		(*sort) = NULL;
		(*sort) = next;
	}
	if (sort && (*sort))
	{
		free((*sort));
		*sort = NULL;
	}
	sort = NULL;
}
