/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:43:51 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/26 02:36:47 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_char_in_name(char *s, int *ptr)
{
	int	i;

	i = -1;
	while (s[++i] && (ft_isalpha(s[i]) || (i != 0 && ft_isdigit(s[i]))
			|| s[i] == '_'))
		;
	if (!s[i])
		return (0);
	else
	{
		ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
		ft_putstr_fd(s, STDERR_FILENO);
		ft_putstr_fd("': ", STDERR_FILENO);
		ft_putendl_fd("not a valid identifier", STDERR_FILENO);
		*ptr = 1;
	}
	return (1);
}

void	ft_remove_link(t_var_env *target, t_var_env **list)
{
	t_var_env	*tmp;
	t_var_env	*ptr;

	if (!list || !*list || !target)
		return ;
	ptr = *list;
	if (target == ptr)
	{
		tmp = ptr;
		*list = (*list)->next;
	}
	else
	{
		while (ptr && ptr->next && ptr->next != target)
			ptr = ptr->next;
		tmp = ptr->next;
		if (ptr->next->next)
			ptr->next = ptr->next->next;
		else
			ptr->next = NULL;
	}
	if (tmp->var_txt)
		free(tmp->var_txt);
	free(tmp->name_var);
	free(tmp);
}

void	update_env(void)
{
	ft_clean_mat(g_datas.envp);
	g_datas.envp = conv_env_to_mat();
}

void	unset(int ac, char **av)
{
	int			i;
	int			status;
	t_var_env	*found;

	i = -1;
	status = 0;
	while (++i < ac)
	{
		if (check_char_in_name(av[i], &status))
			continue ;
		found = ft_find_in_list(av[i], g_datas.env_in_struct);
		if (found)
			ft_remove_link(found, &g_datas.env_in_struct);
		else
			found = ft_find_in_list(av[i], g_datas.out_struct);
		if (found)
			ft_remove_link(found, &g_datas.out_struct);
	}
	if (ac)
		update_env();
	g_datas.last_command_status = status;
}
