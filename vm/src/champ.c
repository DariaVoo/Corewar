/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:00:59 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 14:04:25 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		init_champ(t_champion *champ, int id)
{
	champ->code = NULL;
	champ->id = id;
	champ->next = NULL;
	champ->last_live = 0;
	champ->curr_lives_num = 0;
	champ->prev_lives_num = 0;
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
