/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:07:12 by mbucci            #+#    #+#             */
/*   Updated: 2022/02/26 03:08:37 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_move_link(char *s, t_var_env **src, t_var_env *dst)
{
	t_var_env	*tmp;

	if (!ft_strcmp((*src)->name_var, s))
	{
		while (dst && dst->next)
			dst = dst->next;
		dst->next = *src;
		*src = (*src)->next;
		return ;
	}
	tmp = *src;
	while (tmp && tmp->next && ft_strcmp(s, tmp->next->name_var))
		tmp = tmp->next;
	while (dst && dst->next)
		dst = dst->next;
	dst->next = tmp->next;
	tmp->next = tmp->next->next;
	dst->next->next = NULL;
}

int	redefine_text(t_var_env *ptr, char *s, char *name)
{
	if (ptr->var_txt)
		free(ptr->var_txt);
	ptr->var_txt = ft_substr(s, ft_strlen(name) + 1, ft_strlen(s) - ft_strlen(name) + 1);
	if (!ptr->var_txt)
		return (1);
	return (0);
}

int	add_to_env(char *s)
{
	char		*s_name;
	t_var_env	*tmp1;
	t_var_env	*tmp2;
	t_var_env	*ptr;

	if (!ft_strchr(s, '='))
	{
		if (ft_find_in_list(s, datas_prompt.env_in_struct))
			return (0);
		else if (ft_find_in_list(s, datas_prompt.out_struct))
			ft_move_link(s, &datas_prompt.out_struct, datas_prompt.env_in_struct);
		else
		{
			ptr = (t_var_env *)malloc(sizeof(t_var_env));
			if (!ptr)
				return (1);
			ptr->next = datas_prompt.env_in_struct;
			datas_prompt.env_in_struct = ptr;
			ptr->name_var = ft_strdup(s);
			ptr->var_txt = NULL;
		}
	}
	else
	{
		s_name = ft_substr(s, 0, ft_strchr_up(s, '='));
		if (!s_name)
			return (1);
		tmp1 = ft_find_in_list(s_name, datas_prompt.env_in_struct);
		tmp2 = ft_find_in_list(s_name, datas_prompt.out_struct);
		if (!tmp1 && !tmp2)
			datas_prompt.env_in_struct = ft_new_var_env(s, datas_prompt.env_in_struct);
		else if (tmp1)
		{
			if (redefine_text(tmp1, s, s_name))
				return (1);
		}
		else if (tmp2)
		{
			if (redefine_text(tmp2, s, s_name))
				return (1);
			ft_move_link(s_name, &datas_prompt.out_struct, datas_prompt.env_in_struct);
		}
		free(s_name);
	}
	return (0);
}
