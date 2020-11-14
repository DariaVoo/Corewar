/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:15:23 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/13 22:23:01 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_zjmp(uint8_t *arena, t_carriage *carriage)
{
	t_arg		*args;
	extern t_op	g_optab[17];

	(void)arena;
	args = carriage->args;
	ft_printf("args = %d\t %d\n", args[FIRST].value, carriage->carry);
	if (carriage->carry)
		carriage->program_counter += args[FIRST].value % IDX_MOD;
}