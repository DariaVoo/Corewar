/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/31 21:20:46 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

void		ft_exit(char *str)
{
	ft_putstr(str);
	exit (EXIT_FAILURE);
}

void	champ_print(t_champion *ptr)
{
	unsigned int i;

	i = 0;
	ft_printf("Magic header: %x\nNAME: %s\nProg size: %x\nComment: %s\nCode:\n", ptr->header.magic, ptr->header.prog_name, ptr->header.prog_size, ptr->header.comment);
	while (i < ptr->header.prog_size)
	{
		ft_printf("%.2x", (0xff & ptr->code[i]));
		if (i % 2 != 0)
			ft_putstr(" ");
		if ((i + 1) % 16 == 0 && i != 0)
			ft_putstr("\n");
		i++;
	}
}

t_champion	*valid_champions(char **chmp_file_name, size_t col_champs)
{
	t_champion	*champs;
	t_champion	*head;

	head = parse_champion(chmp_file_name[col_champs], init_champ(col_champs));
	champs = head;
	while (--col_champs > 0)
	{
		champs->next = parse_champion(chmp_file_name[col_champs], init_champ(col_champs));
	}
}

int main(int argc, char **argv)
{
	t_champion	*champ;
	t_vm		*vm;
	size_t		col_champs = (size_t)argc - 1;
	
	ft_printf("HI!!! \n");
	vm = init_vm(col_champs);
	while (col_champs--)
	{
		champ = init_champ(1);
	}
	champ = parse_champion(argv[1], champ);
	vm->champs = champ;
	champ_print(vm->champs);
	return (0);
}
