/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:25 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/28 13:43:44 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

// static t_header	init_header(int fd)
// {
// 	t_header	champ;
// 	int len;
// 	// long int	q;

// 	if (read(fd, &champ.magic, 4) < 0)
// 		ft_exit("ERROR: READ MAGIC HEADER");
// 	if (read(fd, champ.prog_name, PROG_NAME_LENGTH) < 0)
// 		ft_exit("ERROR: READ NAME");
// 	lseek(fd, SEEK_CUR, 4);
// 	if ((len = read(fd, &champ.prog_size, 4)) < 0)
// 		ft_exit("ERROR: READ CHAMP SIZE");
// 	if ((len = read(fd, champ.comment, COMMENT_LENGTH)) < 0)
// 		ft_exit("ERROR: READ COMMENT");
// 	lseek(fd, SEEK_CUR, 4);
// 	return (champ);	
// }

//TODO: implement this
t_champion	parse_champion(char *chmp_file_name)
{
	t_champion	champ;
	int			fd;
	char		*str;

	fd = open(chmp_file_name, O_RDONLY);
	// champ.header = init_header(fd);
	// if ((champ.code = ft_memalloc((champ.header.prog_size + 1) * sizeof(char))) == NULL)
	// 	ft_exit("ERROR: MALLOC");
	// if ((read(fd, champ.code, champ.header.prog_size)) < 0)
	// 	ft_exit("ERROR: READ CODE");
	get_next_line(fd, &str);
	int i = 0;
	while (1)
	{
		ft_printf("%x\n", (char)str[i++]);
	}	
	close(fd);
	return (champ);
}

