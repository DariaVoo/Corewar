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

t_carriage	*init_carriage(int col_champs, int id)
{
	t_carriage	*cursor;

	if ((cursor = (t_carriage*)ft_memalloc(sizeof(t_carriage))) == NULL)
		exit_error("ERROR: MALLOC");
	cursor->opcode = 0;
	cursor->cycle_to_die = 0;
	cursor->program_counter = MEM_SIZE / col_champs * (id - 1);
	ft_memset(cursor->regs, 0, REG_NUMBER);
	cursor->regs[0] = -id;
	cursor->carry = 0;
	cursor->live = 0;
	cursor->next = NULL;
	return (cursor);
}

t_champion		*init_champ(int id)
{
	t_champion	*champ;

	if ((champ = (t_champion*)ft_memalloc(sizeof(t_champion))) == NULL)
		exit_error("ERROR: MALLOC");
	champ->code = NULL;
	champ->id = id;
	champ->next = NULL;
	return (champ);
}

void			init_vm(t_vm *vm)
{
	vm->champs = NULL;
	vm->carriage = NULL;
	vm->count_champs = 0;
	ft_memset(vm->arena, 0, MEM_SIZE);
}

void			init_arena(t_vm *vm)
{
	t_champion	*champ;
	size_t		i;

	champ = vm->champs;
	i = 0;
	while (champ)
	{
		ft_memmove(&(vm->arena[i * MEM_SIZE / vm->count_champs]), champ->code, \
													champ->header.prog_size);
		champ = champ->next;
		i++;
	}
}
