/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:55:26 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/25 09:55:28 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_one_cmd	*move_fd1(t_one_cmd *cmd_now, t_one_cmd *cmd_next)
{
	if (cmd_next->infile == 0 && cmd_now->infile != 0)
		cmd_next->infile = cmd_now->infile;
	if (cmd_next->outfile == 1 && cmd_now->outfile != 1)
		cmd_next->outfile = cmd_now->outfile;
	return (cmd_next);
}

t_one_cmd	*move_fd2(t_one_cmd *cmd_now, t_one_cmd *cmd_next)
{
	if (cmd_next->infile == 0 && cmd_now->infile != 0)
		cmd_next->infile = cmd_now->infile;
	if (cmd_next->outfile == 1 && cmd_now->outfile != 1)
		cmd_next->outfile = cmd_now->outfile;
	return (cmd_next);
}

t_one_cmd	*move_fd3(t_one_cmd *cmd_now, t_one_cmd *cmd_prev)
{
	if (cmd_prev->outfile == 1 && cmd_now->outfile != 1)
		cmd_prev->outfile = cmd_now->outfile;
	if (cmd_prev->infile == 1 && cmd_now->infile != 1)
		cmd_prev->infile = cmd_now->infile;
	return (NULL);
}

t_one_cmd	*move_fd4(t_one_cmd *cmd_first, int nb_escape, t_datas_cmd *all, \
		t_one_cmd	*cmd_now)
{
	t_one_cmd	*cmd_prev;
	t_one_cmd	*cmd_next;
	int			nb_struct;

	nb_struct = ft_lstsize(cmd_first);
	if (!cmd_now->cmd)
	{
		cmd_prev = NULL;
		if (nb_struct - nb_escape - 1 > 0)
			cmd_prev = ft_lstnb(cmd_first, nb_struct - nb_escape - 1);
		cmd_next = cmd_now->next;
		if (cmd_next && !cmd_prev)
			cmd_first = move_fd1(cmd_now, cmd_next);
		else if (cmd_next && cmd_prev)
			cmd_prev->next = move_fd2(cmd_now, cmd_next);
		else if (!cmd_next && cmd_prev)
			cmd_prev->next = move_fd3(cmd_now, cmd_prev);
		ft_free_one_cmd(cmd_now, 1);
		nb_escape = 0;
		if (!cmd_next && !cmd_prev)
			return (NULL);
	}
	else
		nb_escape++;
	return (move_fd(cmd_first, nb_escape, all));
}

t_one_cmd	*move_fd(t_one_cmd *cmd_first, int nb_escape, t_datas_cmd *all)
{
	t_one_cmd	*cmd_now;
	int			nb_struct;

	nb_struct = ft_lstsize(cmd_first);
	if (nb_struct == nb_escape)
		return (cmd_first);
	cmd_now = ft_lstnb(cmd_first, nb_struct - nb_escape);
	if (nb_struct == 1 && (cmd_now->cmd || all->type_hd))
		return (cmd_first);
	return (move_fd4(cmd_first, nb_escape, all, cmd_now));
}
