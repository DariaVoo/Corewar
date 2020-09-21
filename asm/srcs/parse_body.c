#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"
#include <stdlib.h>
#include <fcntl.h>

char *ft_parse_label(char *split, int *i)
{
	char **labels;

	labels = NULL;
	labels = ft_strsplit(split, ':');
	if (labels != NULL)
    {
	    check_label(labels[0]);
    }
}

void ft_parse_line(char *split, int line_num)
{
	int i;
	char *label;

	i = 0;
	if (ft_strchr(split, ':'))
		label = ft_parse_label(split, &i);
}

void ft_parse_body(char **split, int line_num)
{
	while (split[line_num] != '\0')
	{
		ft_parse_line(split[line_num], line_num);
		line_num++;
	}
}
