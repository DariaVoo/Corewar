#include "asm.h"
#include "../libft/includes/libftprintf.h"

void	parse_register(char *arg, t_data *data, int num_arg)
{
	int number;

	if (arg[0] == 'r' && arg[1] && ft_isdigit(arg[1]))
	{
		data->instrs[data->instr_num].args[num_arg].type = "T_REG";
		number = ft_atoi(&arg[1]);
		//неправильное название регистра
		if (!ft_is_number(&arg[1]) || (number < 1 || number > 16))
			exit(1);
		data->instrs[data->instr_num].args[num_arg].value = number;
	}
}

void	parse_direct(char *arg, t_data *data, int num_arg)
{
	int number;

	if (ft_strchr(arg, DIRECT_CHAR))
	{
		data->instrs[data->instr_num].args[num_arg].type = "T_DIR";
		if (ft_strchr(arg, LABEL_CHAR))
		{
			if (!arg[0] || !arg[1] || !arg[2])
				exit(1);
			//если есть label, то проверяем все ли стоит на своих местах и записываем его в аргумент
			if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR)
				data->instrs[data->instr_num].args[num_arg].label = ft_strdup(&arg[2]);
			else
				exit(1);
		}
		else
		{
			//если это лейбла нет, то парсим число
			if (arg[0] != DIRECT_CHAR)
				exit(1);
			number = ft_atoi(&arg[1]);
			if (!ft_is_number(&arg[1]))
				exit(1);
			data->instrs[data->instr_num].args[num_arg].value = number;
		}
	}
}

void parse_indirect(char *arg, t_data *data, int num_arg)
{
	int number;

	if (ft_isdigit(arg[1]))
	{
		data->instrs[data->instr_num].args[num_arg].type = "T_IND";
		if (ft_is_number(arg))
		{
			number = ft_atoi(arg);
			data->instrs[data->instr_num].args[num_arg].value = number;
		}
		else
		{
			//аргумент не является числом
			exit(1);
		}
	}
}

void parse_one_arg(char *arg_old, t_data *data, int num_arg)
{
	int number;
	int i = 0;
	char *arg;

	arg = ft_strtrim(arg_old);
//	ft_strdel(&arg_old);
	parse_register(arg, data, num_arg);
	if (data->instrs[data->instr_num].args[num_arg].type == NULL)
		parse_direct(arg, data, num_arg);
	if (data->instrs[data->instr_num].args[num_arg].type == NULL)
		parse_indirect(arg, data, num_arg);
	ft_strdel(&arg);
	//не соответсвует ни одному типу функции
	if (data->instrs[data->instr_num].args[num_arg].type == NULL)
		exit(1);
}

void ft_parse_args(char *split, int *i, t_data *data)
{
	char **args;
	int args_num;
	int j;

	args_num = 0;
	args = NULL;
	j = 0;
	args = ft_strsplit(&split[*i], SEPARATOR_CHAR);//что будет возвращать, если нет запятых
	//надо предусмотреть, чтобы все равно передавалась строка, если запятых нет
	//считаем количество аргументов
	if (args != NULL)
		args_num = massiv_len(args);
	//неверное количество аргументов в функции или их нет
	if (args_num  > 3 || args == NULL)
		exit(1);
	while (args[j] && j < args_num)
	{
//		ft_printf("%s\n", args[j]);
		parse_one_arg(args[j], data, j);
		j++;
	}
	t_instr instr[16]; //структура должна передаваться из мейна
//	if (!valid_args(body, instr))
//		exit(1);

	//парсим аргументы, а потом их валидируем
	//аргументы можно спарсить в массив из трех элементов
	//1) аргументов меньше
	//2) аргументов больше
	//3) аргументы не того типа
}
