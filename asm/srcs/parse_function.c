#include "asm.h"

int		check_valid_function(char *func, t_data *data)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(func, g_op_tab[i].name_oper) == 0)
		{
			data->instrs[data->instr_num].id_instr = i;
			return (1);
		}
		i++;
	}
	return (0);
}

char		*split_and_get_function_name(char *split, char split_char, t_data *data)
{
	char 	**function;
	char	*name;

	function = NULL;
	if (split[0])
		function = ft_strsplit(split, split_char);
	if (function != NULL && function[0] != NULL && check_valid_function(function[0], data))
	{
		name = ft_strtrim(function[0]);
		free_massiv(function);
		return (name);
	}
	if (function != NULL)
		free_massiv(function);
	return NULL;
}

char		*ft_get_function_name(char *split, int *i, t_data *data)
{
	char	*name;

	skip_spaces(split, i);
	name = split_and_get_function_name(&split[*i], ' ', data);//посмотреть будет ли работать если конец строки
	if (name == NULL)
		name = split_and_get_function_name(&split[*i], '\t', data);
	if (name == NULL && ft_strchr(split, DIRECT_CHAR))
		name = split_and_get_function_name(&split[*i], DIRECT_CHAR, data);
	return (name);
}

void		ft_parse_function(char *split, int *i, t_data *data)
{
	char 	*name;

	name = ft_get_function_name(split, i, data);
	if (name != NULL)
	{
		data->instrs[data->instr_num].name = name;
		(*i) += ft_strlen(name);
	}
	else
		free_close_fd_put_error("Invalid function name", split, data, *i);
}
