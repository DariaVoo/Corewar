/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:37:12 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/09 18:34:18 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// carriage->opcode = *(champ->code + carriage->program_counter);
static void			init_carriage(t_carriage *carriage, t_champion *champ)
{
	carriage->program_counter = MEM_SIZE / get_number_of_players() * (champ->id - 1);
	ft_memset(carriage->regs, 0, REG_NUMBER);
	carriage->regs[0] = -champ->id;
	carriage->cycle_to_die = CYCLE_TO_DIE;
	carriage->carry = 0;
	carriage->live = 0;
	carriage->next = NULL;
}

static t_carriage	*create_carriage()
{
	t_carriage	*carriage;

	carriage = (t_carriage*)ft_memalloc(sizeof(t_carriage));
	if (!carriage)
		exit_error(E_MALLOC);
	return (carriage);
}

void				add_carriage(t_carriage **carriage, t_champion *champ)
{
	t_carriage	*new_carriage;

	new_carriage = create_carriage();
	init_carriage(new_carriage, champ);
	if (*carriage)
		new_carriage->next = *carriage;
	*carriage = new_carriage;
}

void				set_starter_kit_carriage(t_carriage **carriage, t_champion *champ[])
{
	uint8_t	i;

	i = 0;
	while (champ[i])
	{
		add_carriage(carriage, champ[i]);
		i++;
	}
}
