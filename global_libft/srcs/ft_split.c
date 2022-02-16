/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:57:03 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:57:05 by hgoorick         ###   ########.fr       */
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

char	**ft_clean(char **s, int i)
{
	while (i--)
		free(s[i]);
	return (0);
}

static int	nb_words(char const *s, char c)
{
	int	i;
	int	nb_words;
	int	lg_word;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] && (c == s[i]))
			i++;
		lg_word = 0;
		while (s[i + lg_word] && (c != s[i + lg_word]))
			lg_word++;
		if (lg_word)
			nb_words++;
		i += lg_word;
	}
	return (nb_words);
}

static char	**ft_split2(char const *s, char c, char **retour, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lg_word;

	i = 0;
	j = 0;
	while (i < nb)
	{
		while (s[j] && (c == s[j]))
			j++;
		lg_word = 0;
		while (s[j + lg_word] && (c != s[j + lg_word]))
			lg_word++;
		retour[i] = malloc(sizeof(char) * (lg_word + 1));
		if (!retour[i])
			return (ft_clean(retour, i));
		ft_strlcpy(retour[i], &s[j], lg_word + 1);
		j += lg_word;
		i++;
	}
	return (retour);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	nb_word;
	char			**retour;

	if (!s)
		return (0);
	nb_word = nb_words(s, c);
	retour = malloc(sizeof(char *) * (nb_word + 1));
	if (!retour)
		return (0);
	retour = ft_split2(s, c, retour, nb_word);
	if (!retour)
	{
		free(retour);
		return (0);
	}
	retour[nb_word] = 0;
	return (retour);
}
