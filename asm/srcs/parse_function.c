#include "asm.h"
#include "../libft/includes/libftprintf.h"

int		check_valid_function(char *func, t_data *data)
{
	int i;
	char **function;
	char *commands[16] = {"live", "ld", "st", "add", "sub",
						  "and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld",
						  "lldi", "lfork", "aff"};

	function = NULL;
	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(func, commands[i]) == 0)
		{
			data->instrs[data->instr_num].id_instr = i;
			return 1;
		}
		i++;
	}
	return 0;
}

char		*split_and_get_function_name(char *split, char split_char, t_data *data)
{
	char 	**function;
	char	*name;

	name = NULL;
	function = NULL;
	if (split[0])
		function = ft_strsplit(split, split_char);
	if (function != NULL && function[0] != NULL && check_valid_function(function[0], data))
	{
		name = ft_strdup(ft_strtrim(function[0]));
		free_massiv(function);
		return (name);
	}
	return NULL;
}

char		*ft_get_function_name(char *split, int *i, t_data *data)
{
	char	*name;

	name = NULL;
	skip_spaces(split, i);
	name = split_and_get_function_name(&split[*i], ' ', data);//посмотреть будет ли работать если конец строки
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
	{
		exit(1);
	}
}
