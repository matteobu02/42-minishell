/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:48:22 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/23 16:17:36 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var_env	*ft_find_in_list(char *str, t_var_env *list)
{
	if (!str || !list)
		return (NULL);
	while (list && ft_strncmp(str, list->name_var, ft_strlen(str)))
		list = list->next;
	return (list);
}

int	compare_pwd(void)
{
	char	*path;
	char	*tmp;
	int		ret;

	tmp = ft_getenv("PWD", g_datas.env_in_struct);
	if (!tmp)
		return (0);
	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		return (0);
	ret = ft_strcmp(path, tmp);
	free(path);
	path = NULL;
	return (ret);
}

void	replace_pwd(void)
{
	t_var_env	*ptr;

	ptr = ft_find_in_list("PWD", g_datas.env_in_struct);
	free(ptr->var_txt);
	ptr->var_txt = NULL;
	ptr->var_txt = getcwd(NULL, 0);
	ft_clean_mat(g_datas.envp);
	g_datas.envp = conv_env_to_mat();
	g_datas.last_command_status = 0;
}

void	cd_error(char *cmd, char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	if (!ft_strchr(arg, '\n'))
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(NULL);
	}
	g_datas.last_command_status = 1;
}

void	cd(int ac, char **av)
{
	int	ret;

	if (ac == 1)
	{
		if (!ft_getenv("HOME", g_datas.env_in_struct))
			return (cd_error("cd", "HOME not set\n"));
		else
		{
			ret = chdir(ft_getenv("HOME", g_datas.env_in_struct));
			if (ret)
				return (cd_error("cd", \
					ft_getenv("HOME", g_datas.env_in_struct)));
		}
	}
	else
	{
		ret = chdir(av[1]);
		if (ret)
			return (cd_error("cd", av[1]));
	}
	if (compare_pwd())
		replace_pwd();
}
