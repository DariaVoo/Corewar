/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:22:25 by dima              #+#    #+#             */
/*   Updated: 2020/11/09 23:27:33 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// не все копируется!!!
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
	copy->next->prev = copy;
	copy = copy->next;
	copy->program_counter = args[FIRST].value % IDX_MOD;
	return (shift);
}