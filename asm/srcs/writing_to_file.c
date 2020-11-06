/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:10:17 by pkingsbl          #+#    #+#             */
/*   Updated: 2020/11/04 20:10:22 by pkingsbl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "../libft/includes/libftprintf.h"

void	write_hex_fd(long nbr, int fd)
{
	if (nbr >= 256)
	{
		write_hex_fd(nbr / 256, fd);
		write_hex_fd(nbr % 256, fd);
	}
	else
		ft_putchar_fd(nbr, fd);
}

void	write_magic_fd(long nb, int fd)
{
	int		count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 256;
		count++;
	}
	while (4 - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	write_hex_fd(COREWAR_EXEC_MAGIC, fd);
}

void	write_size_fd(long nb, int fd)
{
	int		count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 256;
		count++;
	}
	while (8 - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	write_hex_fd(CHAMP_MAX_SIZE, fd);
}

int 	writing_header_to_file(char *str, int size, int fd)
{
	int		i;

	i = 0;
	while (str[i] != '\0') {
		ft_putchar_fd(str[i], fd);
		i++;
	}
	while (i < size)
	{
		ft_putchar_fd(0x0, fd);
		i++;
	}
	return (0);
}

int 	writing_to_file(t_data *data, int fd)
{
	write_magic_fd(COREWAR_EXEC_MAGIC, fd);
	writing_header_to_file(data->header->prog_name, PROG_NAME_LENGTH + 1, fd);
	// write_size_fd(CHAMP_MAX_SIZE, fd); тут исправить на текущий размер
	writing_header_to_file(data->header->comment, COMMENT_LENGTH + 1, fd);
	//CHAMP_MAX_SIZE
	return (0);
}
