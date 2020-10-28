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

void		init_arena(t_vm *vm)
{
	uint8_t	i;

	i = 0;
	while (vm->champ[i])
	{
		ft_memmove(&(vm->arena[i * MEM_SIZE / vm->count_champs]), vm->champ[i]->code, \
													vm->champ[i]->header.prog_size);
		i++;
	}
}

void		init_vm(t_vm *vm, t_champion *champ[], t_carriage *carriage)
{
	vm->champ = champ;
	vm->carriage = carriage;
	ft_memset(vm->arena, 0, MEM_SIZE);
	vm->count_champs = get_number_of_players();
	vm->dump_cycle = update_dump_flag(-1);
}
