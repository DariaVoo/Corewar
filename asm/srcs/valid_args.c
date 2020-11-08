#include "asm.h"
#include "../libft/includes/libftprintf.h"

int		valid_args(t_data *data)
{
	int i;
	int num_args;

	i = 0;
	num_args = g_op_tab[data->instrs[data->instr_num].id_instr].col_args;
	//проверка количества аругументов
	while (i < 3)
	{
		if ((num_args) == i)
		{
			//количество аргументов больше, чем нужно
			if (i < 3 && data->instrs[data->instr_num].args[i].type != 0)
				exit(1);
			else
				return (1);
		}
		//или аргументов слишком мало
		if (data->instrs[data->instr_num].args[i].type == 0)
			exit(1);
		//неправильный тип аргумента
		if (!(data->instrs[data->instr_num].args[i].type && g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i]))
			exit(1);
		i++;
	}
	return (1);
}