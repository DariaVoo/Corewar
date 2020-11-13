#include "asm.h"

char *get_label_string(t_sort *sort)
{
	t_sort *tmp = sort;
	char *str = " ";
	while(tmp)
	{
		str = ft_strjoin(str, tmp->label);
		str = ft_strjoin(str, " ");
		tmp = tmp->next;
	}
	return str;
}

void print_args_struct(t_arg arg[3])
{
	int i = 0;
	while(i < 3) {
		ft_printf("arg_number = '%d', type = '%d', "
				  "label = '%s', value = '%d'\n",
				  arg[i].arg_number, arg[i].type, arg[i].label,
				  arg[i].value);
		i++;
	}
}

void	skip_comment(char *str_init, char **str)
{
	char **str_lines;

	str_lines = NULL;
//	str = NULL;
	if (ft_strchr(str_init, COMMENT_CHAR))
	{
		str_lines = ft_strsplit(str_init, COMMENT_CHAR);
		*str = ft_strdup(str_lines[0]);
		free_massiv(str_lines);
	}
	else if (ft_strchr(str_init, ALT_COMMENT_CHAR))
	{
		str_lines = ft_strsplit(str_init, ALT_COMMENT_CHAR);
		*str = ft_strdup(str_lines[0]);
		free_massiv(str_lines);
	}
	else
		*str = ft_strdup(str_init);
}

void	go_to_start_if_label_in_arg(char *str, int *symbol_number, t_data *data)
{
	if (*symbol_number != 0 && data->instrs[data->instr_num].label == NULL) //пустая строка или : в другом месте
	{
		*symbol_number = 0;
		skip_spaces(str, symbol_number);
	}
}

void	ft_parse_label_init(char *str, t_data *data, int *symbol_number, char **label1)
{
	char	*label;

	if (ft_strchr(str, LABEL_CHAR))
	{
		label = ft_parse_label(str, symbol_number);
		*label1 = label;
		if (label != NULL)
		{
			if (data->instrs[data->instr_num].label == NULL)
			{
				data->instrs[data->instr_num].label = label;
				data->instrs[data->instr_num].labels = add_block(ft_strdup(label));
			}
			else
				push_end(label, &data->instrs[data->instr_num].labels);
		}
	}
}

void	ft_parse_body(char *str_init, t_data *data)
{
	int 	symbol_number;
	char	*str;
	char *label;

	skip_comment(str_init, &str);
	symbol_number = 0;
	data->instrs[data->instr_num].sum_size = 0;
	data->instrs[data->instr_num].id = data->instr_num;
	data->symbol_number = &symbol_number;
	data->split = str_init;
	ft_parse_label_init(str, data, &symbol_number, &label);
	skip_spaces(str, &symbol_number);
	go_to_start_if_label_in_arg(str, &symbol_number, data);
	if (str[symbol_number] == '\0')
	{
		ft_strdel(&str);
		return;
	}
	ft_parse_function(str, &symbol_number, data);
	ft_parse_args(str, &symbol_number, data);
	ft_count_size(data);
//	if (data->instr_num < 3)
//	{
		ft_printf("----instr_number---- %d\nlabels = '%s', label = '%s', name = '%s', id = '%d', id_instr = '%d', size = '%d'\n", data->instr_num, get_label_string(data->instrs[data->instr_num].labels), data->instrs[data->instr_num].label, data->instrs[data->instr_num].name, data->instrs[data->instr_num].id, data->instrs[data->instr_num].id_instr, data->instrs[data->instr_num].size);
		print_args_struct(data->instrs[data->instr_num].args);
//	}
	data->instr_num += 1;
	ft_strdel(&str);
}
