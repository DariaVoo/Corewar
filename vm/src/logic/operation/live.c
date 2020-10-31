/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:15:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/31 17:55:47 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_live(uint8_t *arena, t_carriage *carriage)
{
	int32_t		shift;
	t_arg		*args;
	extern t_op	g_optab[17];

	args = carriage->args;
	shift = get_args(&args, arena, carriage, g_optab);
	if (shift == 0)
		return (0);
	if (args[0].value == -carriage->regs[0])
		carriage->live = 1;
	return (shift);
}