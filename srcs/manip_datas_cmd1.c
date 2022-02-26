/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_datas_cmd1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:03:46 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/25 10:03:48 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	er(char *str, int error, int status)
{
	if (status)
	{
		ft_putstr_fd("Minishell: ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		g_datas.last_command_status = error;
		return (1);
	}
	ft_putstr_fd(str, 1);
	g_datas.last_command_status = error;
	return (1);
}

int	search_forget(char *map, char forget)
{
	int	x;
	int	count;

	x = -1;
	count = 0;
	while (++x < (int)ft_strlen(map))
		if (map[x] == forget)
			count++;
	if (map[x - 1] != forget)
		return (1);
	return (count);
}

int	check_map2(char **map)
{
	int	x;
	int	y;
	int	count_simple;
	int	count_double;

	x = -1;
	while (++x < ft_matrixlen(map))
	{
		y = -1;
		count_simple = 0;
		count_double = 0;
		while (++y < (int)ft_strlen(map[x]))
		{
			if (map[x][y] == '"' && !(count_simple % 2))
					count_double++;
			if (map[x][y] == 39 && !(count_double % 2))
					count_simple++;
		}
		if (count_simple % 2 || count_double % 2)
			return (er("Minishell: error at the end of command\n", 1, 0));
	}
	return (0);
}

int	check_map(char **map)
{
	int	x;

	x = ft_matrixlen(map) - 1;
	if ((map[x][0] == '<') || (map[x][0] == '>'))
		return (er("Minishell: syntax error near unexpected token `newline'\n" \
			, 258, 0));
	else if (map[x][0] == '|')
		return (er("Minishell: error at the end of command\n", 1, 0));
	else if (infile(map) < 0 || outfile(map) < 0)
		return (er(map[find_next_char(map, '<') + 1], 1, 1));
	return (check_map2(map));
}

char	**one_word(t_datas_cmd *cmd, int x)
{
	cmd->magic_word = malloc(sizeof(char *));
	if (!cmd->magic_word)
		return (NULL);
	cmd->magic_word[0] = cpy_with_malloc(cmd->all_cmds[x + 1]);
	if (!cmd->magic_word[0])
	{
		free(cmd->magic_word);
		return (NULL);
	}
	cmd->magic_word[1] = NULL;
	return (cmd->magic_word);
}
