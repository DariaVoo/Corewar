/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:45:08 by cnails            #+#    #+#             */
/*   Updated: 2020/09/25 19:57:03 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGS_H
# define PARSE_ARGS_H

/*
** NORMITE YS EBAL TEBYA V ROT SUKA
*/

# define DOTCOR ".cor"
# define DOTCOR_SIZE sizeof(DOTCOR) - 1
# define FLAG_N "-n"
# define FLAG_DUMP "-dump"

# define DP "-dump "
# define E_ARGV_DUMP_FLAG_NAN DP "[not an INT number or number is negative]"
# define E_ARGV_DUMP_NOT_EXIST "-dump [number doesn't exist]"

# define E_ARGV_N_FLAG_DUP "-n [duplicated number]"
# define E_ARGV_N_FLAG_NO_CHAMP "-n [num] [no champion name]"
# define E_ARGV_N_FLAG_NAN "-n [not an INT_SIZE number or number is negative]"
# define E_ARGV_N_FLAG_NOT_EXIST "-n [number doesn't exist]"
# define E_ARGV_N_FLAG_RANGE "-n [number is out of range (1 - 4)]"

# define E_ARGV_BAD_ORDER "[bad order of players, it must be (n, n + 1,..., 4)]"
# define E_ARGV_NO_PLAYERS "[no players]"
# define E_ARGV_CHAMP_NAME "[wrong champion name]"
# define PL_LIM "[players limit exceeded "
# define E_ARGV_LIMIT_PLAYERS PL_LIM "or a lot of data transferred]"

#endif
