/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:25:39 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/10 23:33:21 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_sub(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	int32_t		*regs;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	shift = get_args(args, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	regs[args[THIRD].value - 1] = regs[args[FIRST].value - 1] - regs[args[SECOND].value - 1];
	if (regs[args[THIRD].value - 1] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	return (shift);
}