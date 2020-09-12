//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

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
