/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:48:22 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/19 16:01:51 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_list_to_index(char *str, t_var_env *list);

int	compare_paths(void)
{
	char	*path;
	char	*tmp;
	int		ret;

	path = NULL;
	path = getcwd(path, 0);
	tmp = ft_getenv("PATH", datas_prompt.env_in_struct);
	if (tmp && !ft_strncmp(path, tmp, ft_strlen(path)))
		ret = 1;
	else
		ret = 0;
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
	datas_prompt.last_command_status = 0;
}

void	print_error(char *cmd, char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	write(STDERR_FILENO, ": ", 2);
	ft_putstr_fd(arg, STDERR_FILENO);
	if (!ft_strchr(arg, '\n'))
	{
		write(STDERR_FILENO, ": ", 2);
		perror(NULL);
	}
	datas_prompt.last_command_status = 1;
}

void	cd(int ac, char **av)
{
	int	ret;

	if (ac == 1)
	{
		if (!ft_getenv("HOME", datas_prompt.env_in_struct))
			return (print_error("cd", "HOME not set\n"));
		else
		{
			ret = chdir(ft_getenv("HOME", datas_prompt.env_in_struct));
			if (ret)
				return (print_error("cd", ft_getenv("HOME", datas_prompt.env_in_struct)));
		}
	}
	else
	{
		ret = chdir(av[1]);
		if (ret == -1)
			return (print_error("cd", av[1]));
	}
	if (compare_paths())
		replace_pwd();
}
