/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:15 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:57:18 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_next_char(char **all_cmds, char c)
{
	int	x;

	x = -1;
	while (++x < ft_matrixlen(all_cmds))
		if (all_cmds[x][0] == c)
			break ;
	return (x);
}
