/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:05:28 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/25 10:05:31 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**free_no_place(int y, char **magic_word, char **tmp)
{
	while (--y >= 0)
		free(magic_word[y]);
	free(magic_word);
	ft_clean_mat(tmp);
	return (NULL);
}
