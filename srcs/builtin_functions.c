/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:49:11 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/16 16:53:21 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minishell.h"

int	ft_open(t_one_cmd *cmd)
{
	int	fd;

	if (!cmd->type_next)
		return (1);
	fd = open("tmp_build", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return(0);
	cmd->infile = fd;
	return (fd);
}

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

int	compare_paths()
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


/*	EXPORT NAME
 *	if NAME is already a variable it will be added to env
 *	if NAME has no value NAME
 * */

/*void	export(int ac, char **av)
{
	int	i;

	// check for forbidden characters
	// if no parameter is given
	if (ac == 1)
	{
		// display all exported variables in alphabetic order
	}
	else
	{
		i = 0;
		while (++i < ac)
		{
			//	if (av[i] in sys_var or var does not have a value)
				//	add to env list + delete sys_var List;
		}
	}
}

void	unset(int ac, char **av)
{
	int	i;

	if (ac == 1)
		return ;
	i = 0;
 	while (++i < ac)
	{
		//	if (av[i] in env)
		//		delete element;
		//	else if (av[i] in sys_var)
		//		delete element;
		//	else
		//		;
	}
}*/

void	ft_exit(void)
{
	ft_free_datas_cmd(datas_prompt.cmds);
	ft_new_free(datas_prompt.env_in_struct);
	if (datas_prompt.out_struct)
		ft_new_free(datas_prompt.out_struct);
	exit(0);
}
