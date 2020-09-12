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