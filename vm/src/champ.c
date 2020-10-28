/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:00:59 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/30 14:28:17 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		init_champ(t_champion *champ, int id)
{
	champ->code = NULL;
	champ->id = id;
	champ->next = NULL;
}

t_champion		*create_champ(int id)
{
	t_champion	*champ;

	champ = (t_champion*)ft_memalloc(sizeof(t_champion));
	if (!champ)
		exit_error(E_MALLOC);
	init_champ(champ, id);
	return (champ);
}
