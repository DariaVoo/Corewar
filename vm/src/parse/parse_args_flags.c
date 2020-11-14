/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:17:12 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/11/14 19:19:14 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static uint8_t	is_n_flag(const char *argv_str)
{
	if (ft_strcmp(argv_str, FLAG_N) == 0)
		return (1);
	return (0);
}

static uint8_t	is_dump_flag(const char *str)
{
	if (ft_strcmp(str, FLAG_DUMP) == 0)
		return (1);
	return (0);
}

/*
**    проверяем -dump флаг
**    проверяем, есть ли за -dump число
**
**    правильный пример:
**        ./corewar -dump 100 A.cor B.cor
**    неправильный пример:
**        ./corewar -dump -100 A.cor B.cor
**        ./corewar -dump
*/

uint8_t			parse_dump_flag(char *splited_argv[])
{
	if (is_dump_flag(splited_argv[0]))
	{
		if (splited_argv[1])
		{
			if (!ft_isnumber_int(splited_argv[1]) || splited_argv[1][0] == '-')
				exit_error(E_ARGV_DUMP_FLAG_NAN);
			update_dump_flag(ft_atoi(splited_argv[1]));
			return (1);
		}
		else
			exit_error(E_ARGV_DUMP_NOT_EXIST);
	}
	return (0);
}

/*
**    проверяем -n флаг
**    проверяем, есть ли за -n число
**    проверяем, указано ли имя файла (чемпиона) после числа
**
**    правильный пример:
**        ./corewar -n 2 A.cor -n 1 B.cor
**    неправильный пример:
**        ./corewar -n A.cor B.cor
**        ./corewar -n 2 A.cor B.cor -n 3
*/

uint8_t			parse_n_flag(char **splited_argv)
{
	uint8_t		possible_pos;

	possible_pos = 0;
	if (is_n_flag(splited_argv[0]))
	{
		if (splited_argv[1])
		{
			if (!ft_isnumber_int(splited_argv[1]) || splited_argv[1][0] == '-')
				exit_error(E_ARGV_N_FLAG_NAN);
			possible_pos = ft_atoi(splited_argv[1]);
			if (possible_pos < 1 || possible_pos > MAX_PLAYERS)
				exit_error(E_ARGV_N_FLAG_RANGE);
			if (update_n_flag(possible_pos - 1) == -1)
				exit_error(E_ARGV_N_FLAG_DUP);
			if (!splited_argv[2])
				exit_error(E_ARGV_N_FLAG_NO_CHAMP);
			return (possible_pos);
		}
		else
			exit_error(E_ARGV_N_FLAG_NOT_EXIST);
	}
	return (0);
}

/*
**	проверяем имя файла (чемпиона)
**	должно оканчиваться на ".cor"
*/

void			parse_champ_name(const char *argv_name, char *champ_name[])
{
	char		*substr;

	substr = ft_strstr(argv_name, DOTCOR);
	if (!substr || substr == argv_name || substr[DOTCOR_SIZE] != '\0')
		exit_error(E_ARGV_CHAMP_NAME);
	else
	{
		*champ_name = ft_strdup(argv_name);
		if (!*champ_name)
			exit_error(E_STRSUB);
	}
}
