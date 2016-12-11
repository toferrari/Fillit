/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:21:21 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/09 16:27:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static char	**ft_write_tetra(t_tetra *coor, char **solution, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		solution[coor[i].y[j]][coor[i].x[j]] = 'A' + i;
		printf("x = %d\n", coor[i].x[j]);
		printf("y = %d\n", coor[i].y[j]);
		j++;
	}
	return (solution);
}

static char	**ft_delete_tetra(char **solution, int i)
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
			if (solution[y][x] == i + 'A')
			{
				solution[y][x] = '.';
				j++;
			}
			x++;
		}
		y++;
	}
	return (solution);
}

static int		ft_empty(t_tetra coor, char **solution)
{
	int nb_coor;

	nb_coor = 0;
	while (nb_coor < 4)
	{
		if (solution[coor.y[nb_coor]][coor.x[nb_coor]] != '.')
			return (0);
		nb_coor++;
	}
	return (1);
}

static t_tetra	*ft_new_coor(t_tetra *coor, int i, int pos)
{
	int j;

	j = 0;
	if (pos == 1)
	{
		while ( j < 4)
		{
			coor[i].x[j] += 1;
			j++;
		}
	}
	if (pos == 2)
	{
		while (j < 4)
		{
			coor[i].x[j] -= 4;
			coor[i].y[j] += 1;
			j++;
		}
	}
	return (coor);
}

int			ft_try_tetra(int nbtetra, char **solution, int i, t_tetra *coor)
{
	int len;

	len = ft_strlen(solution[0]) - 1;
	printf("%s", solution[0]);
	printf("%s", solution[1]);
	printf("%s", solution[2]);
	printf("%s", solution[3]);
	if (coor[i].x[0] == len & coor[i].y[0] == len)
		return (0);
	if (i < nbtetra)
	{
		if (ft_empty(coor[i], solution) == 1)
			solution = ft_write_tetra(coor, solution, i);
		else if (coor[i].x[i] < len)
		{
			coor = ft_new_coor(coor, i, 1);
			ft_try_tetra(nbtetra, solution, i, coor);
		}
		else
		{
			coor = ft_new_coor(&coor[i], i, 2);
			ft_try_tetra(nbtetra, solution, i, coor);
		}
		if (coor[i].x[0] == len & coor[i].y[0] == len)
		{
			solution = ft_delete_tetra(solution, i - 1);
			i -= 1;
		}
		ft_try_tetra(nbtetra, solution, ++i, coor);
	}
	return (1);
}
