/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:49:31 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/06 12:28:13 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :  															*/
/*			It converts the string argument str to an integer.				*/
/*																			*/
/*	Argument :																*/
/*			This is the string representation of an integral number.		*/
/*																			*/
/*	Return :																*/
/*			This function returns the converted integral number as 			*/
/*				an int value.												*/
/*			If no valid conversion could be performed, it returns zero.		*/
/* ************************************************************************ */

#include "libft.h"

static int	test(long long num, const char *str, int sign)
{
	long long	limit;

	limit = ((num * 10) + (*str - '0')) * sign;
	if (limit < -2147483648)
		return (0);
	if (limit > 2147483647)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned int	rep;
	int				sign;
	int				i;

	rep = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	i--;
	while (ft_isdigit(str[++i]))
	{
		if (!test(rep, &str[i], sign))
			return (0);
		if (test(rep, &str[i], sign) == -1)
			return (-1);
		rep = (rep * 10) + (str[i] - 48);
	}
	return (rep * sign);
}
