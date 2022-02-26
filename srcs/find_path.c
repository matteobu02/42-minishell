/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:11:15 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/24 22:26:00 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : find_in_env
*	Params : - Matrice de char
*			 - Le mot qui est cherche
*			 - La taille du mot
*			 - L'index de depart pour la copie
*	Retour : La ligne de char ou se situe le mot cherche
*	Descritpion:
*		Parcourt la matrice a la rechecher de du mot, une fois trouvé il va
*			copier la ligne de caracteres a partir de l'index donne
*
****************************************/

char	*find_in_env(char **envp, char *word, int len_return)
{
	char	*path;
	int		i;

	i = -1;
	while (ft_matrixlen(envp) > ++i)
	{
		if (!ft_strncmp(envp[i], word, ft_strchr_up(envp[i], '=')))
		{
			path = ft_calloc(sizeof(char), ft_strlen(envp[i]) + 1);
			if (!path)
				return (NULL);
			ft_strlcpy(path, &envp[i][len_return], ft_strlen(envp[i]) + 1);
			return (path);
		}
	}
	return (NULL);
}
