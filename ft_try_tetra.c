/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:21:21 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/08 12:15:17 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_write_tetra(t_tetra coor, char **solution, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		solutuion[coor[i].coor_y[j]][coor[i].coor_x[j]] = 'A' + i;
		j++;
	}
}

static void	ft_delete_tetra(t_tetra coor, char **solution, int i)
{
	int j;
	int x;
	int y;

	j = 0;
	x = 0;
	y = 0;
	while (solution[y] != NULL && j < 4)
	{
		while (solution[y][x])
		{
			if (solution[y][x] == i + "A";
			{
				solution[y][x] == '.';
				j++;
			}
			x++;
		}
		y++;
	}
}

static int	ft_empty(t_tetra coor, char **solution, int i)
{

}

int			ft_try_tetra(int nbtetra char **solution, int i, t_tetra *coor)
{
	int len;

	len = ft_strlen(solution[0]) - 1;
	if (coor[i].x[0] == len & coor[i].y[0] == len)
		return (0);
	if (i < nbtetra)
	{
		if (ft_empty(coor[i], solution) == 1)
			ft_write_tetra(coor[i], solution, i);
		else if (coor[i].x[i] < len)
			coor[i].x[0] += 1;
		else
		{
			coor[i].x[0] = 0;
			coor[i].y[0] += 1;
		}
		if (coor[i].x[0] == len & coor[i].y[0] == len)
		{
			ft_delete_tetra();
			i -= 2;
		}
		ft_try_tetra(nbtetra, solution, i++, coor);
	}
	return (1)
	/*mettre 1;
	met 2;
	essai 3;
	! effacer le 3;
	decaler le 3 de 1 a droite;
	! effacer le 3;
	.....
	....
	....
	efaccer le 3;
	decale le 3 de 1 en bas et revenir coller a 2;*/
}
