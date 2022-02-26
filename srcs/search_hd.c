/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_hd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:04:02 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/25 10:04:05 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	search_hd(t_datas_cmd *cmd)
{
	int		x;

	x = find_next_char(cmd->all_cmds, '<');
	cmd->type_hd = 0;
	cmd->magic_word = NULL;
	while (x < ft_matrixlen(cmd->all_cmds))
	{
		if (ft_matrixlen(&cmd->all_cmds[x]) >= 2
			&& ft_strlen(cmd->all_cmds[x]) == 2)
		{
			if (cmd->all_cmds[x][1] == '<')
			{
				cmd->type_hd++;
				if (cmd->magic_word)
					cmd->magic_word = ft_cpy_maic_word(cmd, x, 0);
				else
					ft_cpy_maic_word(cmd, x, 1);
				if (!cmd->magic_word)
					return ;
			}
		}
		x += find_next_char(&cmd->all_cmds[x + 1], '<') + 1;
	}
}
