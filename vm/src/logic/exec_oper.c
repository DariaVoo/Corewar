/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:48:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 17:01:18 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static int32_t	step_size(uint8_t arg_type, t_op op)
{
	if (arg_type & T_REG)
		return (1);
	else if (arg_type & T_DIR)
		return (op.tdir_size);
	else if (arg_type & T_IND)
		return (IND_SIZE);
	return (0);
}

static int32_t	calc_step(t_carriage *carriage)
{
	int32_t		i;
	uint32_t	step;
	extern t_op	g_optab[17];

	i = 0;
	step = 0;
	step += OPCODE_SIZE + (g_optab[carriage->opcode - 1].bit_type ? 1 : 0);
	while (i < g_optab[carriage->opcode - 1].col_args)
	{
		step += step_size(carriage->args[i].type, g_optab[carriage->opcode - 1]);
		i++;
	}
	return (step);
}

static int8_t	is_args_valid(t_carriage *carriage, uint8_t *arena)
{
	t_arg		*args;
	int32_t		shift;
	int32_t		i;
	int32_t		index;
	extern t_op	g_optab[17];

	args = carriage->args;
	shift = get_args(args, arena, carriage, g_optab);
	ft_printf("opcode : %d \targs %d %d %d\n", carriage->opcode, args[FIRST].value, args[SECOND].value, args[THIRD].value);
	index = carriage->opcode - 1;
	i = 0;
	while (i < g_optab[index].col_args)
	{
		if (!(g_optab[index].type_arg[i] & args[i].type))
			return (0);
		if (args[i].type == T_REG && (args[i].value < 1 || args[i].value > 16))
			return (0);
		i++;
	}
	return (shift);
}

static void		update_opcode(uint8_t *arena, t_carriage *carriage)
{
	extern t_op	g_optab[17];

	carriage->opcode = *(arena + carriage->program_counter);
	if (carriage->opcode >= 1 && carriage->opcode <= 16)
	{
		carriage->cycle_to_die = g_optab[carriage->opcode - 1].cycle_to_die;
	}
}

void			execute_oper(t_vm *vm, t_carriage *carriage)
{
	t_op_func	*param;
	int32_t		shift;
	extern t_op	g_optab[17];

	shift = 0;
	if (carriage->cycle_to_die == 0)
		update_opcode(vm->arena, carriage);
	if (carriage->cycle_to_die > 0)
		carriage->cycle_to_die--;
	if (carriage->cycle_to_die == 0)
	{
		param = NULL;
		if (carriage->opcode >= 1 && carriage->opcode <= 16)
			param = &g_opfunc[carriage->opcode - 1];
		if (param)
		{
			if ((shift = is_args_valid(carriage, vm->arena)) != 0)
				param->func(vm, carriage);
			else
				shift = calc_step(carriage);
			ft_printf("TYT\n");
			if (!(carriage->opcode == OPCODE_ZJMP && carriage->carry == 1))
				carriage->program_counter = calc_addr(carriage->program_counter + OPCODE_SIZE + shift);

		}
		else
			carriage->program_counter = calc_addr(carriage->program_counter + OPCODE_SIZE);
	}
}
