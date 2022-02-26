/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:57:03 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/10 18:48:15 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Allocate and return an array of strings obtained by separating 	*/
/*				's' from using the 'c' character, used as a delimiter.		*/
/*				The array must be terminated with NULL.						*/
/*																			*/
/*	Argument :																*/
/*			s	=>		The string of characters to cut.					*/
/*			c	=>		The delimiting character.							*/
/*																			*/
/*	Return :																*/
/*			The array of new strings, resulting from the splitting. 		*/
/*				NULL if the allocation fails.								*/
/* ************************************************************************ */

#include "libft.h"

static int	need_line(int status, int lg_world)
{
	if ((status && lg_world) || (!status && !lg_world))
		return (1);
	return (0);
}

static int	len_word(char const *s, int i)
{
	int	lg_word;
	int	status;

	lg_word = 0;
	status = 0;
	while (s[i + lg_word] && (!ft_isspace(s[i + lg_word]) || status))
	{
		if (s[i + lg_word] == '"' && status == 0)
			status = 1;
		else if (s[i + lg_word] == 39 && status == 0)
			status = 2;
		else if ((s[i + lg_word] == '"' || s[i + lg_word] == 39) && status)
			status = 0;
		if (!status && (s[i + lg_word] == '|' || s[i + lg_word] == '>'
				|| s[i + lg_word] == '<') && status == 0)
		{
			if (!status && (s[i + lg_word] == s[i + lg_word + 1]))
				lg_word += need_line(status, lg_word) * 2;
			else
				lg_word += need_line(status, lg_word);
			break ;
		}
		lg_word++;
	}
	return (lg_word);
}

static int	nb_words(char const *s)
{
	int	i;
	int	nb_words;
	int	lg_word;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] && (ft_isspace(s[i])))
			i++;
		lg_word = len_word(s, i);
		if (lg_word)
			nb_words++;
		i += lg_word;
	}
	return (nb_words);
}

static char	**ft_split2(char const *s, char **retour, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lg_word;

	i = 0;
	j = 0;
	while (i < nb)
	{
		while (s[j] && (ft_isspace(s[j])))
			j++;
		lg_word = len_word(s, j);
		retour[i] = malloc(sizeof(char) * (lg_word + 1));
		if (!retour[i])
			return (ft_clean(retour, i));
		ft_strlcpy(retour[i], &s[j], lg_word);
		j += lg_word;
		i++;
	}
	return (retour);
}

char	**ft_split_up(char const *s)
{
	unsigned int	nb_word;
	char			**retour;

	if (!s)
		return (0);
	nb_word = nb_words(s);
	retour = malloc(sizeof(char *) * (nb_word + 1));
	if (!retour)
		return (0);
	retour = ft_split2(s, retour, nb_word);
	if (!retour)
	{
		free(retour);
		return (0);
	}
	retour[nb_word] = 0;
	return (retour);
}
