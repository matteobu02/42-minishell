/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:23:26 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/25 16:03:09 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

void	echo(int ac, char **av)
{
	int	i;
	int	flag;

	if (ac == 1)
		printf("\n");
	else
	{
		i = 0;
		if (av[1][0] == '-' && av[1][1] == 'n' && !av[1][2])
		{
			flag = 1;
			i = 1;
		}
		else
			flag = 0;
		while (++i < ac)
			printf("%s", av[i]);
		if (!flag)
			printf("\n");
	}
}
