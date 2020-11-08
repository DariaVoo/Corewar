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
			if (i < 3 && data->instrs[data->instr_num].args[i].type != NULL)
			{
				ft_printf("here");
				return TOO_MANY_ARGS;
//				ft_printf("\n");
				exit(1);
			}
			else
			{
//				ft_printf("\n");
				return (1);
			}
		}
		//или аргументов слишком мало
		if (data->instrs[data->instr_num].args[i].type == NULL)
		{
			return FEW_ARGS;
			exit(1);
		}
		//неправильный тип аргумента
		if (ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_DIR") == 0)
		{
			bool = T_DIR &  g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
		}
		else if (ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_IND") == 0)
		{
			bool = T_IND &  g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
		}
		else if ((ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_REG") == 0))
		{
//			ft_printf("here %d, %d", T_REG, g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i]);
			bool = T_REG & g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i];
		}
		else
		{
			return INVALID_TYPE;
//			ft_printf("%d, ", bool);
			exit(1);
		}
//		ft_printf("%d, ", bool);
		if (!bool)
		{
			return INVALID_TYPE;
			exit(1);
		}
//		if (!((ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_DIR") == 0) && ((T_DIR &&  g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i]) == 1)) &&
//		   !((ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_IND") == 0) && ((T_IND &&  g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i]) == 1)) &&
//		   !((ft_strcmp(data->instrs[data->instr_num].args[i].type, "T_REG") == 0) && ((T_REG &&  g_op_tab[data->instrs[data->instr_num].id_instr].type_arg[i]) == 1)))
//		{
//			exit(1);
//		}
		i++;
	}
//	ft_printf("\n");
	return (1);
}