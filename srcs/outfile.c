/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:05:17 by hgoorick          #+#    #+#             */
/*   Updated: 2022/02/24 22:28:20 by mbucci           ###   ########.fr       */
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

int	open_fd(char *cmd, int stat)
{
	int	fd;

	fd = 0;
	if (stat)
		fd = open(cmd, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(cmd, O_CREAT | O_RDWR | O_TRUNC, 0644);
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

int	give_me_fd(char **all_cmd, int x)
{
	if (ft_strlen(all_cmd[x - 1]) > 1)
	{
		if (all_cmd[x - 1][1] == '>')
			return (open_fd(all_cmd[x], 1));
		else
			return (-1);
	}
	return (open_fd(all_cmd[x], 0));
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

int	outfile(char **all_cmd)
{
	int	x;
	int	fd;

	fd = 1;
	while (1)
	{
		if (fd > 1)
			all_cmd = &all_cmd[x];
		x = find_next_char(all_cmd, '>');
		if (x == ft_matrixlen(all_cmd))
			break ;
		else if (fd > 1)
			close(fd);
		x++;
		fd = give_me_fd(all_cmd, x);
		if (fd == -1)
			return (-1);
	}
	return (fd);
}
