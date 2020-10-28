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

static void			init_carriage(t_carriage *carriage, int id)
{
	carriage->opcode = 0;
	carriage->cycle_to_die = 0;
	carriage->program_counter = MEM_SIZE / get_number_of_players() * (id - 1);
	ft_memset(carriage->regs, 0, REG_NUMBER);
	carriage->regs[0] = -id;
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

void				add_carriage(t_carriage **carriage, uint8_t id)
{
	t_carriage	*new_carriage;

	new_carriage = create_carriage();
	init_carriage(new_carriage, id);
	if (*carriage)
		new_carriage->next = *carriage;
	*carriage = new_carriage;
}

void				set_starter_kit_carriage(t_carriage **carriage, char *champ_names[])
{
	uint8_t	i;

	i = 0;
	while (champ_names[i])
	{
		add_carriage(carriage, i + 1);
		i++;
	}
}
