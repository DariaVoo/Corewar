/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:12:22 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 19:34:02 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_lldi(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	take_args(vm->arena, carriage, THIRD);
	address = carriage->program_counter + (args[FIRST].value \
											+ args[SECOND].value) % MEM_SIZE;
	address = address < 0 ? MEM_SIZE + address : address;
	regs[args[THIRD].value - 1] = get_arg(vm->arena, address, REG_CODE, \
												g_optab[carriage->opcode - 1]);
	carriage->carry = regs[args[THIRD].value - 1] == 0 ? 1 : 0;
}
