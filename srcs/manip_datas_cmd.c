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
	if (!cmd->all_cmds)
		return (NULL);
	cmd->full_path = find_in_env(datas_prompt->envp, "PATH=", 5, 5);
	if (!cmd->full_path)
	{
		ft_free_datas_cmd(cmd);
		return (NULL);
	}
	cmd->cmd_first = trans_cmd(cmd->all_cmds, datas_prompt, 0, NULL);
	if (!cmd->cmd_first)
	{
		ft_free_datas_cmd(cmd);
		return (NULL);
	}
	cmd->datas_prompt = datas_prompt;
	cmd->nb_cmds = ft_lstsize(cmd->cmd_first);
	return (cmd);
}
