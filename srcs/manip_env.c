/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:43:32 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/25 18:00:15 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var_env	*ft_clean_no_place(t_var_env *out_struct)
{
	free(out_struct->name_var);
	free(out_struct);
	return (NULL);
}

/****************************************
*
*	Nom : ft_new_var_env
*	Params : - La ligne de char d'une ligne de variable d'environnement
*			 - Pointeur vers la premiere strcut de la liste chainee
*	Retour : Pointeur vers la nouvelle premiere structure de la liste chainee
*	Descritpion:
*		Divise la ligne d'environnement en deux partie (Division par le =)
*			place ces deux parties dans une strcut et la place en premier
*			sur la liste chainee de var d'env
*
****************************************/

t_var_env	*ft_new_var_env(char *str, t_var_env *old_struct)
{
	int			size_word;
	int			size_word2;
	t_var_env	*out_struct;

	out_struct = malloc(sizeof(t_var_env));
	if (!out_struct)
		return (NULL);
	size_word = ft_strchr_up(str, '=');
	out_struct->name_var = malloc(sizeof(char) * size_word);
	if (!out_struct->name_var)
	{
		free(out_struct);
		return (NULL);
	}
	ft_strlcpy(out_struct->name_var, str, size_word);
	size_word2 = ft_strlen(str) - size_word;
	out_struct->var_txt = malloc(sizeof(char) * size_word2);
	if (!out_struct->var_txt)
		return (ft_clean_no_place(out_struct));
	ft_strlcpy(out_struct->var_txt, &str[size_word + 1], size_word2);
	out_struct->next = old_struct;
	return (out_struct);
}

/****************************************
*
*	Nom : conv_env
*	Params : Matrice d'environnement
*	Retour : Pointeur vers la premiere struct de var env de la liste chainee
*	Descritpion:
*		Converti la matrice d'env
*
****************************************/

t_var_env	*conv_env(char **envp)
{
	int			x;
	t_var_env	*out_struct;

	x = ft_matrixlen(envp);
	out_struct = NULL;
	while (--x > -1)
	{
		out_struct = ft_new_var_env(envp[x], out_struct);
		if (!out_struct)
		{
			out_struct = NULL;
			break ;
		}
	}
	return (out_struct);
}

char	*ft_no_place_again(char *out_mat, t_var_env *tmp)
{
	ft_strlcpy(&out_mat[ft_strlen(tmp->name_var)], "=", 1);
	ft_strlcpy(&out_mat[ft_strlen(tmp->name_var) + 1], tmp->var_txt, \
	ft_strlen(tmp->var_txt));
	return (out_mat);
}

char	**conv_env_to_mat(void)
{
	char		**out_mat;
	int			x;
	int			i;
	t_var_env	*tmp;

	i = -1;
	x = ft_lstsize_up(g_datas.env_in_struct);
	out_mat = malloc(sizeof(char *) * (x + 1));
	tmp = g_datas.env_in_struct;
	out_mat[x] = NULL;
	while (++i < x)
	{
		if (!tmp->var_txt)
			out_mat[i] = (char *)malloc(ft_strlen(tmp->name_var) + 1);
		else
			out_mat[i] = malloc(ft_strlen(tmp->var_txt) \
					+ ft_strlen(tmp->name_var) + 2);
		ft_strlcpy(out_mat[i], tmp->name_var, ft_strlen(tmp->name_var));
		if (tmp->var_txt)
			ft_no_place_again(out_mat[i], tmp);
		tmp = tmp->next;
	}
	return (out_mat);
}
