/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:37:12 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 19:30:47 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

static void		check_champ_file(t_header head, const char *filename)
{
	if (head.magic != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Error: File %s has an invalid header\n", filename);
		exit(1);
	}
	if (head.prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large ", filename);
		ft_printf("a code (%d bytes > 682 bytes)\n", head.prog_size);
		exit(1);
	}
}

static t_header	init_champ_header(int fd)
{
	t_header	champ;

	if (read(fd, &champ.magic, INT_SIZE) < 0)
		exit_error(E_PAR_MAGIC_HEADER);
	swap_bit((char*)(&champ.magic));
	if (read(fd, champ.prog_name, PROG_NAME_LENGTH) < 0)
		exit_error(E_PAR_NAME);
	lseek(fd, INT_SIZE, SEEK_CUR);
	if (read(fd, &champ.prog_size, INT_SIZE) < 0)
		exit_error(E_PAR_CHAMP_SIZE);
	swap_bit((char*)(&champ.prog_size));
	if (read(fd, champ.comment, COMMENT_LENGTH) < 0)
		exit_error(E_PAR_COMMENT);
	lseek(fd, INT_SIZE, SEEK_CUR);
	return (champ);
}

t_champion		*parse_champ_file(const char *champ_name, uint8_t id)
{
	t_champion	*champ;
	int			ret;
	int			fd;

	fd = open(champ_name, O_RDONLY);
	if (fd < 0)
	{
		perror(champ_name);
		exit(NOE_FD);
	}
	champ = create_champ(id);
	champ->header = init_champ_header(fd);
	check_champ_file(champ->header, champ_name);
	champ->code = ft_memalloc(champ->header.prog_size + 1);
	if (!champ->code)
		exit_error(E_MALLOC);
	ret = read(fd, champ->code, champ->header.prog_size + 1);
	if (ret < 0)
		exit_error(E_READ);
	close(fd);
	return (champ);
}

void			parse_files(t_champion *champ[], char *champ_names[])
{
	uint8_t	i;

	i = 0;
	while (champ_names[i])
	{
		champ[i] = parse_champ_file(champ_names[i], i + 1);
		i++;
	}
}
