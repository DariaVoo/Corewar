//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

int     ft_parse_header(char **split, int i)
{
    while (split && *split != NULL)
    {
        ft_printf("%s\n", *split);
        split++;
        i++;
    }
    return (i);
}
