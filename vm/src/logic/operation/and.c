/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:12:08 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/12 22:03:36 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_and(uint8_t *arena, t_carriage *carriage)
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
	ft_putstr("args: ");
	ft_putnbr(args[FIRST].value);
	ft_putnbr(args[SECOND].value);
	ft_putnbr(args[THIRD].value);
	regs[args[THIRD].value - 1] = args[FIRST].value & args[SECOND].value;
	ft_printf("\nregs = %d \n", regs[args[THIRD].value - 1]);
	carriage->carry = regs[args[THIRD].value - 1] == 0 ? 1 : 0;
	return (shift);
}