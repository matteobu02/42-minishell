/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:48:22 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/17 16:23:03 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_list_to_index(char *str, t_var_env *list)
{
	int	index;

	index = 0;
	while (list && ft_strncmp(str, list->name_var, ft_strlen(str)))
	{
		index++;
		list = list->next;
	}
	if (!list)
		return (-1);
	return (index);
}

int	compare_paths(void)
{
	char	*path;
	int		ret;

	path = NULL;
	path = getcwd(path, 0);
	if (!ft_strncmp(path, ft_getenv("PATH", datas_prompt.env_in_struct), ft_strlen(path)))
		ret = 0;
	else
		ret = 1;
	free(path);
	path = NULL;
	return (ret);
}

void	replace_pwd(void)
{
	int			i;
	t_var_env	*ptr;

	ptr = datas_prompt.env_in_struct;
	i = ft_list_to_index("PWD", ptr);
	while (--i > -1)
		ptr = ptr->next;
	free(ptr->var_txt);
	ptr->var_txt = NULL;
	ptr->var_txt = getcwd(NULL, 0);
	ft_clean_mat(datas_prompt.envp);
	datas_prompt.envp = conv_env_to_mat();
}

void	cd(int ac, char **av)
{
	int	ret;

	if (ac == 1)
	{
		if (!ft_getenv("HOME", datas_prompt.env_in_struct))
			perror("HOME not set");
		else
		{
			ret = chdir(ft_getenv("HOME", datas_prompt.env_in_struct));
			if (ret)
				perror(NULL);
		}
	}
	else
	{
		ret = chdir(av[1]);
		if (ret == -1)
			perror(NULL);
	}
	if (compare_paths())
		replace_pwd();
}
