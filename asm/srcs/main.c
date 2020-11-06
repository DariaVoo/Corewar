#include "../includes/asm.h"
#include "../../vm/libft/includes/libftprintf.h"

int		main(int ac, char **av)
{
//	We have one important question: how much champs we want to process. If only 1:

// "NEW LEAF, have you?"
    t_data  all_data;
    char    *saved_file;

    //if (!(all_data = (t_data*)malloc(sizeof(t_data))))
     //   ft_exit(MALLOC_ERR);
    if (ac == 1)
        ft_exit(USAGE);
    //all_data = 0;
    ft_init_structs(&all_data, 1000);
    
    ft_printf("START: %s\n", av[ac - 1]);

    all_data.read_fd = open(av[ac - 1], O_RDONLY); // Должен быть 3 или больше (на открытие файла, ага)
    ft_printf("%d\n", all_data.read_fd);
    

    // ОБРАБОТКА ОШИБОК ОТКРЫТИЯ (НОМЕР ФД И КОЛ-ВО СЧИТАННЫХ БАЙТ)
	if (all_data.read_fd < 3)
		ft_exit("Bad file read");

    ft_read_file(&all_data);
    ft_check_all_data(&all_data);
    saved_file = ft_saved_name(saved_file); // ДАЕМ ИМЯ НОВОМУ ФАЙЛУ
    
    // СОЗДАТЬ ФАЙЛ
    int fd;
    if ((fd = open(ft_cor_extension(av[ac - 1]), O_RDWR | O_CREAT, 0666)) == -1)
        return (-1);

    // ОБРАБОТАТЬ ОШИБКИ СОЗДАНИЯ (НОМЕР ФД)


    // ОТКРЫТЬ ФАЙЛ ДЛЯ ЗАПИСИ


    // ЗАПИСАТЬ В СОЗДАННЫЙ ФАЙЛ
    writing_to_file(&all_data, fd);

    // ОБРАБОТКА ФЛАГОВ
    if ((ac - 1) > 1)
        ft_check_flags(&av, ac - 1);


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
    ft_printf("FINISH\n");
	return (0);
}
