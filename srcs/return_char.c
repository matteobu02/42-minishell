/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:58:09 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/26 12:51:24 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : return_char
*	Params : - liste de chars liee a la Matrice de la commande
*			 - la positon dans la liste de chars
*			 - la matrice d'env
*			 - la premiere stuct de la liste chainee
*	Retour : Liste de char modifie ou on remplace la var d'env par sa liste de
*				char liee
*	Descritpion:
*		Defini la longueur de la var d'env, prend ensuite la liste de char liee
*			a la var d'env, cut avant et apres la variable d'env et colle les
*			deux partie avec la liste de char liee a la var d'env
*
****************************************/

char	*return_char1(char *cmd, t_var_env *out_struct)
{
	char	*tmp;

	tmp = find_in_struct(cmd, g_datas.env_in_struct);
	if (tmp == NULL)
	{
		tmp = find_in_struct(cmd, out_struct);
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char) * 2);
			if (!tmp)
				return (NULL);
			tmp[0] = '\0';
		}
	}
	return (tmp);
}

char	*return_char2(char *cmd, int y)
{
	char	*tmp;

	tmp = ft_calloc(sizeof(char), y);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, cmd, y);
	return (tmp);
}

char	*return_char3(char *cmd, int y)
{
	char	*tmp;

	tmp = ft_calloc(sizeof(char), ft_strlen(&cmd[y + \
		ft_strlen_up(&cmd[y + 1], " \"\'$")]));
	if (!tmp)
	{
		return (NULL);
	}
	ft_strlcpy(tmp, &cmd[y + 1 + ft_strlen_up(&cmd[y + 1], " \"\'$")], \
		ft_strlen(&cmd[y + ft_strlen_up(&cmd[y + 1], " \"\'$")]));
	return (tmp);
}

char	*return_char4(char *cmds, int y, char **tmp)
{
	char	*out;

	ft_free_little_matrice(tmp, 2);
	if (!tmp[2])
		return (NULL);
	tmp[0] = return_char3(cmds, y);
	if (!tmp[0])
		return (ft_free_little_matrice(tmp, 0));
	tmp[1] = ft_strjoin(tmp[2], tmp[0]);
	if (!tmp[1])
		return (ft_free_little_matrice(tmp, 1));
	if (cmds)
		free(cmds);
	out = ft_calloc(sizeof(char), ft_strlen(tmp[1]) + 1);
	ft_strlcpy(out, tmp[1], ft_strlen(tmp[1]) + 1);
	ft_free_little_matrice(tmp, 3);
	free(tmp);
	if (!out)
		return (NULL);
	return (out);
}

char	*return_char(char *cmds, int y, t_var_env *out_struct)
{
	char	**tmp;

	tmp = malloc(sizeof(char *) * 3);
	if (!tmp)
		return (NULL);
	tmp[0] = return_char1(&cmds[y + 1], out_struct);
	if (!tmp[0])
	{
		free(tmp);
		return (NULL);
	}
	tmp[1] = return_char2(cmds, y);
	if (!tmp[1])
	{
		if (tmp[0])
		{
			free(tmp[0]);
			free(tmp);
		}
		return (NULL);
	}
	tmp[2] = ft_strjoin(tmp[1], tmp[0]);
	return (return_char4(cmds, y, tmp));
}
