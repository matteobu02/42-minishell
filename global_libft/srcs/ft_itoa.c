/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:45:32 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:53:15 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The itoa() function constructs a string representation of 		*/
/*				an integer.													*/
/*																			*/
/*	Argument :																*/
/*			value 	=>	Is the integer to be converted to string 			*/
/*							representation.									*/
/*																			*/
/*	Return :																*/
/*			The function itoa() always returns the value string.			*/
/*				There is no error return.									*/
/* ************************************************************************ */

#include "libft.h"

static char	*zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = 48;
	str[1] = '\0';
	return (str);
}

static int	str_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		i++;
	while (nbr / 10 != 0 && i++ < 10)
		nbr /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	len = str_len(n) + 1;
	if (n == 0)
		return (zero());
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	nb = n;
	str[len] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb)
	{
		str[--len] = (nb % 10 + 48);
		nb /= 10;
	}
	return (str);
}
