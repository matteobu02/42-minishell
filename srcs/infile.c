/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:34:26 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/24 22:27:46 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/****************************************
*
*	Nom : open_fd
*	Params : - Liste de char relatif au nom de fichier a ouvrir
*			 - Le status (1 si on doit ajouter, 0 si on doit ecrire par dessus)
*	Retour : Le fd du outfile
*	Descritpion:
*		Essaye d'ouvrir le fichier donne, si l'ouverture ne marche pas il
*			affiche un message d'erreur
*
****************************************/

int	open_fd_infile(char *cmd)
{
	int	fd;

	fd = open(cmd, O_RDONLY);
	if (fd <= 0)
		return (-1);
	return (fd);
}

/****************************************
*
*	Nom : give_me_fd
*	Params : - La matrice de toute la commande
*			 - L'index dans la matrice
*	Retour : Le fd du outfile
*	Descritpion:
*		Regarde si il y a > ou >> pour changer le type donne a open_fd
*
****************************************/

int	give_me_fd_infile(char **all_cmd, int x)
{
	if (ft_strlen(all_cmd[x - 1]) > 1)
	{
		if (all_cmd[x - 1][1] == '<')
			return (0);
		else
			return (-1);
	}
	return (open_fd_infile(all_cmd[x]));
}

/****************************************
*
*	Nom : outfile
*	Params : - La matrice de toute la commande
*	Retour : Le fd du outfile
*	Descritpion:
*		Parcourt la matrice a la recherche de > si il en trouve alors le fd sera
*			adpate ou sinon fd sera a 1, si il y a plusieurs fd, ils seront
*			ouverts et fermes de sorte que seul le dernier fd restera ouvert
*			pour outfile
*
****************************************/

int	infile(char **all_cmd)
{
	int	x;
	int	fd;

	fd = 0;
	while (1)
	{
		if (fd > 1)
			all_cmd = &all_cmd[x];
		x = find_next_char(all_cmd, '<');
		if (x == ft_matrixlen(all_cmd) || (ft_strlen(all_cmd[x]) == 2
				&& all_cmd[x][1] == '<'))
			break ;
		else if (fd > 1)
			close(fd);
		if (x == ft_matrixlen(all_cmd) - 1)
			return (-1);
		x++;
		fd = give_me_fd_infile(all_cmd, x);
		if (fd == -1)
			return (-1);
	}
	return (fd);
}
