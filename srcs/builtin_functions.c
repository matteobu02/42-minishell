/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:49:11 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/21 14:37:54 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minishell.h"

t_var_env	*ft_find_in_list(char *str, t_var_env *list);

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

/*void	print_list(void)
{
	t_var_env	*ptr;

	ptr = datas_prompt.env_in_struct;
	while (ptr)
	{
		printf("%s=%s\n", ptr->name_var, ptr->var_txt);
		ptr = ptr->next;
	}
}*/

/*void	print_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		printf("%s\n", matrix[i]);
}*/

/*int	forbidden_char_in_name(char *s)
{
	const char	*
}*/

void	ft_remove_link(t_var_env *target, t_var_env *list)
{
	t_var_env	*tmp;

	if (!list || !target)
		return ;
	while (list && list != target && list->next != target)
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
	int			i;
	t_var_env	*ptr;

	if (ac == 1)
	{
		datas_prompt.last_command_status = 0;
		return ;
	}
	i = -1;
 	while (++i < ac)
	{
		//check for forbidden characters
		//	if forbidden char print error message and keep going
		ptr = ft_find_in_list(av[i], datas_prompt.env_in_struct);
		if (!ptr)
			ft_remove_link(ptr, datas_prompt.env_in_struct);
		else
		{
			ptr = ft_find_in_list(av[i], datas_prompt.out_struct);
			if (!ptr)
				ft_remove_link(ptr, datas_prompt.out_struct);
		}
	}
	ft_clean_mat(datas_prompt.envp);
	datas_prompt.envp = conv_env_to_mat();
	datas_prompt.last_command_status = 0;
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
