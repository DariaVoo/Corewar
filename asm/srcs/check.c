//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../includes/error.h"
#include "../libft/includes/libftprintf.h"

void    ft_check_header_file(void)
{
	int i;
	int j;
	char all_ch[] = {COMMENT_CHAR, LABEL_CHAR, ALT_COMMENT_CHAR, DIRECT_CHAR, SEPARATOR_CHAR};
	
	if (all_ch[0] == '\n' || all_ch[0] == ' ')
		ft_exit(HEADER_ERR);
	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 5)
		{
			if (all_ch[j] == '\n' || all_ch[i] == all_ch[j] || all_ch[j] == ' ')
				ft_exit(HEADER_ERR);
			j++;
		}
		i++;
	}
	if (COREWAR_EXEC_MAGIC > UINT32_MAX)
		ft_exit(EXEC_MAGIC_ERR);
}

void	ft_check_args(char **av, int ac)
{
	int i = 0;

	if (ac == 1)
		ft_exit(USAGE);
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
    if (ft_strlen(ft_strstr(name, ".s")) != 2)
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