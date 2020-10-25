#include "vm.h"

void		check_missed_pos_order(char *champion_names[MAX_PLAYERS])
{
	uint8_t	i;
	int8_t	n;

	i = MAX_PLAYERS - 1;
	n = update_n_flag(-1);
	if (!n)
		exit_error(E_ARGV_NO_PLAYERS);
	while (i)
	{
		if ((n & 1 << i) && !(n & 1 << (i - 1)))
			exit_error(E_ARGV_BAD_ORDER);
		i--;
	}
}

void		merge_champion_names(char *champion_names[MAX_PLAYERS],
									char *unranking_champion_names[MAX_PLAYERS])
{
	uint8_t	i;
	uint8_t	n;

	i = 0;
	n = 0;
	while(i < MAX_PLAYERS)
	{
		if (!champion_names[i])
		{
			while (n < MAX_PLAYERS)
			{
				if (unranking_champion_names[n])
				{
					champion_names[i] = unranking_champion_names[n];
					update_n_flag(i);
					n++;
					break ;
				}
				n++;
			}
		}
		i++;
	}
}

/*
	аргументы могут придти двумя способами:
	./corewar -dump nbr_cycles -n number champion1.cor
	./corewar "-dump nbr_cycles -n number champion1.cor"
	прочие скобочные хуйни идут нахуй, например
	./corewar "-dump n" "-n number" "champion1.cor" идет нахуй

	проверяем каким способом пришли аргументы
	проверяем флаг -dump (если существует, должен находиться первым аргументом)
	проверяем флаг -n
	проверяем игрока (должно быть 'расширение' .cor)
*/

void		parse_args(t_vm *vm, char *champion_names[MAX_PLAYERS], char **argv)
{
	char	*unranking_champion_names[MAX_PLAYERS];
	char	**splited_argv;
	size_t	i;
	uint8_t	n;
	uint8_t	limit;
	uint8_t	possible_pos;

	i = 0;
	n = 0;
	limit = 0;
	init_champion_names(unranking_champion_names);
	if (argv[1])
		splited_argv = argv;
	else
	{
		splited_argv = ft_strsplit(argv[0], ' ');
		if (!splited_argv || !splited_argv[0])
			exit_error(E_SSPLIT);
	}
	if (parse_dump_flag(vm, splited_argv))
		i = 2;
	while (splited_argv[i])
	{
		if (limit > MAX_PLAYERS - 1)
			exit_error(E_ARGV_LIMIT_PLAYERS);
		possible_pos = 0;
		if ((possible_pos = parse_n_flag(splited_argv + i)))
		{
			i = i + 2;
			parse_champion_name(splited_argv[i], \
			&champion_names[possible_pos - 1]);
		}
		else
		{
			parse_champion_name(splited_argv[i], \
			&unranking_champion_names[n]);
			n++;
		}
		i++;
		limit++;
	}
	merge_champion_names(champion_names, unranking_champion_names);
	check_missed_pos_order(champion_names);
	if (splited_argv != argv)
		ft_arrdel((void ***)&splited_argv);
}
