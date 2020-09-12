//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

void    ft_check_flags(char *str)
{
    if (*str == '-')
    {
        str++;
        if (ft_strchr(str, 'a'))
            ft_printf("Нужно передавать структуру и инициализировать флаг А\n");
    }
    ft_printf("%s\n", str);
}


//void    ft_check_filename(char *str)
//{
//    ft_printf("%s\n", str);
//}

