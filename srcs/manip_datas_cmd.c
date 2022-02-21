/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_datas_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:15:35 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:15:38 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	er(char *str, int error, int status)
{
	if (status)
	{
		ft_putstr_fd("Minishell: ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		datas_prompt.last_command_status = error;
		return (1);
	}
	ft_putstr_fd(str, 1);
	datas_prompt.last_command_status = error;
	return (1);
}

int	search_forget(char *map, char forget)
{
	int x;
	int count;

	x = -1;
	count = 0;
	while (++x < (int)ft_strlen(map))
		if (map[x] == forget)
			count++;
	if (map[x - 1] != forget)
		return (1);
	return (count);
}

int	check_map2(char **map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < ft_matrixlen(map))
	{
		y = -1;
		while (++y < (int)ft_strlen(map[x]))
		{
			if ((map[x][0] == '"' && search_forget(map[x], '"') % 2) || (map[x][0] == '\'' && search_forget(map[x], 39) % 2))
				return (er("Minishell: error at the end of command\n", 1, 0));
			else if (map[x][y] == '!' && ft_strlen(map[x]) == 2
					&& map[x][1] == '!')
				if (!datas_prompt.old_command)
					return (er("Minishell: !!: Event not found\n", 1, 0));
		}

	}
	return (0);
}

int	check_map(char **map)
{
	int	x;

	x = ft_matrixlen(map) - 1;
	if ((map[x][0] == '<') || (map[x][0] == '>'))
		return (er("Minishell: syntax error near unexpected token \
			`newline'\n", 258, 0));
	else if (map[x][0] == '|')
		return (er("Minishell: error at the end of command\n", 1, 0));
	else if (infile(map) < 0 || outfile(map) < 0)
		return (er(map[find_next_char(map, '<') + 1], 1, 1));
	else
		return (check_map2(map));
	return (0);
}

char	**ft_cpy_maic_word(t_datas_cmd *cmd, int x, int status)
{
	int		y;
	int		k;
	char	**tmp;

	if (status)
	{
		cmd->magic_word = malloc(sizeof(char *) * 2);
		cmd->magic_word[0] = cpy_with_malloc(cmd->all_cmds[x + 1]);
		cmd->magic_word[1] = NULL;
		return (cmd->magic_word);
	}
	tmp = cmd->magic_word;
	cmd->magic_word = malloc(sizeof(char *) * ft_matrixlen(tmp) + 2);
	y = -1;
	k = ft_matrixlen(tmp);
	while (++y < k)
	{
		cmd->magic_word[y] = cpy_with_malloc(tmp[y]);
		free(tmp[y]);
	}
	cmd->magic_word[y] = cpy_with_malloc(cmd->all_cmds[x + 1]);
	free(tmp);
	return (cmd->magic_word);
}

void	search_hd(t_datas_cmd *cmd)
{
	int		x;

	x = find_next_char(cmd->all_cmds, '<');
	cmd->type_hd = 0;
	cmd->magic_word = NULL;
	while (x < ft_matrixlen(cmd->all_cmds))
	{
		if (ft_matrixlen(&cmd->all_cmds[x]) >= 2
			&& ft_strlen(cmd->all_cmds[x]) == 2)
		{
			if (cmd->all_cmds[x][1] == '<')
			{
				cmd->type_hd++;
				if (cmd->magic_word)
					cmd->magic_word = ft_cpy_maic_word(cmd, x, 0);
				else
					ft_cpy_maic_word(cmd, x, 1);
			}
		}
		x += find_next_char(&cmd->all_cmds[x + 1], '<') + 1;
	}
}

/****************************************
*
*	Nom : gen_datas_cmd
*	Params : - La ligne complete de commandes
*			 - La strcut de datas_prompt
*	Retour : La struct relative a toute la ligne de commande (datas_cmd)
*	Descritpion:
*		A parti de la chaine de char, la strcuture va stocker un split_up de la
*			chaine (separations par des espaces, des tabs et d'autes cas plus
*			specifiques), met en evidence le path pour pipex, lan la fct
*			trans_cmd qui va permettre de creer une strcut par commande, reprend
*			datas_prompt pour le repointer et init le nombre de commandes
*
****************************************/

t_datas_cmd	*ft_free_no_place(t_datas_cmd *cmd)
{
	ft_clean_mat(cmd->all_cmds);
	free(cmd);
	return (NULL);
}

t_one_cmd	*ft_lstnb(t_one_cmd *cmd_first, int nb)
{
	t_one_cmd	*tmp;

	tmp = cmd_first;
	while (--nb > 0)
		tmp = tmp->next;
	return (tmp);
}

int	ft_lstsize_down(t_one_cmd *lst)
{
	if (!lst)
		return (0);
	if (lst->next == 0)
		return (1);
	return (1 + ft_lstsize_down(lst->next));
}

t_one_cmd	*move_fd(t_one_cmd *cmd_first, int nb_escape)
{
	t_one_cmd	*cmd_now;
	t_one_cmd	*cmd_prev;
	t_one_cmd	*cmd_next;
	int			nb_struct;

	nb_struct = ft_lstsize_down(cmd_first);
	if (nb_struct == nb_escape)
		return (cmd_first);
	cmd_now = ft_lstnb(cmd_first, nb_struct - nb_escape);
	if (nb_struct == 1)
		return (cmd_first);
	if (!cmd_now->cmd)
	{
		cmd_prev = NULL;
		if (nb_struct - nb_escape - 1 > 0)
			cmd_prev = ft_lstnb(cmd_first, nb_struct - nb_escape - 1);
		cmd_next = cmd_now->next;
		if (cmd_next && !cmd_prev)
		{
			if (cmd_next->infile == 0 && cmd_now->infile != 0)
				cmd_next->infile = cmd_now->infile;
			if (cmd_next->outfile == 1 && cmd_now->outfile != 1)
				cmd_next->outfile = cmd_now->outfile;
			cmd_first = cmd_next;
			ft_free_one_cmd(cmd_now, 1);
			nb_escape = 0;
		}
		else if (cmd_next && cmd_prev)
		{
			if (cmd_next->infile == 1 && cmd_now->outfile != 1)
				cmd_next->infile = cmd_now->outfile;
			if (cmd_prev->outfile == 1 && cmd_now->outfile != 1)
				cmd_prev->outfile = cmd_now->outfile;
			cmd_prev->next = cmd_next;
			ft_free_one_cmd(cmd_now, 1);
			nb_escape = 0;
		}
		else if (!cmd_next && cmd_prev)
		{
			if (cmd_prev->outfile == 1 && cmd_now->outfile != 1)
				cmd_prev->outfile = cmd_now->outfile;
			if (cmd_prev->infile == 1 && cmd_now->infile != 1)
				cmd_prev->infile = cmd_now->infile;
			cmd_prev->next = NULL;
			ft_free_one_cmd(cmd_now, 1);
			nb_escape = 0;
		}
	}
	else if ((ft_strchr_up(cmd_now->cmd, '=') && (ft_strchr_up(cmd_now->cmd, '"') == 0
				|| ft_strchr_up(cmd_now->cmd, '"') > ft_strchr_up(cmd_now->cmd, '='))))
	{
		cmd_prev = ft_lstnb(cmd_first, nb_struct - 1);
		datas_prompt.out_struct = \
			ft_new_var_env(cmd_now->cmd, datas_prompt.out_struct);
		ft_free_one_cmd(cmd_now, 1);
		cmd_prev->type_next = 0;
		cmd_prev->next = NULL;
	}
	return (move_fd(cmd_first, nb_escape + 1));
}

t_datas_cmd	*gen_datas_cmd(char *x, t_datas_prompt *datas_prompt)
{
	t_datas_cmd	*cmd;

	cmd = malloc(sizeof(t_datas_cmd));
	if (!cmd)
		exit (0);
	cmd->all_cmds = ft_split_up(x);
	search_hd(cmd);
	if (!cmd->all_cmds)
	{
		free(cmd);
		return (NULL);
	}
	if (check_map(cmd->all_cmds))
	{
		return (ft_free_no_place(cmd));
	}
	ft_putstr_fd("test\n", 1);
	cmd->cmd_first = trans_cmd(cmd->all_cmds, cmd, 0, NULL);
	ft_putstr_fd("test\n", 1);
	cmd->cmd_first = move_fd(cmd->cmd_first, 0);
	if (!cmd->cmd_first->next)
	{
		if ((ft_strchr_up(cmd->cmd_first->cmd, '=') && (ft_strchr_up(cmd->cmd_first->cmd, '"') == 0
					|| ft_strchr_up(cmd->cmd_first->cmd, '"') > ft_strchr_up(cmd->cmd_first->cmd, '='))))
		{
			datas_prompt->out_struct = \
				ft_new_var_env(cmd->cmd_first->cmd, datas_prompt->out_struct);
			ft_free_datas_cmd(cmd);
			return (NULL);
		}
	}
	if (!cmd->cmd_first)
	{
		ft_free_datas_cmd(cmd);
		return (NULL);
	}
	cmd->datas_prompt = datas_prompt;
	cmd->nb_cmds = ft_lstsize(cmd->cmd_first);
	return (cmd);
}
