/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   simple_mat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hgoorick <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/10 18:00:06 by hgoorick		  #+#	#+#			 */
/*   Updated: 2022/02/10 18:02:37 by hgoorick         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : nb_erase
*	Params : - Matrice de char a parcourir
*			 - Caractere a compter
*	Retour : Nombre de fois que le caractere est present
*	Descritpion:
*		Le code va parcourir la matrice en comptant le nombre d'iteration du
*			caractere
*
****************************************/

int	nb_erase(char **tmp, char try)
{
	int	nb_erase;
	int	x;

	nb_erase = 0;
	x = 0;
	while (1)
	{
		if (x >= ft_matrixlen(tmp))
			break ;
		tmp = &tmp[x];
		x = find_next_char(tmp, try);
		x++;
		nb_erase++;
	}
	return (nb_erase);
}

/****************************************
*
*	Nom : cpy_with_malloc
*	Params : La liste de char a copier
*	Retour : La liste de char copiee
*	Descritpion:
*		Copie une chaine avant de la retourner
*
****************************************/

char	*cpy_with_malloc(char *tmp)
{
	char	*out;

	out = malloc(sizeof(char) * ft_strlen(tmp) + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, tmp, ft_strlen(tmp));
	return (out);
}

/****************************************
*
*	Nom : ft_clean_mat
*	Params : La matrcie de commande
*	Retour : Void
*	Descritpion:
*		Free toute la matrice et le pointeur de la matrice
*
****************************************/

void	ft_clean_mat(char **mat)
{
	int	x;

	x = ft_matrixlen(mat);
	while (--x > -1)
		free(mat[x]);
	free(mat);
}

/****************************************
*
*	Nom : simple_mat
*	Params : La matrice de commande
*	Retour : La matrice de commande simplifiee
*	Descritpion:
*		Simplifie la commande pour ne laisser que les commandes et les
*			parametres
*
****************************************/

char	**simple_mat(char **start_mat)
{
	char	**final_mat;
	int		y;
	int		x;

	final_mat = malloc(sizeof(char *) * ft_matrixlen(start_mat) - \
		((nb_erase(start_mat, '>') + nb_erase(start_mat, '<')) * 2) + 1);
	if (!final_mat)
		return (NULL); //free all
	x = -1;
	y = -1;
	while (++x < ft_matrixlen(start_mat))
	{
		if (x < ft_matrixlen(start_mat))
		{
			if (start_mat[x][0] == '<' || start_mat[x][0] == '>')
				x++;
			else
			{
				final_mat[++y] = cpy_with_malloc(start_mat[x]);
				if (!final_mat[y])
				{
					ft_clean_mat(final_mat);
					ft_clean_mat(start_mat);
					return (NULL);
				}
			}

		}
		else
		{
			final_mat[++y] = cpy_with_malloc(start_mat[x]);
			if (!final_mat[y])
			{
				ft_clean_mat(final_mat);
				ft_clean_mat(start_mat);
				return (NULL);
			}
		}

	}
	final_mat[++y] = NULL;
	ft_clean_mat(start_mat);
	return (final_mat);
}
