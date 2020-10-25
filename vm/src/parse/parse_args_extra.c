#include "vm.h"

int8_t		get_number_of_players(char *champion_names[MAX_PLAYERS])
{
	uint8_t	i;

	i = 0;
	while (champion_names[i])
		i++;
	return (i);
}

int8_t		update_n_flag(const int8_t shift)
{
	static int8_t	n_positions = 0;

	if (n_positions & 1 << shift)
		return (-1);
	n_positions = n_positions | 1 << shift;
	return (n_positions);
}

uint8_t		is_n_flag(const char *argv_str)
{
	if (ft_strcmp(argv_str, FLAG_N) == 0)
		return (1);
	return (0);
}

uint8_t		is_dump_flag(const char *str)
{
	if (ft_strcmp(str, FLAG_DUMP) == 0)
		return (1);
	return (0);
}

void			init_champion_names(char *champion_names[MAX_PLAYERS])
{
	uint8_t		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		champion_names[i] = NULL;
		i++;
	}
}