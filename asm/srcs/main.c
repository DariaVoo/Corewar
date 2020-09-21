#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"

int		main(int ac, char **av)
{
//	We have one important question: how much champs we want to process. If only 1:
    char	**split;
    int i;
    t_header 	*header;
    t_body		*body;

    i = 0;
    split = NULL;
    /*
     ** Без маллока все падает
     */
    header = malloc(sizeof(header));
    body = malloc(sizeof(body));

    ft_check_header_file();
    ft_check_args(av, ac);
    split = ft_file_read(split, av[ac - 1]);

    while (*split != NULL)
    {
        ft_printf("%s\n", *split);
        split++;
    }

	ft_init_structs(header, body);
	i = ft_parse_header(split, i);
	ft_parse_body(split, i);
	// ft_create_body

	return (0);
}
