/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:49:52 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 19:33:11 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_lfork(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	t_carriage	*copy;
	extern t_op	g_optab[17];

	args = carriage->args;
	copy = carriage;
	while (copy->next != NULL)
		copy = copy->next;
	(void)vm->arena;
	copy->next = copy_carriage(carriage);
	copy->next->prev = copy;
	copy = copy->next;
	copy->program_counter = args[FIRST].value % MEM_SIZE;
}
