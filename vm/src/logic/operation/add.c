/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:06:49 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 19:31:46 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_add(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	regs[args[THIRD].value - 1] = regs[args[FIRST].value - 1] + \
												regs[args[SECOND].value - 1];
	if (regs[args[THIRD].value - 1] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	(void)vm;
}
