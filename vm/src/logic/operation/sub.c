/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:25:39 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/04 16:01:29 by qjosmyn          ###   ########.fr       */
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
	shift = get_args(&args, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	regs[args[THIRD].value] = regs[args[FIRST].value] - regs[args[SECOND].value];
	if (regs[args[THIRD].value] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	return (shift);
}