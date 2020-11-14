/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:16:00 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 19:33:14 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdio.h"

void		op_ldi(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	args = take_args(vm->arena, carriage, THIRD);
	address = carriage->program_counter + (args[FIRST].value \
												+ args[SECOND].value) % IDX_MOD;
	address = address < 0 ? MEM_SIZE + address : address;
	regs[args[THIRD].value - 1] = get_arg(vm->arena, address, REG_CODE, \
												g_optab[carriage->opcode - 1]);
}
