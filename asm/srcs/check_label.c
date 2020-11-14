/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:34:54 by pkingsbl          #+#    #+#             */
/*   Updated: 2020/11/14 19:28:24 by pkingsbl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_label(char *label)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (label[i] && (label[i] != LABEL_CHAR))
	{
		j = 0;
		while (LABEL_CHARS[j] != '\0' && LABEL_CHARS[j] != label[i])
			j++;
		if (LABEL_CHARS[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
