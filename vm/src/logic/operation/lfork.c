/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:49:52 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/09 22:50:05 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_fork(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	t_carriage	*copy;
	extern t_op	g_optab[17];

	args = carriage->args;
	shift = get_args(args, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	copy = carriage;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = copy_carriage(carriage);
	copy->program_counter = args[FIRST].value % MEM_SIZE;
	return (shift);
}