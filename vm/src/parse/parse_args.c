#include "vm.h"

/*
	возвращает начальное количество игроков
*/

uint8_t		get_number_of_players()
{
	uint8_t	i;
	int8_t	n;

	i = 0;
	n = update_n_flag(-1);
	while (n)
	{
		n = n & (n - 1);
		i++;
	}
	return (i);
}

int32_t		update_dump_flag(const int32_t dump_flag)
{
	static int32_t	dump = -1;

	if (dump_flag > -1)
		dump = dump_flag;
	return (dump);
}

int8_t		update_n_flag(const int8_t shift)
{
	static int8_t	n_positions = 0;

	if (n_positions & 1 << shift)
		return (-1);
	n_positions = n_positions | 1 << shift;
	return (n_positions);
}

static void	check_missed_pos_order()
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

static void	merge_champ_names(char **champ_names, char **unranking_champ_names)
{
	uint8_t	i;
	uint8_t	n;

	i = 0;
	n = 0;
	while(i < MAX_PLAYERS)
	{
		if (!champ_names[i])
		{
			while (n < MAX_PLAYERS)
			{
				if (unranking_champ_names[n])
				{
					champ_names[i] = unranking_champ_names[n];
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

void		parse_args(char *champ_names[], char **argv)
{
	char	*unranking_champ_names[MAX_PLAYERS + 1];
	char	**splited_argv;
	size_t	i;
	uint8_t	n;
	uint8_t	limit;
	uint8_t	possible_pos;

	i = 0;
	n = 0;
	limit = 0;
	init_arrptr((void *)unranking_champ_names, MAX_PLAYERS + 1);
	if (argv[1])
		splited_argv = argv;
	else
	{
		splited_argv = ft_strsplit(argv[0], ' ');
		if (!splited_argv || !splited_argv[0])
			exit_error(E_SSPLIT);
	}
	if (parse_dump_flag(splited_argv))
		i = 2;
	while (splited_argv[i])
	{
		if (limit > MAX_PLAYERS - 1)
			exit_error(E_ARGV_LIMIT_PLAYERS);
		possible_pos = 0;
		if ((possible_pos = parse_n_flag(splited_argv + i)))
		{
			i = i + 2;
			parse_champ_name(splited_argv[i], &champ_names[possible_pos - 1]);
		}
		else
		{
			parse_champ_name(splited_argv[i], &unranking_champ_names[n]);
			n++;
		}
		i++;
		limit++;
	}
	merge_champ_names(champ_names, unranking_champ_names);
	check_missed_pos_order();
	if (splited_argv != argv)
		ft_arrdel((void ***)&splited_argv);
}
