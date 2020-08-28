/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:25 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/27 19:16:55 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

static t_header	init_header(int fd)
{
	t_header	champ;
	char		str[COMMENT_LENGTH + 1];
	int len;
	// long int	q;

	ft_bzero(str, COMMENT_LENGTH);
	if ((len = read(fd, str, 4)) < 0)
		ft_exit("ERROR: READ MAGIC HEADER");
	ft_printf("buf = %s %d\n", str, str[2]);
	champ.magic = ft_atoi(str);
	ft_bzero(str, COMMENT_LENGTH);
	if ((len = read(fd, str, PROG_NAME_LENGTH)) < 0)
		ft_exit("ERROR: READ NAME");
	ft_printf("buf = %s %d\n", str, len);
	ft_strcpy(champ.prog_name, str);
	ft_bzero(str, COMMENT_LENGTH);
	if ((read(fd, str, 1)) < 0)
		ft_exit("ERROR: READ CHAMP SIZE");
	champ.prog_size = ft_atoi(str);
	ft_printf("buf = %s %d\n", str, len);
	ft_bzero(str, COMMENT_LENGTH);
	if ((read(fd, str, COMMENT_LENGTH)) < 0)
		ft_exit("ERROR: READ COMMENT");
	ft_printf("buf = %s %d\n", str, len);
	ft_strcpy(champ.comment, str);
	return (champ);	
}

//TODO: implement this
t_champion	parse_champion(char *chmp_file_name)
{
	t_champion	champ;
	int			fd;

	fd = open(chmp_file_name, O_RDONLY);
	champ.header = init_header(fd);
	if ((champ.code = ft_memalloc((champ.header.prog_size + 1) * sizeof(char))) == NULL)
		ft_exit("ERROR: MALLOC");
	if ((read(fd, champ.code, champ.header.prog_size)) < 0)
		ft_exit("ERROR: READ CODE");
	close(fd);
	return (champ);
}

