/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:03 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/24 22:26:59 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : start_prompt
*	Params : La matrcie d'env
*	Retour : La ligne qui sera affichee au prompt
*	Descritpion:
*		Isole la valeur de user et ajoute le coloris et le @minishell
*
****************************************/

char	*start_prompt1(char *output, char *tmp1)
{
	char	*tmp;

	if (!g_datas.last_command_status)
		tmp = ft_strjoin(output, " \033[0;92m>\033[0;39m ");
	else
		tmp = ft_strjoin(output, " \033[0;91m>\033[0;39m ");
	free(output);
	free(tmp1);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*start_prompt(char **env)
{
	char	*output;
	char	*tmp;
	char	*tmp1;

	tmp = find_in_env(env, "USER=", 5);
	if (!tmp)
		return (NULL);
	tmp1 = ft_strjoin("\033[0;91m", tmp);
	if (!tmp1)
	{
		free(tmp);
		return (NULL);
	}
	output = ft_strjoin(tmp1, "\033[0;39m@\033[0;92mminishell\033[0;39m");
	free(tmp);
	if (!output)
	{
		free(tmp1);
		return (NULL);
	}
	return (start_prompt1(output, tmp1));
}
