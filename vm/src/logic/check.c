/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:13:26 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 12:37:17 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int8_t	is_died(t_vm *vm, t_carriage *carriage)
{
	return (vm->cycle_to_die <= 0
			|| vm->iter_from_start - carriage->last_live >= vm->cycle_to_die);
}

static void	delete_died_carriage(t_vm *vm)
{
	t_carriage	*prev;
	t_carriage	*curr;
	t_carriage	*del;

	prev = NULL;
	curr = vm->carriage;
	while (curr)
	{
		if (is_died(vm, (del = curr)) && vm->carriage_num--)
		{
			curr = curr->next;
			if (vm->carriage = del)
				vm->carriage = curr;
			if (prev)
				prev->next = curr;
			// мб утечка
			ft_memdel((void**)&del);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

int32_t		cycles_to_die_check(t_vm *vm)
{
	vm->check_num++;
	delete_died_carriage(vm);
	if(vm->check_num == MAX_CHECKS || vm->lives_num >= NBR_LIVE)
	{
		vm->cycle_to_die -= CYCLE_TO_DIE;
		vm->check_num = 0;
	}
	
	vm->cycle_after_check = 0;
}