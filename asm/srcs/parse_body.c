#include "asm.h"
#include "../libft/includes/libftprintf.h"

int ft_is_number(char *name)
{
	int i;

	i = 0;

	while(name[i])
	{
		if (i == 0 && (name[i] == '+' || name[i] == '-'))
		{
			i++;
			continue;
		}
		if (name[i] < '0' || name[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

//void	ft_init_structs(t_data *data, int instr_num)
//{
//	data->header = (t_header*)malloc(sizeof(t_header));
//	data->instrs = (t_instr*)malloc(sizeof(t_instr) *10);
//	data->label = (t_label*)malloc(sizeof(t_label));
//	data->header->is_comment = 0;
//	data->header->is_name = 0;
//	data->line_count = 0;
//	data->instr_num = 0;
//}

void 	skip_spaces(char *split, int *i)
{
	while (split[*i] && (split[*i] == ' ' || split[*i] == '\t'))
	{
		(*i)++;
	}
}

int		check_label(char *label)
{
	int 	i;
	int 	j;

	i = 0;
	while (label[i] && label[i] != LABEL_CHAR)
	{
		j = 0;
		while (LABEL_CHARS[j] != '\0' && LABEL_CHARS[j] != label[i]) {
			j++;
		}
		if (LABEL_CHARS[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char *ft_parse_label(char *split, int *i, t_data *data)
{
	char **labels;

	labels = NULL;
	ft_printf("hi");
	skip_spaces(split, i);

	labels = ft_strsplit(&split[*i], LABEL_CHAR);

	if (labels != NULL)
	{
		if (check_label(labels[0]))
		{
			(*i) += ft_strlen(labels[0]);
			//проверка на наличие двоеточия и его пропуск
			//если сразу после нет двоеточия то оно в другом месте
			if (split[*i] && split[*i] == ':')
			{
				(*i)++;
				return labels[0];
			}
			else
				return NULL;
		}
	}
	//по сути этого случая не может быть так как проверка на label char есть раньше
	return NULL;
}

char *check_valid_function(char *func)
{
	int i;
	char **function;
	char *commands[16] = {"live", "ld", "st", "add", "sub",
						  "and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld",
						  "lldi", "lfork", "aff"};

	function = NULL;
	i = 0;
	if (ft_strchr(func, DIRECT_CHAR))
	{
		function = ft_strsplit(func, DIRECT_CHAR);
	}
	if (function != NULL && function[0])
	{
		char *trim_func = ft_strtrim(function[0]);
//		ft_printf("%s\n", trim_func);
		while (i < 16)
		{
//			ft_printf("here");
			if (ft_strcmp(trim_func, commands[i]) == 0)
				return trim_func;
			i++;
		}
	}
	else {
		while (i < 16)
		{
			char *trim_func = ft_strtrim(func);
//			ft_printf("%s\n", trim_func);
//		ft_printf("here");
			if (ft_strcmp(trim_func, commands[i]) == 0)
				return trim_func;
			i++;
		}
	}
	return NULL;
}

void ft_parse_function(char *split, int *i, t_data *data)
{
	char **function;

	function = NULL;
	skip_spaces(split, i);
	if (split[*i])
		function = ft_strsplit(&split[*i], ' '); //посмотреть будет ли работать если конец строки
	if (function != NULL && function[0] != NULL)
	{
//		ft_printf("\nfunc = %s\n", function[0]);
		data->instrs[data->instr_num].name = check_valid_function(function[0]);
		if (data->instrs[data->instr_num].name == NULL)
			exit(1);
		else
		{
//			ft_printf("success_name ");
			(*i) += ft_strlen(function[0]);

		}
	}
}

int massiv_len(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void parse_one_arg(char *arg_old, t_data *data, int num_arg)
{
	int number;
	int i = 0;


	char *arg = ft_strtrim(arg_old);
	if (arg[0] == 'r' && arg[1] && ft_isdigit(arg[1]))
	{
		data->instrs[data->instr_num].args[num_arg].type = "T_REG";
		number = ft_atoi(&arg[1]);
		//неправильное название регистра
		if (!ft_is_number(&arg[1]) || (number < 1 || number > 16))
			exit(1);
		data->instrs[data->instr_num].args[num_arg].value = number;
	}
	else if (ft_strchr(arg, DIRECT_CHAR))
	{
		data->instrs[data->instr_num].args[num_arg].type = "T_DIR";
		if (ft_strchr(arg, LABEL_CHAR))
		{
			if (!arg[0] || !arg[1] || !arg[2])
				exit(1);
			//если есть label, то проверяем все ли стоит на своих местах и записываем его в аргумент
			if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR)
			{
				data->instrs[data->instr_num].args[num_arg].label = &arg[2];
			}
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
	else if (ft_isdigit(arg[1]))
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

void	ft_parse_body(char *str_init, t_data *data)
{
	char	*label;
	int 	symbol_number;
	char *str;

	str = NULL;
	if (ft_strchr(str_init, '#'))
	{
		char **str_lines = ft_strsplit(str_init, '#');
		str = str_lines[0];
	}
	else
		str = str_init;

	symbol_number = 0;
	if (ft_strchr(str, LABEL_CHAR))
	{
//		ft_printf("HERE");
		label = ft_parse_label(str, &symbol_number, data);
		data->instrs[data->instr_num].label = label;
		//если лейбл есть пушим в конец структуры лейблов
		//		if (body.label != NULL)
		//			push_back(labels, label);
		if (data->instrs[data->instr_num].label != NULL)
			skip_spaces(str, &symbol_number);
	}
//	ft_printf("\n%s\n", data->instrs[data->instr_num].label);
	//может быть в другом месте обрабатываются пустые строки?
	if (symbol_number != 0 && data->instrs[data->instr_num].label == NULL) //пустая строка или : в другом месте
	{
		symbol_number = 0;
		skip_spaces(str, &symbol_number);
	}
	else if (str[symbol_number] == '\0')
		return;
	ft_parse_function(str, &symbol_number, data);
	ft_parse_args(str, &symbol_number, data);
	ft_printf("----instr_number---- %d\nlabel = '%s', name = '%s'\n", data->instr_num, data->instrs[data->instr_num].label, data->instrs[data->instr_num].name);
	print_args_struct(data->instrs[data->instr_num].args);
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