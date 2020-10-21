// #include "../includes/asm.h"
// #include "../libft/includes/libftprintf.h"
// #include <stdlib.h>
// #include <fcntl.h>

// char *ft_parse_label(char *split, int *i)
// {
// 	char **labels;

// 	labels = NULL;
// 	labels = ft_strsplit(split, LABEL_CHAR);
// 	if (labels != NULL)
//     {
// 	    if (check_label(labels[0]))
// 		{
// 			(*i) += ft_strlen(labels[0]);
// 	    	return labels[0];
// 		}
//     }
// 	return NULL;
// }
// void 	skip_spaces(char *split, int *i)
// {
// 	while (split[*i] == ' ')
// 	{
// 		(*i)++;
// 	}
// }

// char *check_valid_function(char *func)
// {
// 	int i;
// 	char **function;
// 	char *commands[16] = {"live", "ld", "st", "add", "sub",
// 	"and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld",
// 	"lldi", "lfork", "aff"};

// 	function = NULL;
// 	i = 0;
// 	if (ft_strchr(func, DIRECT_CHAR))
// 	{
// 		function = ft_strsplit(func, DIRECT_CHAR);
// 		if (function != NULL && function[0])
// 			func = function[0];
// 	}
// 	while (i < 16)
// 	{
// 		if (ft_strcmp(func, commands[i]) == 0)
// 			return func;
// 		i++;
// 	}
// 	return NULL;
// }

// void ft_parse_function(char *split, int *i, t_body body)
// {
// 	char **function;

// 	function = NULL;
// 	function = ft_strsplit(&split[*i], ' '); //посмотреть будет ли работать если конец строки
// 	if (function != NULL && function[0] != NULL)
// 	{
// 		body.name = check_valid_function(function[0]);
// 		if (body.name == NULL)
// 			exit(1);
// 		else
// 			(*i) += ft_strlen(body.name);
// 	}
// }

// int massiv_len(char **args)
// {
// 	int i;

// 	i = 0;
// 	while (args[i])
// 		i++;
// 	return (i);
// }

// int ft_is_number(char *name)
// {
// 	int i;

// 	i = 0;
// 	while(name[i])
// 	{
// 		if (name[i] < '0' || name[i] > '9')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void parse_one_arg(char *arg, t_body body, int num_arg)
// {
// 	int number;

// 	if (arg[0] == 'r' && ft_isdigit(arg[1]))
// 	{
// 		body.args[num_arg].type = "T_REG";
// 		number = ft_atoi(&arg[0]);
// 		//неправильное название регистра
// 		if (!ft_is_number(&arg[1]) || (number < 1 || number > 16))
// 			exit(1);
// 		body.args[num_arg].value = number;
// 	}
// 	else if (ft_strchr(arg, DIRECT_CHAR))
// 	{
// 		body.args[num_arg].type = "T_DIR";
// 		if (ft_strchr(arg, LABEL_CHAR))
// 		{
// 			//если есть label, то проверяем все ли стоит на своих местах и записываем его в аргумент
// 			if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR)
// 			{
// 				body.args[num_arg].label = &arg[2];
// 			}
// 			else
// 				exit(1);
// 		}
// 		else
// 		{
// 			//если это лейбла нет, то парсим число
// 			number = ft_atoi(&arg[0]);
// 			if (!ft_is_number(&arg[1]))
// 				exit(1);
// 			body.args[num_arg].value = number;
// 		}
// 	}
// 	else if (ft_isdigit(arg[1]))
// 	{
// 		body.args[num_arg].type = "T_IND";
// 		if (ft_is_number(arg))
// 		{
// 			number = ft_atoi(arg);
// 			body.args[num_arg].value = number;
// 		}
// 		else
// 		{
// 			//аргумент не является числом
// 			exit(1);
// 		}
// 	}
// }

// int valid_args(t_body body, t_instr instr[16])
// {
// 	int i;
// 	int num_args;

// 	i = 0;
// 	num_args = instr[body.id_instr].num_args;
// 	//проверка количества аругументов
// 	while (i < 3)
// 	{
// 		if ((num_args - 1) == i)
// 		{
// 			if (i < 3 && body.args[i].type != NULL)
// 			{
// 				//количество аргументов больше, чем нужно
// 				exit(1);
// 			}
// 			else
// 				return (1);
// 		}
// 		if (body.args[i].type != NULL &&
// 		!((ft_strcmp(body.args[i].type, "T_DIR") == 0) && instr[body.id_instr].type[i].t_dir == 1) &&
// 		!((ft_strcmp(body.args[i].type, "T_IND") == 0) && instr[body.id_instr].type[i].t_ind == 1) &&
// 		!((ft_strcmp(body.args[i].type, "T_REG") == 0) && instr[body.id_instr].type[i].t_reg == 1))
// 		{
// 			//неправильный тип аргумента или аргументов слишком мало
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void ft_parse_args(char *split, int *i, t_body body)
// {
// 	char **args;
// 	int args_num;
// 	int j;

// 	args_num = 0;
// 	args = NULL;
// 	j = 0;
// 	args = ft_strsplit(split, SEPARATOR_CHAR);//что будет возвращать, если нет запятых
// 	//надо предусмотреть, чтобы все равно передавалась строка, если запятых нет
// 	//считаем количество аргументов
// 	if (args != NULL)
// 		args_num = massiv_len(args);
// 	//неверное количество аргументов в функции или их нет
// 	if (args_num  > 3 || args == NULL)
// 		exit(1);
// 	while (j < args_num)
// 	{
// 		parse_one_arg(args[j], body, j);
// 		j++;
// 	}
// 	t_instr instr[16]; //структура должна передаваться из мейна
// 	if (!valid_args(body, instr))
// 		exit(1);

// 	//парсим аргументы, а потом их валидируем
// 	//аргументы можно спарсить в массив из трех элементов
// 	//1) аргументов меньше
// 	//2) аргументов больше
// 	//3) аргументы не того типа
// }

// t_body ft_parse_line(char *split, int line_num, t_label *labels)
// {
// 	t_body body;
// 	int i;
// 	char *label;

// 	i = 0;
// 	body.label = NULL;
// 	body.name = NULL;
// 	if (ft_strchr(split, LABEL_CHAR))
// 	{
// 		body.label = ft_parse_label(split, &i);
// 		//если лейбл есть пушим в конец структуры лейблов
// //		if (body.label != NULL)
// //			push_back(labels, label);
// 		if (body.label != NULL)
// 			skip_spaces(split, &i);
// 	}
// 	//если строка закончилась и лейбл тоже некорректный, выдаем ошибку
// 	if (split[i] == '\0' && body.label == NULL) //пустая строка
// 		exit(1);
// 	//если строка не закончилась на лейбле => парсим функцию
// 	ft_parse_function(split, &i, body);
// 	ft_parse_args(split, &i, body);
// 	return body;
// }

// void valid_count_label(t_body body)
// {

// }

// void ft_parse_body(char **split, int line_num, int all_lines)
// {
// 	t_body body[all_lines];
// 	t_label *labels;
// 	int body_num;
// 	int i;

// 	i = 0;
// 	labels = NULL;
// 	body_num = 0;
// 	//построчно идем по файлу
// 	while (split[line_num] != NULL)
// 	{
// 		//заполняем тело функции
// 		body[body_num] = ft_parse_line(split[line_num], line_num, labels);
// 		//в случае если лейбл считался, но больше ничего нет в функции не обновляем
// 		//номер элемента
// 		if (body[body_num].label == NULL && body[body_num].name != NULL)
// 			body_num++;
// 		line_num++;
// 	}
// 	//валидация лейблов в аргументе и расчет лейбла
// 	while (i < all_lines)
// 	{
// 		valid_count_label(body[i]);
// 		i++;
// 	}
// }
