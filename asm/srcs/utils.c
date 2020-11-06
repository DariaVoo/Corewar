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

char    *ft_saved_name(char *str)
{
    str = "filename";
    return (str);
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
	while (args[i])
		i++;
	return (i);
}
