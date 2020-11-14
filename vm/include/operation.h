/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:39:20 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/09 23:30:32 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "vm.h"

t_op_func	g_opfunc[17] =
{
	{op_live},
	{op_ld},
	{op_st},
	{op_add},
	{op_sub},
	{op_and},
	{op_or},
	{op_xor},
	{op_zjmp},
	{op_ldi},
	{op_sti},
	{op_fork},
	{op_lld},
	{op_lldi},
	{op_lfork},
	{op_aff},
	{NULL}
};

#endif
