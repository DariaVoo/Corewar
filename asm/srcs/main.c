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

	// TODO Заменить заглушку
//    ft_printf("FINISH\n");
    free_data(&all_data);
	return (0);
}
