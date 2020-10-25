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

#ifndef PARSE_N_H
# define PARSE_N_H

# define DOTCOR ".cor"
# define DOTCOR_SIZE sizeof(DOTCOR) - 1
# define FLAG_N "-n"
# define FLAG_DUMP "-dump"

# define E_ARGV_DUMP_FLAG_NAN "-dump [not a number, or number is negative]"
# define E_ARGV_DUMP_NOT_EXIST "-dump [number doesn't exist]"

# define E_ARGV_N_FLAG_DUP "-n [duplicated number]"
# define E_ARGV_N_FLAG_NO_CHAMP "-n [num] [no champion name]"
# define E_ARGV_N_FLAG_NAN "-n [not a number, or number is gegative]"
# define E_ARGV_N_FLAG_NOT_EXIST "-n [number doesn't exist]"
# define E_ARGV_N_FLAG_RANGE "-n [number is out of range (1 - 4)]"

# define E_ARGV_BAD_ORDER "[bad order of players, it must be (n, n + 1, ... , 4)]"
# define E_ARGV_NO_PLAYERS "[no players]"
# define E_ARGV_CHAMP_NAME "[wrong champion name]"
# define E_ARGV_LIMIT_PLAYERS "[players limit exceeded or a lot of data transferred]"

#endif
