#include "asm.h"
#include "../libft/includes/libftprintf.h"

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

void	free_data(t_data *data)
{
	int i;
	int all_instrs;
	int j;

	i = 0;
	j = 0;
	all_instrs = data->instr_num;

	if (data->header != NULL)
		free(data->header);
	while(i < all_instrs)
	{
		j = 0;
		if (data->instrs[i].name != NULL)
			ft_strdel(&data->instrs[i].name);
		if (data->instrs[i].label != NULL)
			ft_strdel(&data->instrs[i].label);
		while(j < 3)
		{
			if (data->instrs[i].args[j].label != NULL)
				ft_strdel(&data->instrs[i].args[j].label);
			j++;
		}
		i++;
	}
	if (data->split != NULL)
		free(data->split);
	if (data->all_labels != NULL)
		free(data->all_labels);
	if (data->label != NULL)
		free(data->label);
	if (data->instrs != NULL)
		free(data->instrs);

}