/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:10:53 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/24 22:29:12 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : find_in_struct
*	Params : - Liste de char recherchee a travers toute la liste chainee
*			 - Pointeur vers la premiere strcut de la liste chainee
*	Retour : La liste de char liee a la lste de char recherchee
*	Descritpion:
*		Compare la liste de chars recherchee a celle de la struct, si elles sont
*			egales alors on retourne une copie de la liste de char liee sinon on
*			refait la fonction sur la strcut suivante de la liste chainee, si il
*			n'y en a pas alors le code renvoi nul
*
****************************************/

char	*find_in_struct(char *var_env, t_var_env *out)
{
	char	*tmp1;

	if (!out)
		return (NULL);
	if (!ft_strncmp(var_env, out->name_var, ft_strlen(out->name_var)))
	{
		tmp1 = ft_calloc(sizeof(char), ft_strlen(out->var_txt));
		if (!tmp1)
			return (NULL);
		ft_strlcpy(tmp1, out->var_txt, ft_strlen(out->var_txt));
		return (tmp1);
	}
	else if (out->next)
		return (find_in_struct(var_env, out->next));
	return (NULL);
}

/****************************************
*
*	Nom : modif_mat
*	Params : - La Matrice de la commande
*			 - la matrice d'env
*			 - la premiere stuct de la liste chainee
*	Retour : La Matrice de la commande ou les vars d'env ont ete remplacees par
*				leurs valeurs
*	Descritpion:
*		Parcour la liste puor trouver un $ signifiant qu'il a trouve une var
*			d'env, la commande return char var s'occuper de remplacer la var
*			d'env par sa valeur reelle
*
****************************************/

char	*modif_mat2(char *cmd, int y, t_var_env *out_struct)
{
	char	*tmp;
	char	*tmp1;

	if (cmd[y] == '$')
	{
		if (y <= (int)ft_strlen(cmd) - 1 && cmd[y + 1] == '?')
		{
			tmp1 = ft_itoa(g_datas.last_command_status);
			tmp = ft_calloc(ft_strlen(cmd) - 2 + ft_strlen(tmp1), \
				sizeof(char));
			ft_strlcpy(tmp, cmd, y);
			ft_strlcpy(&tmp[y], tmp1, ft_strlen(tmp1) + 1);
			ft_strlcpy(&tmp[y + ft_strlen(tmp1)], &cmd[y + 2], \
				ft_strlen(&cmd[y + 2]) + 1);
			free(cmd);
			cmd = tmp;
		}
		else if ((y > 0 && cmd[0] == '"') || (y == 0))
			cmd = return_char(cmd, y, out_struct);
	}
	return (cmd);
}

char	*replace_two_char(char *cmd, char erase)
{
	int		x;
	int		y;
	int		count;
	char	*return_char;

	x = -1;
	y = -1;
	return_char = malloc(sizeof(char) * ft_strlen(cmd) - 1);
	if (!return_char)
		return (NULL);
	count = 0;
	while (++x < (int)ft_strlen(cmd) && count != 2)
	{
		if (cmd[x] != erase)
			return_char[++y] = cmd[x];
		else
			count++;
	}
	--x;
	while (++x < (int)ft_strlen(cmd))
		return_char[++y] = cmd[x];
	return_char[++y] = '\0';
	free(cmd);
	return (return_char);
}

char	*modif_mat3(char *cmd, int *y, int *stat_simple, int *stat_double)
{
	if (cmd[(*y)] == '"' && !(*stat_simple))
	{
		(*stat_double)++;
		if (!((*stat_double) % 2))
		{
			cmd = replace_two_char(cmd, '"');
			(*stat_double) = 0;
			(*y) -= 2;
		}
	}
	else if (cmd[*y] == 39 && !*stat_double)
	{
		(*stat_simple)++;
		if (!((*stat_simple) % 2))
		{
			cmd = replace_two_char(cmd, 39);
			(*stat_simple) = 0;
			(*y) -= 2;
		}
	}
	return (cmd);
}

char	**modif_mat(char **cmds, t_var_env *out_struct)
{
	int		x;
	int		y;
	int		stat_simple;
	int		stat_double;

	x = -1;
	while (++x < ft_matrixlen(cmds))
	{
		y = -1;
		stat_simple = 0;
		stat_double = 0;
		while (++y < (int)ft_strlen(cmds[x]))
		{
			cmds[x] = modif_mat2(cmds[x], y, out_struct);
			cmds[x] = modif_mat3(cmds[x], &y, &stat_simple, &stat_double);
		}
	}
	return (cmds);
}
