/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipen_t.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hgoorick <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/10 18:03:17 by hgoorick		  #+#	#+#			 */
/*   Updated: 2022/02/10 18:03:34 by hgoorick         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : pipen_t
*	Params : La matrice de toute la commande
*	Retour : La matrice de toute la commande sans |
*	Descritpion:
*		Parcourt la matrice en remplace le | par la ligne suivante de la matrice
*
****************************************/

char	**pipen_t(char **cmds)
{
	while (!find_next_char(cmds, '|'))
	{
		if (ft_matrixlen(cmds) > 1)
			cmds = &cmds[1];
		else
			return (NULL);
	}
	return (cmds);
}
