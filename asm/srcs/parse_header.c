//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

int     ft_parse_header(char **split, int i, t_header *header)
{
//    header->prog_size = 800;
    while (*split != NULL)
    {
        while (*split[0] == '#')
            split++;
        if (ft_strstr(*split, ".name"))
            ft_memcpy(header->prog_name, *split, ft_strlen(*split));
//        ft_printf("%s\n", header->prog_name);
        split++;
        i++;
    }
    return (i);
}
