/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:25:39 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 19:34:43 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_sub(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	(void)vm->arena;
	regs[args[THIRD].value - 1] = regs[args[FIRST].value - 1] - \
												regs[args[SECOND].value - 1];
	if (regs[args[THIRD].value - 1] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
