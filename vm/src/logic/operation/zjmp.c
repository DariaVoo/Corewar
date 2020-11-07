/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:15:23 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/06 12:40:39 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_zjmp(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	extern t_op	g_optab[17];

	args = carriage->args;
	shift = get_args(zargs, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	if (carriage->carry)
	{
		carriage->program_counter += args[FIRST].value % IDX_MOD;
	}
	return (shift);
}