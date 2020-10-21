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

