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
			return labels[0];
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

void ft_parse_function(char *split, int *i, t_body body)
{
	char **function;

	function = NULL;
	function = ft_strsplit(&split[*i], ' ');
	function = ft_strsplit(&split[*i], '%');
	if (function != NULL)
	{
//		body.name = check_valid_function(function[0]);
	}
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
//		if (body.label != NULL)
//			push_back(labels, label);
		if (body.label != NULL)
			skip_spaces(split, &i);
	}
	if (split[i] != '\0')
		ft_parse_function(split, &i, body);
	if (split[i] != '\0' && split[i] != )
	if (split[i] == '\0' && body.label == NULL)
		exit(1);
	return body;
}

void ft_parse_body(char **split, int line_num, int all_lines)
{
	t_body body[all_lines];
	t_label *labels;
	int body_num;

	labels = NULL;
	body_num = 0;
	while (split[line_num] != NULL)
	{
		body[body_num] = ft_parse_line(split[line_num], line_num, labels);
		line_num++;
		body_num++;
	}
}
