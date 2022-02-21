/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_datas_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:15:35 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:15:38 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_map(char **map)
{
	int x;
	int y;

	x = ft_matrixlen(map) - 1;
	if ((map[x][0] == '<') || (map[x][0] == '>'))
	{
		ft_putstr_fd("Minishell: syntax error near unexpected token `newline'\n", 1);
		datas_prompt.last_command_status = 258;
		return (1);
	}
	else if ((map[x][0] == '|') || (map[x][0] == '"' && map[x][ft_strlen(map[x]) - 1] != '"') || (map[x][0] == '\'' && map[x][ft_strlen(map[x]) - 1] != '\''))
	{
		ft_putstr_fd("Minishell: error at the end of command\n", 1);
		datas_prompt.last_command_status = 1;
		return (1);
	}
	else if (infile(map) < 0)
	{
		ft_putstr_fd("Minishell: ", 1);
		ft_putstr_fd(map[find_next_char(map, '<') + 1], 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		datas_prompt.last_command_status = 1;
		return (1);
	}
	else if (outfile(map) < 0)
		return (1);
	else
	{
		x = -1;
		while (++x < ft_matrixlen(map))
		{
			y = -1;
			while (++y < (int)ft_strlen(map[x]))
			{
				if (map[x][y] == '!' && ft_strlen(map[x]) == 2 && map[x][1] == '!')
				{
					if (!datas_prompt.old_command)
					{
						ft_putstr_fd("Minishell: !!: Event not found\n", 1);
						return (1);
					}
					return (0);
				}
			}
		}
	}
	return (0);
}

void search_hd(t_datas_cmd *cmd)
{
	int x;
	int y;
	int k;
	char **tmp;

	x = find_next_char(cmd->all_cmds, '<');
	cmd->type_hd = 0;
	cmd->magic_word = NULL;
	while (x < ft_matrixlen(cmd->all_cmds))
	{
		if (ft_matrixlen(&cmd->all_cmds[x]) >= 2 && ft_strlen(cmd->all_cmds[x]) == 2)
		{
			if (cmd->all_cmds[x][1] == '<')
			{
				cmd->type_hd++;
				if (cmd->magic_word)
				{
					tmp = cmd->magic_word;
					cmd->magic_word = malloc(sizeof(char *) * ft_matrixlen(tmp) + 2);
					y = -1;
					k = ft_matrixlen(tmp);
					while (++y < k)
					{
						cmd->magic_word[y] = cpy_with_malloc(tmp[y]);
						free(tmp[y]);
					}
					cmd->magic_word[y] = cpy_with_malloc(cmd->all_cmds[x + 1]);
					ft_putstr_fd("\n", 1);
					free(tmp);
				}
				else
				{
					cmd->magic_word = malloc(sizeof(char *) * 2);
					cmd->magic_word[0] = cpy_with_malloc(cmd->all_cmds[x + 1]);
					cmd->magic_word[1] = NULL;
				}
			}
		}
		x += find_next_char(&cmd->all_cmds[x + 1], '<') + 1;
	}
}

/****************************************
*
*	Nom : gen_datas_cmd
*	Params : - La ligne complete de commandes
*			 - La strcut de datas_prompt
*	Retour : La struct relative a toute la ligne de commande (datas_cmd)
*	Descritpion:
*		A parti de la chaine de char, la strcuture va stocker un split_up de la
*			chaine (separations par des espaces, des tabs et d'autes cas plus
*			specifiques), met en evidence le path pour pipex, lan la fct
*			trans_cmd qui va permettre de creer une strcut par commande, reprend
*			datas_prompt pour le repointer et init le nombre de commandes
*
****************************************/

t_datas_cmd	*gen_datas_cmd(char *x, t_datas_prompt *datas_prompt)
{
	t_datas_cmd	*cmd;

	cmd = malloc(sizeof(t_datas_cmd));
	if (!cmd)
		exit (0);
	cmd->all_cmds = ft_split_up(x);
	search_hd(cmd);
	if (!cmd->all_cmds)
	{
		free(cmd);
		return (NULL);
	}
	if (check_map(cmd->all_cmds))
	{
		//ft_free_all(cmd->all_cmds);
		free(cmd);
		return (NULL);
	}
	cmd->cmd_first = trans_cmd(cmd->all_cmds, cmd, 0, NULL);
	if (!cmd->cmd_first)
	{
		ft_free_datas_cmd(cmd);
		return (NULL);
	}
	cmd->datas_prompt = datas_prompt;
	cmd->nb_cmds = ft_lstsize(cmd->cmd_first);
	return (cmd);
}
