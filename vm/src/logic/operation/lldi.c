/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:12:22 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/07 18:12:55 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_lldi(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	shift = get_args(args, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	take_args(args, carriage, THIRD);
	address = carriage->program_counter + (args[FIRST].value + args[SECOND].value) % IDX_MOD;
	address = address < 0 ? MEM_SIZE + address : address;
	regs[args[THIRD].value] = get_arg(arena + address, REG_CODE, g_optab[carriage->opcode - 1]);
	return (shift);
}