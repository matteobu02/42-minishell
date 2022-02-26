/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   libft.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hgoorick <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/09/04 15:59:57 by hgoorick		  #+#	#+#			 */
/*   Updated: 2022/02/25 09:54:33 by hgoorick         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "includes.h"
# include "struct.h"

t_one_cmd	*ft_lstnb(t_one_cmd *cmd_first, int nb);

int			find_next_char(char **all_cmds, char c);
int			ft_isspace(char c);
int			ft_lstsize_up(t_var_env *lst);
int			ft_allisspace(char *str);
int			ft_strchr_up(const char *str, int to_find);
int			ft_atoi(const char *str);
int			ft_matrixlen(char **m);
int			ft_lstsize(t_one_cmd *lst);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_memcmp(const void *string1, const void *string2, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);

char		*get_next_line(int fd);
char		*ft_strchr(const char *str, int to_find);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strjoin_up(char *s1, char *s2);
char		*cpy_with_malloc(char *tmp);

char		**ft_split(char const *s, char c);
char		**ft_split_up(char const *s);
char		**ft_split_pipex(char const *s, char c);
char		**ft_clean(char **s, int i);
char		**ft_matrixlcpy(char **matrix_in, int nb_line);

size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t siz);
size_t		ft_strlcat(char *dst, const char *src, size_t siz);

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void		ft_putchar_fd(char c, int fd);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_bzero(void *pointer, size_t count);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *destination, const void *source, size_t size);
void		*ft_memmove(void *destination, const void *source, size_t size);
void		*ft_memset(void *pointer, int value, size_t count);
void		*ft_calloc(size_t count, size_t size);

#endif
