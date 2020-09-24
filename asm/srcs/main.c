#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

int		main(int ac, char **av)
{
//	We have one important question: how much champs we want to process. If only 1:
    char	**split;
    int i;
    t_header 	header;
    t_body		body;

    i = 0;
    split = NULL;

    ft_check_header_file();
    ft_check_args(av, ac);
    split = ft_file_read(split, av[ac - 1]);

//    while (*split != NULL)
//    {
//        ft_printf("%s\n", *split);
//        split++;
//    }

	ft_init_structs(&header, &body);
	i = ft_parse_header(split, i, &header);
	ft_printf("%d - %s\n", header.prog_size, header.prog_name);

	// TODO Заменить заглушку
	ft_parse_body(split, i, 1000);
	// ft_create_body

	return (0);
}
