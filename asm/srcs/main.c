#include "../includes/asm.h"
#include "../../vm/libft/includes/libftprintf.h"

int		main(int ac, char **av)
{
//	We have one important question: how much champs we want to process. If only 1:

// "NEW LEAF, have you?"
    t_data  all_data;

    if (ac == 1)
        ft_exit(USAGE);

	ft_check_filename(av[ac - 1]); //проверка имени файла (заканчивается на .s)
	if ((all_data.read_fd = open(av[ac - 1], O_RDONLY)) < 3)
	{
		close(all_data.read_fd);
		ft_exit("Bad file read\n");
	}
	if (read(all_data.read_fd, NULL, 0) < 0)
	{
		close(all_data.read_fd);
		ft_exit("Bad file read\n");
	}  
    ft_init_structs(&all_data, get_number_of_lines(&all_data));
	ft_read_file(&all_data);
    // СОЗДАТЬ ФАЙЛ
    int fd;
    if ((fd = open(ft_cor_extension(av[ac - 1]), O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
        return (-1);

    // ОБРАБОТАТЬ ОШИБКИ СОЗДАНИЯ (НОМЕР ФД)


    // ОТКРЫТЬ ФАЙЛ ДЛЯ ЗАПИСИ


    // ЗАПИСАТЬ В СОЗДАННЫЙ ФАЙЛ
    writing_to_file(&all_data, fd);

    ft_close_fd(all_data.read_fd, all_data.write_fd);




    // char	**split;
    // int i;
    // t_header 	header;
    // t_body		body;

    // i = 0;
    // split = NULL;

    // ft_check_header_file();
    // ft_check_args(av, ac);
    // split = ft_file_read(split, av[ac - 1]);
    // split = file_comment_trim сделать сплит по COMMENT_CHAR и ALT_COMMENT_CHAR

//    while (*split != NULL)
//    {
//        ft_printf("%s\n", *split);
//        split++;
//    }

	// i = ft_parse_header(split, &header);
	// ft_printf("line_number == %d | header.prog_size == %d | header.prog_name == %s\n", i, header.prog_size, header.prog_name);


	// TODO Заменить заглушку
	// ft_parse_body(split, i, 1000);
	// ft_create_body
//    ft_printf("FINISH\n");
    free_data(&all_data);
	return (0);
}
