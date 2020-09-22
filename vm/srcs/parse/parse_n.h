/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:45:08 by cnails            #+#    #+#             */
/*   Updated: 2020/09/22 19:06:43 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_N_H
# define PARSE_N_H

typedef struct	s_arg
{
    int				index;
    char			*name;
    struct	s_arg	*next;
}				t_arg;

#endif
