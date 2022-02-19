/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_one_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:35:02 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:35:05 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void search_hd(t_one_cmd *cmd)
{
	int x;

	x = 0;
	cmd->type_hd = 0;
	cmd->magic_word = NULL;
	while (1)
	{
		x = find_next_char(&cmd->all_cmd[x], '<');
		if (x < ft_matrixlen(&cmd->all_cmd[x]) + 1 && ft_strlen(cmd->all_cmd[x]) == 2)
		{
			if (cmd->all_cmd[x][1] == '<')
			{
				cmd->type_hd = 1;
				cmd->magic_word = cpy_with_malloc(cmd->all_cmd[x + 1]);
				if (!cmd->magic_word)
				{
					ft_free_one_cmd(cmd, 0);
					cmd = NULL;
					return ;
				}
				break;
			}
		}
		else
			break;
	}
}

/****************************************
*
*	Nom : trans_cmd
*	Params : - La matrice de toute la ligne de commandes
* 			 - La matrice d'env
*			 - la liste chainee de variables d'environnement defini par le user
*			 - Le status de la fonction (si premier de la liste chainee = 0
*					else = 1)
*	Retour : La premiere structure de la liste chainee de one_cmd
*	Descritpion:
*		Commence par cree la matrice reprenant tous les elements de la commande
*			(jusqu'au pipe), init infile et outfile, met en avant la cmd unique
*			et defini le type du pointeru vers la prochaine commande (0 = pas de
*			commandes apres, 1 = une commande apres, 2 = une commande apres mais
*			celle-ci est la premiere) ensuite il lance relance la fonction avec
*			la commande suivante (si il y en a une)
*
****************************************/

t_one_cmd	*trans_cmd(char **cmds, t_datas_prompt *datas_prompt, int st, t_one_cmd *old_one)
{
	int			x;
	t_one_cmd	*cmd;
	t_one_cmd	*tmp;
	char 		**envp;
	t_var_env 	*out_struct;

	envp = datas_prompt->envp;
	out_struct = datas_prompt->out_struct;
	cmds = pipen_t(cmds);
	cmd = malloc(sizeof(t_one_cmd));
	if (!cmd)
		return(NULL);
	cmd->all_cmd = ft_matrixlcpy(cmds, find_next_char(cmds, '|'));
	if (!cmd->all_cmd)
		free(cmd);
	cmd->all_cmd = modif_mat(cmd->all_cmd, envp, out_struct);
	if (!cmd->all_cmd)
		free(cmd);
	if (old_one && infile(cmd->all_cmd) == 0)
		cmd->infile = old_one->infile;
	else
		cmd->infile = infile(cmd->all_cmd);
	if (old_one && outfile(cmd->all_cmd) == 1)
		cmd->outfile = old_one->outfile;
	else
		cmd->outfile = outfile(cmd->all_cmd);
	if (cmd->outfile == -1 || cmd->infile == -1)
	{
		ft_free_one_cmd(cmd, 0);
		return (NULL);
	}
	search_hd(cmd);
	if (cmd == NULL)
		return (NULL);
	//on s'est arrete la
	if (cmd->type_hd || ((cmd->infile != 0 || cmd->outfile != 1) && (find_next_char(cmd->all_cmd, '<') < find_next_char(cmds, '|') || find_next_char(cmd->all_cmd, '>') < find_next_char(cmds, '|'))))
	{
		cmd->all_cmd = simple_mat(cmd->all_cmd);
		if (!cmd->all_cmd)
		{
			ft_free_one_cmd(cmd, 0);
			return (NULL);
		}
	}
	x = find_next_char(cmds, '|');
	if (!ft_matrixlen(cmd->all_cmd) && 	x != ft_matrixlen(cmds))
	{
		tmp = trans_cmd(&(cmds[x + 1]), datas_prompt, 0, cmd);
		ft_free_one_cmd(cmd, 1);
		cmd = tmp;
	}
	else
	{
		cmd->cmd = cmd->all_cmd[0];
		cmd->type_next = 0;
		cmd->next = NULL;
		if (x != ft_matrixlen(cmds))
		{
			cmd->type_next = 2;
			if (st)
				cmd->type_next = 1;
			cmd->next = trans_cmd(&(cmds[x + 1]), datas_prompt, 1, NULL);
		}
	}
	return (cmd);
}
