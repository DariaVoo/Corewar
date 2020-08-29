#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"
#include <stdlib.h>
#include <fcntl.h>

void    ft_exit(char *str)
{
    ft_putstr(str);
    exit(1);
}

void ft_check_filename(char *name)
{
    if (ft_strlen(ft_strstr(name, ".s")) != 2 && ft_strlen(name) < 3)
    {
        ft_exit("Bad file name\n");
    }
    else
    {
        ft_printf("File: %s\n", name);
    }
}

void    ft_check_header()
{
    if (COMMENT_CHAR == '\n' || LABEL_CHAR == '\n' || ALT_COMMENT_CHAR == '\n' || DIRECT_CHAR == '\n' || SEPARATOR_CHAR == '\n')
    {
        ft_exit("Wrong chars in header\n");
    }
}

char	**ft_file_read(char **split, char *filename)
{
    char	tmp[BUFF + 1];
	char	*str;
	char	*str2;
	int		len;

	str = "";
	str2 = "";
    int fd = open(filename, O_RDONLY);
	while ((len = read(fd, tmp, BUFF)) > 0)
	{
		tmp[len] = '\0';
		if ((str2 = ft_strjoin(str, tmp)) == NULL)
			ft_exit("ERROR: STRJOIN ERROR");
		if (*str != '\0')
			free(str);
		str = str2;
	}
	if (len < 0)
		ft_exit("ERROR: INPUT FILE NAME");
	if ((split = ft_strsplit(str2, '\n')) == NULL)
		ft_exit("ERROR: SPLIT ERROR");
	ft_strdel(&str2);
	return (split);
}


int		main(int ac, char **av)
{
//	We have one important question: how much champs we want to process. If only 1:
    if (ac != 2)
        ft_exit("Usage: bla-bla-bla\n");

    char	**split;
    split = NULL;

    ft_check_header();
    ft_check_filename(av[1]);
    split = ft_file_read(split, av[1]);
	

    while (split && *split != NULL)
    {
        ft_printf("%s\n", *split);
        split++;
    }
	return (0);
}
