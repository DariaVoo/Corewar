/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:15:23 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 14:19:12 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_zjmp(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	extern t_op	g_optab[17];

	(void)vm->arena;
	args = carriage->args;
	if (carriage->carry)
		carriage->program_counter += args[FIRST].value % IDX_MOD;
}