/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:12:14 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/18 15:54:46 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# define INPUT "######################################################\n\
#     __  ____       _      __         ____          #\n\
#    /  |/  (_)___  (_)____/ /_  ___  / / /          #\n\
#   / /|_/ / / __ \\/ / ___/ __ \\/ _ \\/ / /           #\n\
#  / /  / / / / / / (__  ) / / /  __/ / /            #\n\
# /_/  /_/_/_/ /_/_/____/_/ /_/\\___/_/_/             #\n\
#                                                    #\n\
# Dev by Lisa Buccheri, Matteo Bucci & Hugo Goorickx #\n\
# (Version 0.6.2)                                    #\n\
######################################################\n"



void		ft_free_one_cmd(t_one_cmd *first_cmd, int status);
void		ft_free_datas_cmd(t_datas_cmd *datas_cmd);
void		ft_new_free(t_var_env *input);
void		cmd_process(t_fd fds, char **argv, char *env[], int j);
void		pipe_rec(t_datas_cmd *cmds, char *env[], int prev_fd[2], \
	t_one_cmd *cmd);
void		ft_here_doc(t_datas_cmd *cmds, char *end_word);
void		ft_free(char **paths, char **cmd);
void		close_pipe(int fd[2]);
void		parent(t_fd fds, char *argv[], char *env[], int fd[2]);
void		child(t_fd fds, char *argv[], char *env[], int fd[2]);
void		perror_cnf(char *str, char *cmd, int fd);
void		ft_end_process(char *cmd_path, char **cmd, char **path, char **env, \
	t_one_cmd *cmd_struct);
void		process(char *env[], char **cmd, t_one_cmd *cmd_struct, int to_exec);
void 		cd(int ac, char **av);
void		echo(int ac, char **av);
void 		env(void);
void		pwd(void);
void		unset(int ac, char **av);
void		ft_exit(void);
void		ft_clean_mat(char **mat);

int			ft_strchr_up(const char *str, int to_find);
int			ft_strlen_up(char *str, char *search);
int			infile(char **all_cmd);
int			outfile(char **all_cmd);
int			count_cmd(char *argv[]);
int			find_builtin(t_one_cmd *cmd);
int			check_builtin(t_one_cmd *cmd);
int			ft_open(t_one_cmd *cmd);

char		*find_in_env(char **envp, char *word, int len_word, int len_return);
char		*start_prompt(char **env);
char		*cpy_with_malloc(char *tmp);
char		*ft_getenv(char *var_name, t_var_env *list);

char		**ft_first_cmd(char **all_cmds);
char		**get_path(char *env[]);
char		**pipen_t(char **cmds);
char		**modif_mat(char **cmds, char **envp, t_var_env *out_struct);
char		**simple_mat(char **start_mat);
char		**conv_env_to_mat(void);

t_datas_cmd	*gen_datas_cmd(char *x, t_datas_prompt *datas_prompt);
t_datas_cmd	*ft_parsing(char *cmd_one_line, t_datas_prompt *datas_prompt);

t_one_cmd	*trans_cmd(char **cmds, t_datas_prompt *datas_prompt, int st, \
	t_one_cmd *old_one);

t_var_env	*conv_env(char **envp);
t_var_env	*ft_new_var_env(char *str, t_var_env *old_struct);

#endif
