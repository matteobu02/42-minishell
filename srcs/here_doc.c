/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:07:00 by lbuccher          #+#    #+#             */
/*   Updated: 2022/02/26 01:33:43 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*return_hd(t_datas_cmd *cmds, char **tmp1, char *join)
{
	int		x;
	char	*tmp;

	x = -1;
	tmp1 = ft_split(join, '\n');
	if (!tmp1)
		return (NULL);
	if (ft_matrixlen(tmp1) == cmds->type_hd - 1)
		return (NULL);
	while (++x < (ft_matrixlen(tmp1) + 1) - cmds->type_hd)
	{
		if (!x)
			tmp = cpy_with_malloc(tmp1[x]);
		else
			tmp = ft_strjoin_up(tmp, tmp1[x]);
		if (!tmp)
		{
			ft_clean_mat(tmp1);
			return (NULL);
		}
	}
	return (tmp);
}

void	ft_here_doc2(t_datas_cmd *cmds, char *here_doc, char *join, int here_fd)
{
	char	*tmp;
	char	**tmp1;

	tmp1 = NULL;
	tmp = return_hd(cmds, tmp1, join);
	ft_clean_mat(tmp1);
	ft_putstr_fd(tmp, here_fd);
	close(here_fd);
	free(tmp);
	tmp = malloc((ft_strlen(join) * sizeof(char)) + 1);
	if (!tmp)
		return ;
	here_fd = open(".tmp", O_RDONLY, 0644);
	free(here_doc);
	if (cmds->nb_cmds && cmds->cmd_first->cmd)
		cmds->cmd_first->infile = here_fd;
	else
	{
		read(here_fd, tmp, ft_strlen(join));
		ft_putstr_fd(tmp, 1);
		close(here_fd);
	}
	free(join);
	free(tmp);
}

void	get_here_doc(char *join, char **end_word, int here_fd)
{
	int		i;
	char	*here_doc;

	i = 0;
	end_word = g_datas.cmds->magic_word;
	while (1)
	{
		ft_putstr_fd("heredoc>", 1);
		here_doc = get_next_line(1);
		if (here_doc && (ft_strlen(end_word[i]) == ft_strlen(here_doc) - 1)
			&& !ft_strncmp(here_doc, end_word[i], ft_strlen(end_word[i])))
			i++;
		else
			i = 0;
		if (i == g_datas.cmds->type_hd)
			break ;
		join = ft_strjoin_up(join, here_doc);
		free(here_doc);
		if (!join)
		{
			close(here_fd);
			return ;
		}
	}
	ft_here_doc2(g_datas.cmds, here_doc, join, here_fd);
}

void	ft_here_doc(char **end_word)
{
	char	*join;
	int		here_fd;

	join = ft_calloc(1, 1);
	if (!join)
		return ;
	here_fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (here_fd == -1)
		return (perror("open"));
	get_here_doc(join, end_word, here_fd);
}
