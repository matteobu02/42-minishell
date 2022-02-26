/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:11:32 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:11:34 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : ft_new_free
*	Params : Pointeur vers la structure de donnees relatives au var d'env
*	Retour : void
*	Descritpion:
*		Free l'ensemble de la liste chainee stockant les donnees des var d'env
*
****************************************/

void	ft_new_free(t_var_env *input)
{
	t_var_env	*tmp;

	while (input->next)
	{
		tmp = input;
		if (tmp->var_txt)
			free(tmp->var_txt);
		if (tmp->name_var)
			free(tmp->name_var);
		input = tmp->next;
		if (tmp)
			free(tmp);
	}
	if (input->var_txt)
		free(input->var_txt);
	if (input->name_var)
		free(input->name_var);
	if (input)
		free(input);
}

/****************************************
*
*	Nom : ft_free_one_cmd
*	Params : Pointeur vers la premiere struct de la liste chainee
*	Retour : Void
*	Descritpion:
*		Toutes les donnees malloc de la struct seront free avant de passer a
*			la struct suivante la liste chainee
*
****************************************/

void	*ft_free_one_cmd(t_one_cmd *first_cmd, int status)
{
	int	x;

	x = ft_matrixlen(first_cmd->all_cmd);
	while (--x >= 0)
		if (first_cmd->all_cmd[x])
			free(first_cmd->all_cmd[x]);
	if (first_cmd->all_cmd)
		free(first_cmd->all_cmd);
	if (first_cmd->infile > 0 && !status)
		close(first_cmd->infile);
	if (first_cmd->outfile > 1 && !status)
		close(first_cmd->outfile);
	if (first_cmd->next && !status)
		ft_free_one_cmd(first_cmd->next, 0);
	if (first_cmd)
		free(first_cmd);
	return (NULL);
}

/****************************************
*
*	Nom : ft_free_datas_cmd
*	Params : Pointeur la struct reprenant les donnees de la ligne de commandes
*	Retour : Void
*	Descritpion:
*		Toutes les donnees malloc de la struct seront free
*
****************************************/

void	*ft_free_datas_cmd(t_datas_cmd *datas_cmd)
{
	int	x;

	if (datas_cmd->all_cmds)
	{
		x = ft_matrixlen(datas_cmd->all_cmds);
		while (--x >= 0)
			free(datas_cmd->all_cmds[x]);
		free(datas_cmd->all_cmds);
	}
	if (datas_cmd->magic_word)
	{
		x = datas_cmd->type_hd;
		while (--x >= 0)
			free(datas_cmd->magic_word[x]);
		free(datas_cmd->magic_word);
	}
	if (datas_cmd->cmd_first)
		ft_free_one_cmd(datas_cmd->cmd_first, 0);
	if (datas_cmd)
		free(datas_cmd);
	return (NULL);
}

/****************************************
*
*	Nom : ft_free_little_matrice
*	Params : - Matrice de 3 liste de char
*			 - L'index qui ne doit pas etre free
*	Retour : Void
*	Descritpion:
*		Free les trois index de la matrice sauf si le nombre donne est compris
*			entre 0 et 2, dans ce cas l'index egal au nombre ne sera pas free
*
****************************************/

char	*ft_free_little_matrice(char **mat, int x)
{
	int	y;

	y = -1;
	while (++y < 3)
		if (y != x)
			free(mat[y]);
	return (NULL);
}

t_datas_cmd	*ft_free_no_place(t_datas_cmd *cmd)
{
	ft_clean_mat(cmd->all_cmds);
	free(cmd);
	return (NULL);
}
