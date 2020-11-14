/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sweet-cacao <sweet-cacao@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:50:02 by sweet-cacao       #+#    #+#             */
/*   Updated: 2020/11/14 19:50:02 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"

void	free_massiv(char **massiv)
{
	int i;

	i = 0;
	if (!massiv )
		return;
	while(massiv[i])
	{
		free(massiv[i]);
		i++;
	}
	free(massiv);
}

void	free_instrs(t_data *data, int i)
{
	int j;

	j = 0;
	if (data->instrs[i].labels != NULL)
		sort_del(&data->instrs[i].labels);
	ft_strdel(&data->instrs[i].name);
	ft_strdel(&data->instrs[i].label);
	while(j < 3)
	{
		ft_strdel(&data->instrs[i].args[j].label);
		j++;
	}
}

void	free_data(t_data *data)
{
	int i;
	int all_instrs;
	int j;

	i = 0;
	all_instrs = data->instr_num;
	if (data->header != NULL)
		free(data->header);
	while(i < all_instrs)
	{
		free_instrs(data, i);
		i++;
	}
//	if (data->split != NULL)
//		ft_strdel(&data->split);
	ft_strdel(&data->all_labels);
	if (data->label != NULL)
		free(data->label);
	if (data->instrs != NULL)
		free(data->instrs);
}