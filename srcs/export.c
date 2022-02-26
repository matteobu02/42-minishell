/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:54:16 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/26 03:08:56 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	format_print(char *s)
{
	int	f;

	f = ft_strchr_up(s, '=');
	if (!f)
		f = ft_strlen(s) - 1;
	ft_putstr_fd("declare -x ", 1);
	write(1, s, f + 1);
	if (!ft_strchr_up(s, '='))
		ft_putchar_fd('\n', 1);
	else
	{
		write(1, "\"", 1);
		s = ft_strchr(s, '=');
		if (s++)
			write(1, s, ft_strlen(s));
		ft_putendl_fd("\"", 1);
	}
}

void	export_print(char **tab)
{
	char	*t;
	int		x;
	int		i;
	int		j;

	x = ft_matrixlen(tab);
	i = -1;
	while (++i < x)
	{
		j = i;
		while (++j < x)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				t = tab[i];
				tab[i] = tab[j];
				tab[j] = t;
			}
		}
	}
	i = -1;
	while (tab[++i])
		format_print(tab[i]);
}

int	check_arg(char *s, int *ptr)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '.' || s[i] == '{' || s[i] == '-' || s[i] == '}'
			|| s[i] == '$' || s[i] == '\'' || s[i] == ';' || s[i] == '&'
			|| s[i] == '\"' || s[i] == '|' || s[i] == '^' || s[i] == '~'
			|| s[i] == '*' || s[i] == '#' || s[i] == '@' || s[i] == '!'
			|| !ft_isascii(s[i]))
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(s, STDERR_FILENO);
			ft_putstr_fd("': ", STDERR_FILENO);
			ft_putendl_fd("not a valid identifier", STDERR_FILENO);
			*ptr = 1;
			return (1);
		}
	}
	return (0);
}

void	ft_export(int ac, char **av)
{
	int	i;
	int	status;

	status = 0;
	if (ac == 1)
		export_print(g_datas.envp);
	else
	{
		i = 0;
		status = 0;
		while (++i < ac)
		{
			if (check_arg(av[i], &status))
				continue ;
			add_to_env(av[i]);
		}
	}
	update_env();
	g_datas.last_command_status = status;
}
