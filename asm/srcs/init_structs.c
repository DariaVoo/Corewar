/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:15:47 by rretta            #+#    #+#             */
/*   Updated: 2020/10/25 20:57:15 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../../vm/libft/includes/libftprintf.h"

void	ft_init_structs(t_data *data)
{
	data->header = (t_header*)malloc(sizeof(t_header));
	data->instrs = (t_instr*)malloc(sizeof(t_instr));
	data->label = (t_label*)malloc(sizeof(t_label));
	data->header->is_comment = 0;
	data->header->is_name = 0;
	data->line_count = 0;
}