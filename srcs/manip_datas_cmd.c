/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_datas_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:15:35 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/26 01:33:02 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cpy_maic_word(t_datas_cmd *cmd, int x, int status)
{
	int		y;
	int		k;
	char	**tmp;

	if (status)
		return (one_word(cmd, x));
	tmp = cmd->magic_word;
	k = ft_matrixlen(tmp);
	cmd->magic_word = malloc(sizeof(char *) * cmd->type_hd + 1);
	if (!cmd->magic_word)
		return (NULL);
	y = -1;
	while (++y < k)
	{
		cmd->magic_word[y] = cpy_with_malloc(tmp[y]);
		if (!cmd->magic_word[y])
			return (free_no_place(y, cmd->magic_word, tmp));
	}
	cmd->magic_word[y] = cpy_with_malloc(cmd->all_cmds[x + 1]);
	if (!cmd->magic_word[y])
		return (free_no_place(y, cmd->magic_word, tmp));
	cmd->magic_word[y + 1] = NULL;
	free(tmp);
	return (cmd->magic_word);
}

/****************************************
*
*	Nom : gen_datas_cmd
*	Params : - La ligne complete de commandes
*			 - La strcut de g_datas
*	Retour : La struct relative a toute la ligne de commande (datas_cmd)
*	Descritpion:
*		A parti de la chaine de char, la strcuture va stocker un split_up de la
*			chaine (separations par des espaces, des tabs et d'autes cas plus
*			specifiques), met en evidence le path pour pipex, lan la fct
*			trans_cmd qui va permettre de creer une strcut par commande, reprend
*			g_datas pour le repointer et init le nombre de commandes
*
****************************************/

void	in_env(t_var_env *tmp1)
{
	t_var_env	*tmp;

	tmp = ft_find_in_list(tmp1->name_var, g_datas.env_in_struct);
	if (tmp->var_txt)
		free(tmp->var_txt);
	tmp->var_txt = cpy_with_malloc(tmp1->var_txt);
	free(tmp1->var_txt);
	free(tmp1->name_var);
	free(tmp1);
	ft_clean_mat(g_datas.envp);
	g_datas.envp = conv_env_to_mat();
}

void	in_var(t_var_env *tmp1)
{
	t_var_env	*tmp;

	tmp = ft_find_in_list(tmp1->name_var, g_datas.out_struct);
	if (tmp->var_txt)
		free(tmp->var_txt);
	tmp->var_txt = cpy_with_malloc(tmp1->var_txt);
	free(tmp1->var_txt);
	free(tmp1->name_var);
	free(tmp1);
}

t_datas_cmd	*gen_datas_cmd1(char *x)
{
	t_datas_cmd	*cmd;

	cmd = malloc(sizeof(t_datas_cmd));
	if (!cmd)
		return (NULL);
	cmd->all_cmds = ft_split_up(x);
	search_hd(cmd);
	if (!cmd->all_cmds)
	{
		free(cmd);
		return (NULL);
	}
	if (check_map(cmd->all_cmds))
	{
		g_datas.last_command_status = 1;
		return (ft_free_no_place(cmd));
	}
	cmd->cmd_first = move_fd(trans_cmd(cmd->all_cmds, 0, cmd), 0, cmd);
	if (!cmd->cmd_first)
		return (ft_free_no_place(cmd));
	return (cmd);
}

t_datas_cmd	*gen_datas_cmd(char *x)
{
	t_datas_cmd	*cmd;
	char		*tmp;
	t_var_env	*tmp1;

	cmd = gen_datas_cmd1(x);
	if (!cmd)
		return (NULL);
	tmp = cmd->cmd_first->cmd;
	if (!cmd->cmd_first->next && (tmp && (ft_strchr_up(tmp, '=')
				&& (ft_strchr_up(tmp, '"') == 0
					|| ft_strchr_up(tmp, '"') > ft_strchr_up(tmp, '=')))))
	{
		g_datas.last_command_status = 0;
		tmp1 = ft_new_var_env(cmd->cmd_first->cmd, g_datas.out_struct);
		if (ft_find_in_list(tmp1->name_var, g_datas.env_in_struct))
			in_env(tmp1);
		else if (ft_find_in_list(tmp1->name_var, g_datas.out_struct))
			in_var(tmp1);
		else
			g_datas.out_struct = tmp1;
		ft_free_datas_cmd(cmd);
		return (NULL);
	}
	cmd->nb_cmds = ft_lstsize(cmd->cmd_first);
	return (cmd);
}
