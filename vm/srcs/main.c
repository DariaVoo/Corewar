/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/01 12:48:28 by dima             ###   ########.fr       */
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
	ft_putstr("\n");
}

//valid champions at order
t_champion	*valid_champions(char **chmp_file_name, size_t col_champs)
{
	t_champion	*champs;
	t_champion	*head;

	head = parse_champion(chmp_file_name[col_champs], init_champ(col_champs));
	champs = head;
	while (--col_champs > 0)
	{
		champs->next = parse_champion(chmp_file_name[col_champs],\
													init_champ(col_champs));
		champs = champs->next;
	}
	return (head);
}


int main(int argc, char **argv)
{
	t_champion	*champ;
	t_vm		*vm;
	size_t		col_champs = (size_t)argc - 1;
	
	vm = init_vm(col_champs);
	champ = valid_champions(argv, col_champs);
	ft_printf("HI!!! \n");
	vm->champs = champ;
	init_arena(vm);
	ft_printf("%x", vm->arena);
	return (0);
}
