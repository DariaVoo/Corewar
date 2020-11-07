/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:14:29 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/07 16:05:02 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_or(uint8_t *arena, t_carriage *carriage)
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
	take_args(arena, carriage, THIRD);
	regs[args[THIRD].value] = args[FIRST].value | args[SECOND].value;
	carriage->carry = regs[args[THIRD].value] == 0 ? 1 : 0;
	return (shift);
}