/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:49:11 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/17 16:39:21 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minishell.h"

int	ft_list_to_index(char *str, t_var_env *ptr);

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
}*/

void	ft_remove_link(int index, t_var_env *list)
{
	t_var_env	*tmp;

	while (list && --index > 0)
		list = list->next;
	tmp = list->next;
	list->next = list->next->next;
	free(tmp->var_txt);
	free(tmp->name_var);
	free(tmp);
	tmp = NULL;
}

void	unset(int ac, char **av)
{
	int	i;
	int	x;

	if (ac == 1)
		return ;
	i = 0;
 	while (++i < ac)
	{
		x = ft_list_to_index(av[i], datas_prompt.env_in_struct);
		if (x != -1)
			ft_remove_link(x, datas_prompt.env_in_struct);
		else
		{
			x = ft_list_to_index(av[i], datas_prompt.out_struct);
			if (x != -1)
				ft_remove_link(x, datas_prompt.out_struct);
		}
	}
}

void	ft_exit(void)
{
	char **tmp;

	tmp = malloc(sizeof(char *) * 3);
	tmp[0] = "rm";
	tmp[1] = "-f";
	tmp[2] = "tmp";
	execve("/bin/rm", tmp, datas_prompt.envp);
	ft_free_datas_cmd(datas_prompt.cmds);
	ft_new_free(datas_prompt.env_in_struct);
	if (datas_prompt.out_struct)
		ft_new_free(datas_prompt.out_struct);
	exit(0);
}
