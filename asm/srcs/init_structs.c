/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:15:47 by rretta            #+#    #+#             */
/*   Updated: 2020/10/27 19:03:36 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../../vm/libft/includes/libftprintf.h"

void	ft_init_structs(t_data *data, int instr_num)
{
	data->header = (t_header*)malloc(sizeof(t_header));
	data->instrs = (t_instr*)malloc(sizeof(t_instr)*instr_num);
	data->label = (t_label*)malloc(sizeof(t_label));
	data->header->is_comment = 0;
	data->header->is_name = 0;
	data->line_count = 0;
	data->instr_num = 0;
}