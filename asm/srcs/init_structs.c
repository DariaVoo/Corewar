/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:15:47 by rretta            #+#    #+#             */
/*   Updated: 2020/11/06 22:27:55 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../../vm/libft/includes/libftprintf.h"

void	ft_init_structs(t_data *data, int instr_num)
{
//	data->header = (t_header*)malloc(sizeof(t_header));
	if (!(data->header = (t_header*)malloc(sizeof(t_header))))
		ft_exit(MALLOC_ERR);
	ft_memset(data->header->prog_name, '\0', PROG_NAME_LENGTH + 1);
	ft_memset(data->header->comment, '\0', COMMENT_LENGTH + 1);
	data->instrs = (t_instr*)malloc(sizeof(t_instr)*instr_num);
	data->label = (t_label*)malloc(sizeof(t_label));
	data->header->is_comment = 0;
	data->header->is_name = 0;
	data->line_count = 0;
	data->instr_num = 0;
}