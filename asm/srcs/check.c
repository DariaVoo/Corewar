//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

void    ft_check_header_file(void)
{
	int i = 0;

	char all_ch[] = {COMMENT_CHAR, LABEL_CHAR, ALT_COMMENT_CHAR, DIRECT_CHAR, SEPARATOR_CHAR};
	while (i < 5)
	{
		int k = i + 1;
		if (all_ch[i] == '\n')
			ft_exit("Wrong chars in header\n");
		while (k < 5)
		{
			if ( all_ch[k] == '\n' || all_ch[i] == all_ch[k])
				ft_exit("Wrong chars in header\n");
			k++;
		}
		i++;
	}
//    if (COMMENT_CHAR == '\n' || LABEL_CHAR == '\n' || ALT_COMMENT_CHAR == '\n' || DIRECT_CHAR == '\n' || SEPARATOR_CHAR == '\n')
//    {
//        ft_exit("Wrong chars in header\n");
//
//        //проверить на ОдИнАкОвОсТь всех этих символов
//    }
}

void	ft_check_args(char **av, int ac)
{
    int i = 0;

    if (ac == 1)
        ft_exit("Usage: bla-bla-bla\n");
    while (i < ac)
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