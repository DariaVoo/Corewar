/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:16:00 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/08 15:42:31 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_ldi(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	shift = get_args(args, arena, carriage, g_optab);
	ft_printf("shift = %d\nargs : %d %d %d\n",shift, args[0].value,  args[1].value,  args[2].value);
	if (shift == 0)
		return (0);
	take_args(arena, carriage, THIRD);
	address = carriage->program_counter + (args[FIRST].value + args[SECOND].value) % IDX_MOD;
	address = address < 0 ? MEM_SIZE + address : address;
	regs[args[THIRD].value] = get_arg(arena + address, REG_CODE, g_optab[carriage->opcode - 1]);
	return (shift);
}