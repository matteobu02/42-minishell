/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:52:50 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/04 15:52:51 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The isdigit() function checks whether a character is numeric	*/
/*				character (0-9) or not.										*/
/*																			*/
/*	Argument :																*/
/*			Function isdigit() takes a single argument in the form of 		*/
/*				an integer and returns the value of type int.				*/
/*																			*/
/*	Return :																*/
/*			Non-zero int ( x > 0 )	=>	Argument is a numeric character.	*/
/*			Zero (0)				=>	Argument is not a numeric character.*/
/* ************************************************************************ */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
