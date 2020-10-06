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
    // split = file_comment_trim сделать сплит по COMMENT_CHAR и ALT_COMMENT_CHAR

//    while (*split != NULL)
//    {
//        ft_printf("%s\n", *split);
//        split++;
//    }

	ft_init_structs(&header, &body);
	i = ft_parse_header(split, &header);
	ft_printf("line_number == %d | header.prog_size == %d | header.prog_name == %s\n", i, header.prog_size, header.prog_name);


	// TODO Заменить заглушку
	ft_parse_body(split, i, 1000);
	// ft_create_body

	return (0);
}
