#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"
#include <stdlib.h>
#include <fcntl.h>

char *ft_parse_label(char *split, int *i)
{
	char **labels;

	labels = NULL;
	labels = ft_strsplit(split, LABEL_CHAR);
	if (labels != NULL)
    {
	    if (check_label(labels[0]))
		{
			(*i) += ft_strlen(labels[0]);
	    	return labels[0];
		}
    }
	return NULL;
}
void 	skip_spaces(char *split, int *i)
{
	while (split[*i] == ' ')
	{
		(*i)++;
	}
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
		if (function != NULL && function[0])
			func = function[0];
	}
	while (i < 16)
	{
		if (ft_strcmp(func, commands[i]) == 0)
			return func;
		i++;
	}
	return NULL;
}

void ft_parse_function(char *split, int *i, t_body body)
{
	char **function;

	function = NULL;
	function = ft_strsplit(&split[*i], ' '); //посмотреть будет ли работать если конец строки
	if (function != NULL && function[0] != NULL)
	{
		body.name = check_valid_function(function[0]);
		if (body.name == NULL)
			exit(1);
		else
			(*i) += ft_strlen(body.name);
	}
}

void ft_parse_args(char *split, int *i, t_body body)
{
	char **args;

	args = NULL;
	args = ft_strsplit(split, ',');

}

t_body ft_parse_line(char *split, int line_num, t_label *labels)
{
	t_body body;
	int i;
	char *label;

	i = 0;
	body.label = NULL;
	body.name = NULL;
	if (ft_strchr(split, LABEL_CHAR))
	{
		body.label = ft_parse_label(split, &i);
		//если лейбл есть пушим в конец структуры лейблов
//		if (body.label != NULL)
//			push_back(labels, label);
		if (body.label != NULL)
			skip_spaces(split, &i);
	}
	//если строка закончилась и лейбл тоже некорректный, выдаем ошибку
	if (split[i] == '\0' && body.label == NULL) //пустая строка
		exit(1);
	//если строка не закончилась на лейбле => парсим функцию
	ft_parse_function(split, &i, body);
	ft_parse_args(split, &i, body);
	return body;
}

void ft_parse_body(char **split, int line_num, int all_lines)
{
	t_body body[all_lines];
	t_label *labels;
	int body_num;

	labels = NULL;
	body_num = 0;
	//построчно идем по файлу
	while (split[line_num] != NULL)
	{
		//заполняем тело функции
		body[body_num] = ft_parse_line(split[line_num], line_num, labels);
		//в случае если лейбл считался, но больше ничего нет в функции не обновляем
		//номер элемента
		if (body[body_num].label == NULL && body[body_num].name != NULL)
			body_num++;
		line_num++;
	}
}
