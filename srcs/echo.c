/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:23:26 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/23 16:38:28 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	while (str[++i] && str[i] == 'n')
		;
	if (!str[i])
		return (1);
	else
		return (0);
}

void	echo(int ac, char **av)
{
	int	i;
	int	flag;

	if (ac == 1)
		ft_putchar_fd('\n', 1);
	else
	{
		i = 0;
		flag = 0;
		while (++i < ac && get_flag(av[i]))
			flag = 1;
		i--;
		while (++i < ac)
		{
			ft_putstr_fd(av[i], 1);
			if (i < ac - 1)
				ft_putchar_fd(32, 1);
		}
		if (!flag)
			ft_putchar_fd('\n', 1);
	}
	g_datas.last_command_status = 0;
}
