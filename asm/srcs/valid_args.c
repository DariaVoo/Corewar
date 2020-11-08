#include "asm.h"
#include "../libft/includes/libftprintf.h"

int		valid_args(t_data *data)
{
	int i;
	int num_args;
	int bool;

	i = 0;
	bool = 0;
	num_args = g_op_tab[data->instrs[data->instr_num].id_instr].col_args;
	//проверка количества аругументов
	while (i < 3)
	{
		bool = 0;
		if ((num_args) == i)
		{
			//количество аргументов больше, чем нужно
			if (i < 3 && data->instrs[data->instr_num].args[i].type != 0)
				return TOO_MANY_ARGS;
			else
			{
//				ft_printf("\n");
				return (1);
			}
		}
		//или аргументов слишком мало
		if (data->instrs[data->instr_num].args[i].type == 0)
			return FEW_ARGS;
		//неправильный тип аргумента
		if (data->instrs[data->instr_num].args[i].type == T_DIR)
		{
			bool = T_DIR &  g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
		}
		else if (data->instrs[data->instr_num].args[i].type == T_IND)
		{
			bool = T_IND &  g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
		}
		else if (data->instrs[data->instr_num].args[i].type == T_REG)
		{
//			ft_printf("here %d, %d", T_REG, g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i]);
			bool = T_REG & g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
		}
		else
			return INVALID_TYPE;
//		ft_printf("%d, ", bool);
		if (!bool)
			return INVALID_TYPE;
		i++;
	}
//	ft_printf("\n");
	return (1);
}