/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/27 18:39:23 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

void		ft_exit(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

void	champ_print(t_champion ptr)
{
	ft_printf("Magic header: %x\nNAME: %s\nProg size: %d\nComment: %s\nCode: %s\n", ptr.header.magic, ptr.header.prog_name, ptr.header.prog_size, ptr.header.comment, ptr.code);
}

int main(int argc, char **argv)
{
	t_champion	champ;

	argc++;
	ft_printf("HI!!! \n");
	champ = parse_champion(argv[1]);
	champ_print(champ);
	return (0);
}
