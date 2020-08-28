/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:25 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/28 17:44:43 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

static void		swap_bit(char *byte)
{
	char	c;
	int		i;

	i = 0;
	while (i < 4 / 2)
	{
		c = byte[i];
		byte[i] = byte[3 - i];
		byte[3 - i] = c;
		i++;
	}
}

static t_header	init_header(int fd)
{
	t_header	champ;
	int len;

	if (read(fd, &champ.magic, 4) < 0)
		ft_exit("ERROR: READ MAGIC HEADER");
	swap_bit((char*)(&champ.magic));
	if (read(fd, champ.prog_name, PROG_NAME_LENGTH) < 0)
		ft_exit("ERROR: READ NAME");
	lseek(fd, 4, SEEK_CUR);
	if ((len = read(fd, &champ.prog_size, 4)) < 0)
		ft_exit("ERROR: READ CHAMP SIZE");
	swap_bit((char*)(&champ.prog_size));
	if ((len = read(fd, champ.comment, COMMENT_LENGTH)) < 0)
		ft_exit("ERROR: READ COMMENT");
	lseek(fd, 4, SEEK_CUR);
	return (champ);	
}

//TODO: implement this
t_champion	parse_champion(char *chmp_file_name)
{
	t_champion	champ;
	int			fd;

	fd = open(chmp_file_name, O_RDONLY);
	champ.header = init_header(fd);
	if ((champ.code = ft_memalloc(champ.header.prog_size + 8)) == NULL)
		ft_exit("ERROR: MALLOC");
	if ((read(fd, champ.code, champ.header.prog_size + 8)) < 0)
		ft_exit("ERROR: READ CODE");
	return (champ);
}

