//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

void    ft_exit(char *str)
{
    ft_putstr(str);
    exit(1);
}

void    ft_close_fd(int a, int b)
{
    close(a);
    close(b);
}

void 	skip_spaces(char *split, int *i)
{
	while (split[*i] && (split[*i] == ' ' || split[*i] == '\t'))
	{
		(*i)++;
	}
}

int		ft_is_number(char *name)
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

int		massiv_len(char **args)
{
	int i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

int			get_number_of_lines(t_data *data)
{
	char	*string;
	int 	num;
	char	*label;
	int		sym;

	num = 0;
	label = " ";
	while (get_next_line(data->read_fd, &string))
	{
		sym = 0;
		if (ft_strchr(string, LABEL_CHAR))
		{
			if (ft_parse_label(string, &sym) != NULL)
			{
				sym = 0;
				label = ft_strjoin(ft_strjoin(label, ft_parse_label(string, &sym)), " ");
			}
		}
		num++;
	}
	data->all_labels = ft_strdup(label);
	ft_strdel(&string);
	lseek(data->read_fd, 0, 0);
	return (num);
}
