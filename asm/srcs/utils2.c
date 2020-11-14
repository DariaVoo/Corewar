/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:28:24 by pkingsbl          #+#    #+#             */
/*   Updated: 2020/11/14 22:33:37 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "libftprintf.h"

int		ft_skip(char *line, int id)
{
	while (line[id] == ' ' || line[id] == '\t')
		id++;
	return (id);
}

void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_close_fd(int a, int b, char *filename)
{
	close(a);
	close(b);
	ft_printf("Writing output program to %s\n", filename);
}
