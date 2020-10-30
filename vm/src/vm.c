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

void		init_arena(uint8_t *arena, t_champion *champ[])
{
	uint8_t	i;
	uint8_t	count_champ;

	i = 0;
	count_champ = get_number_of_players();
	while (champ[i])
	{
		ft_memmove(&(arena[i * MEM_SIZE / count_champ]), champ[i]->code, \
					champ[i]->header.prog_size);
		i++;
	}
}

void		init_vm(t_vm *vm, t_champion *champ[], \
					uint8_t *arena, t_carriage *carriage)
{
	vm->champ = champ;
	vm->arena = arena;
	vm->carriage = carriage;
	vm->count_champs = get_number_of_players();
	vm->cycle_dump = get_number_dump_cycle();
}
