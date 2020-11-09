/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:04:57 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/08 16:10:53 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			op_sti(uint8_t *arena, t_carriage *carriage)
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
	take_args(arena, carriage, FIRST);
	address = carriage->program_counter + (args[SECOND].value + args[THIRD].value) % IDX_MOD;
	address = address < 0 ? MEM_SIZE + address : address;
	//Усечение, так как каст из 32 к 8
	*(int32_t*)(arena + address) = regs[args[FIRST].value];
	return (shift);
}