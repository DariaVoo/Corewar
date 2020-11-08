#include "asm.h"
#include "../libft/includes/libftprintf.h"

void print_args_struct(t_arg arg[3])
{
	int i = 0;
	while(i < 3) {
		ft_printf("arg_number = '%d', type = '%s', "
				  "label = '%s', value = '%d'\n",
				  arg[i].arg_number, arg[i].type, arg[i].label,
				  arg[i].value);
		i++;
	}
}

void	*skip_comment(char *str_init, char **str)
{
	*str = NULL;
	if (ft_strchr(str_init, COMMENT_CHAR))
	{
		char **str_lines = ft_strsplit(str_init, COMMENT_CHAR);
		*str = ft_strdup(str_lines[0]);
		free_massiv(str_lines);
	}
	else
		*str = str_init;
}

void	go_to_start_if_label_in_arg(char *str, int *symbol_number, t_data *data)
{
	if (*symbol_number != 0 && data->instrs[data->instr_num].label == NULL) //пустая строка или : в другом месте
	{
		*symbol_number = 0;
		skip_spaces(str, symbol_number);
	}
}


void	ft_parse_body(char *str_init, t_data *data)
{
	char	*label;
	int 	symbol_number;
	char	*str;

	skip_comment(str_init, &str);
	symbol_number = 0;
	data->instrs[data->instr_num].id = data->instr_num;
	data->symbol_number = &symbol_number;
	data->split = str_init;
	if (ft_strchr(str, LABEL_CHAR))
	{
		label = ft_parse_label(str, &symbol_number, data);
		data->instrs[data->instr_num].label = label;
		//если лейбл есть пушим в конец структуры лейблов
		//		if (body.label != NULL)
		//			push_back(labels, label);
		//если есть лейбл то пропускаем пробелы до функции
	}
	go_to_start_if_label_in_arg(str, &symbol_number, data);
	if (str[symbol_number] == '\0')
		return;
	ft_parse_function(str, &symbol_number, data);
	ft_parse_args(str, &symbol_number, data);
	ft_count_size(data);
	if (data->instr_num < 3)
	{
		ft_printf("----instr_number---- %d\nlabel = '%s', name = '%s', id = '%d', id_instr = '%d', size = '%d'\n", data->instr_num, data->instrs[data->instr_num].label, data->instrs[data->instr_num].name, data->instrs[data->instr_num].id, data->instrs[data->instr_num].id_instr, data->instrs[data->instr_num].size);
		print_args_struct(data->instrs[data->instr_num].args);
	}
	data->instr_num +=1;
}



//int main(void)
//{
//	t_data data;
//	int i = 0;
//	char *str[5] = {"label01: live r10, %:label02, 88",
//			   "\t ld    %-272,r3           ",
//			   "\t fork  %:label01        ",
//			   "   label04:     ",
//			   " sti   r6,r2,r3           "};
//
//	ft_init_structs(&data, 5);
//	while (i < 5)
//	{
//		ft_printf("%s\n", str[i]);
//		ft_parse_body(str[i], &data);
//		data.instr_num--;
//		ft_printf("----instr_number---- %d\nlabel = '%s', name = '%s'\n", data.instr_num, data.instrs[data.instr_num].label, data.instrs[data.instr_num].name);
//		print_args_struct(data.instrs[data.instr_num].args);
//		data.instr_num++;
//		i++;
//	}
//}