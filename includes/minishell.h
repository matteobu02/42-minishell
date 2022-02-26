/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:12:14 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/26 02:34:41 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

t_datas	g_datas;

# define INPUT "\033[2J######################################################\n\
#     __  ____       _      __         ____          #\n\
#    /  |/  (_)___  (_)____/ /_  ___  / / /          #\n\
#   / /|_/ / / __ \\/ / ___/ __ \\/ _ \\/ / /           #\n\
#  / /  / / / / / / (__  ) / / /  __/ / /            #\n\
# /_/  /_/_/_/ /_/_/____/_/ /_/\\___/_/_/             #\n\
#                                                    #\n\
# Dev by Lisa Buccheri, Matteo Bucci & Hugo Goorickx #\n\
# (Version 1.0.0)                                    #\n\
######################################################\n"

void		*ft_free_one_cmd(t_one_cmd *first_cmd, int status);
void		*ft_free_datas_cmd(t_datas_cmd *datas_cmd);
void		ft_new_free(t_var_env *input);
void		cmd_process(t_fd fds, char **argv, char *env[], int j);
void		pipe_rec(t_datas_cmd *cmds, char *env[], int prev_fd[2], \
	t_one_cmd *cmd);
void		ft_here_doc(char **end_word);
void		ft_free(char **paths, char **cmd);
void		close_pipe(int fd[2]);
void		parent(t_fd fds, char *argv[], char *env[], int fd[2]);
void		child(t_fd fds, char *argv[], char *env[], int fd[2]);
void		perror_cnf(char *str, char *cmd, int fd);
void		ft_end_process(char *cmd_path, char **cmd, char **path, \
	t_one_cmd *cmd_struct);
void		process(char *env[], char **cmd, t_one_cmd *cmd_struct, \
	int to_exec);
void		cd(int ac, char **av);
void		echo(int ac, char **av);
void		env(void);
void		pwd(void);
void		ft_export(int ac, char **av);
void		unset(int ac, char **av);
void		ft_exit(void);
void		ft_clean_mat(char **mat);
void		var_error(char *funct, char *var);
void		search_hd(t_datas_cmd *cmd);
void		ft_redirection(int fd_in, int fd_out, int simple, int first);
void		multi_pipe(t_datas_cmd *cmds, int n_fd[2], int pr_fd[2], \
	t_one_cmd *cmd);
void		clean_mat_and_exit(char **paths);
void		update_env(void);

int			ft_strchr_up(const char *str, int to_find);
int			ft_strlen_up(char *str, char *search);
int			infile(char **all_cmd);
int			outfile(char **all_cmd);
int			count_cmd(char *argv[]);
int			find_builtin(t_one_cmd *cmd);
int			find_builtin_env(t_one_cmd *cmd);
int			check_builtin(t_one_cmd *cmd);
int			ft_open(t_one_cmd *cmd);
int			er(char *str, int error, int status);
int			search_forget(char *map, char forget);
int			check_map2(char **map);
int			check_map(char **map);
int			no_path(char **paths, char **cmd, t_one_cmd *c_stru, int to_ex);
int			add_to_env(char *s);

char		*find_in_env(char **envp, char *word, int len_return);
char		*find_in_struct(char *var_env, t_var_env *out);
char		*start_prompt(char **env);
char		*cpy_with_malloc(char *tmp);
char		*ft_getenv(char *var_name, t_var_env *list);
char		*ft_free_little_matrice(char **mat, int x);
char		*return_char(char *cmds, int y, t_var_env *out_struct);
char		*find_cmd_path(char **paths, t_one_cmd *c_stru, char **cmd);

char		**ft_first_cmd(char **all_cmds);
char		**free_no_place(int y, char **magic_word, char **tmp);
char		**one_word(t_datas_cmd *cmd, int x);
char		**conv_env_to_mat(void);
char		**get_path(char *env[]);
char		**pipen_t(char **cmds);
char		**modif_mat(char **cmds, t_var_env *out_struct);
char		**simple_mat(char **start_mat);
char		**conv_env_to_mat(void);
char		**ft_cpy_maic_word(t_datas_cmd *cmd, int x, int status);

t_datas_cmd	*gen_datas_cmd(char *x);
t_datas_cmd	*ft_free_no_place(t_datas_cmd *cmd);
t_datas_cmd	*ft_parsing(char *cmd_one_line, t_datas *datas_prompt);

t_one_cmd	*trans_cmd(char **cmds, int st, t_datas_cmd	*data_command);
t_one_cmd	*move_fd(t_one_cmd *cmd_first, int nb_escape, t_datas_cmd *all);

t_var_env	*conv_env(char **envp);
t_var_env	*ft_new_var_env(char *str, t_var_env *old_struct);
t_var_env	*ft_find_in_list(char *str, t_var_env *list);

#endif
