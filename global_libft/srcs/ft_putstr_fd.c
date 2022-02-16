/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:56:44 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:56:46 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Write the string 's' to the file descriptor given.				*/
/*																			*/
/*	Argument :																*/
/*			str		=>		The string of characters to write.				*/
/*																			*/
/*			fd		=>		The file descriptor to write to.				*/
/*																			*/
/*	Return :																*/
/*			None.															*/
/* ************************************************************************ */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}
