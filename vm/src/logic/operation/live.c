/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:15:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/22 14:06:20 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

int		op_live(uint8_t *arena, t_carriage *carriage)
{
	uint16_t	*command;

	command = carriage->program_counter + 1;
	if (*command < 1 && *command > 4)
		return (0);
	if (*command == carriage->regs[0])
		carriage->live = TRUE;
	return (1);
}
