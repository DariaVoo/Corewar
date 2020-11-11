/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:37:12 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/10 21:18:59 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_carriage(t_carriage *carriage, uint8_t *arena, uint8_t id)
{
	carriage->program_counter = MEM_SIZE / get_number_of_players() * (id - 1);
	carriage->opcode = *(arena + carriage->program_counter);
	ft_memset(carriage->regs, 0, REG_NUMBER);
	carriage->regs[0] = -id;
	carriage->cycle_to_die = 0;
	carriage->carry = 0;
	carriage->live = 0;
	carriage->next = NULL;
	carriage->prev = NULL;
}

t_carriage	*create_carriage()
{
	t_carriage	*carriage;

	carriage = (t_carriage*)ft_memalloc(sizeof(t_carriage));
	if (!carriage)
		exit_error(E_MALLOC);
	carriage->args = (t_arg*)ft_memalloc(sizeof(t_arg) * MAX_ARGS);
	if (!carriage->args)
		exit_error(E_MALLOC);
	return (carriage);
}

void		add_carriage(t_carriage **carriage, uint8_t *arena, uint8_t id)
{
	t_carriage	*new_carriage;

	new_carriage = create_carriage();
	init_carriage(new_carriage, arena, id);
	if (*carriage)
	{
		(*carriage)->prev = new_carriage;
		new_carriage->next = *carriage;
	}
	*carriage = new_carriage;
}

void		set_starter_kit_carriage(t_carriage **carriage, uint8_t *arena)
{
	uint8_t	i;
	uint8_t	count_champ;

	i = 0;
	count_champ = get_number_of_players();
	while (i < count_champ)
	{
		add_carriage(carriage, arena, i + 1);
		i++;
	}
}

// не все копирует
t_carriage	*copy_carriage(t_carriage *carriage)
{
	t_carriage	*copy;

	copy = create_carriage();
	ft_memcpy(copy->regs, carriage->regs, sizeof(int32_t) * REG_NUMBER);
	copy->live = carriage->live;
	copy->carry = carriage->carry;
	return (copy);
}