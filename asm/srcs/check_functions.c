//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

void    ft_check_header_file(void)
{
    if (COMMENT_CHAR == '\n' || LABEL_CHAR == '\n' || ALT_COMMENT_CHAR == '\n' || DIRECT_CHAR == '\n' || SEPARATOR_CHAR == '\n')
    {
        ft_exit("Wrong chars in header\n");
    }
}

void	ft_check_args(char **av, int ac)
{
    int i = 0;

    if (ac == 1)
        ft_exit("Usage: bla-bla-bla\n");
    while (av && *av)
    {
        if (i == ac - 1)
            ft_check_filename(av[i]);
        else
            ft_check_flags(av[i]);
        i++;
    }
}

void	ft_check_filename(char *name)
{
    if (ft_strlen(ft_strstr(name, ".s")) != 2 && ft_strlen(name) < 3)
        ft_exit("Bad file name\n");
    else
        ft_printf("File: %s\n", name);
}

