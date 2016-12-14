/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:21:21 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/14 16:28:58 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static char		**ft_write_tetra(t_tetra *coor, char **solution, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		solution[coor[i].y[j]][coor[i].x[j]] = 'A' + i;
		j++;
	}
	return (solution);
}

static char		**ft_delete_tetra(char **solution, int i)
{
	int x;
	int y;
	int j;

	x = 0;
	y = 0;
	j = 0;
	while (solution[y] && j < 4)
	{
		x = 0;
		while (solution[y][x] && j < 4)
		{
			if (solution[y][x] == 'A' + i)
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

static int		ft_empty(t_tetra *coor, char **solution, int i, int len)
{
	int nb_coor;

	nb_coor = 0;
	while (nb_coor < 4)
	{
		if (coor[i].x[nb_coor] < 0 || coor[i].y[nb_coor] < 0
		|| coor[i].x[nb_coor] > len || coor[i].y[nb_coor] > len)
		{
			return (0);
		}
		else if (solution[coor[i].y[nb_coor]][coor[i].x[nb_coor]] != '.')
		{
			return (0);
		}
		nb_coor++;
	}
	return (1);
}

static t_tetra	*ft_new_coor(t_tetra *coor, int i, int pos, int len)
{
	int j;

	j = 0;
	if (pos == 1)
	{
		while (j < 4)
		{
			coor[i].x[j] += 1;
			j++;
		}
	}
	if (pos == 2)
	{
		while (j < 4)
		{
			coor[i].x[j] -= len - 1;
			coor[i].y[j] += 1;
			j++;
		}
	}
	return (coor);
}

int				ft_try_tetra(int nbtetra, char **solu, int i, t_tetra *coor)
{
	int len;

	len = ft_strlen(solu[0]) - 1;
	if (i < nbtetra)
	{
		if (ft_empty(coor, solu, i, len) == 1)
			ft_try_tetra(nbtetra, ft_write_tetra(coor, solu, i), i + 1, coor);
		else if (ft_check_coor_x(coor, len, i) == 1)
			{coor = ft_new_coor(coor, i, 1, len);
			ft_try_tetra(nbtetra, solu, i, coor);}
		else if (ft_check_coor_y(coor, len, i) == 1)
			{coor = ft_new_coor(coor, i, 2, len);
			ft_try_tetra(nbtetra, solu, i, coor);}
		else if (i > 0)
		{
			solu = ft_delete_tetra(solu, i - 1);
			coor = ft_new_coor(coor, i - 1, 1, len);
			coor = ft_coor_tetra_zero_xy(coor, nbtetra, i);
			i -= 2;
			ft_try_tetra(nbtetra, solu, ++i, coor);
		}
	}
	if (ft_check_coor_x(coor, len, 0) == 0)
		return (0);
	return (1);
}
