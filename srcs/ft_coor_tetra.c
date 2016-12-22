/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:20:32 by jthillar          #+#    #+#             */
/*   Updated: 2016/12/22 15:06:20 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		ft_cpx(char **tab, int x, int y, int i)
{
	int coor_x;

	coor_x = 0;
	while (tab[y])
	{
		while (tab[y][x] != 'A' + i && tab[y][x])
		{
			x++;
		}
		if (tab[y][x] == 'A' + i)
		{
			coor_x = x;
			return (coor_x);
		}
		if (tab[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	return (0);
}

int		ft_cpy(char **tab, int x, int y, int i)
{
	int coor_y;

	coor_y = 0;
	while (tab[y])
	{
		while (tab[y][x] != 'A' + i && tab[y][x])
			x++;
		if (tab[y][x] == 'A' + i)
		{
			coor_y = y - (i * 5);
			return (coor_y);
		}
		if (tab[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	return (0);
}

t_tetra	*ft_coor_tetra(char **tab, int nbtetra)
{
	int		x;
	int		y;
	int		i;
	t_tetra	*t_te;

	i = 0;
	y = 0;
	x = 0;
	if (!(t_te = (struct s_tetra*)malloc(sizeof(*t_te) * nbtetra)))
		return (NULL);
	while (i < nbtetra && tab[y][x])
	{
		t_te[i].x[0] = ft_cpx(tab, x, y, i);
		t_te[i].y[0] = ft_cpy(tab, x, y, i);
		t_te[i].x[1] = ft_cpx(tab, t_te[i].x[0] + 1, t_te[i].y[0] + (i * 5), i);
		t_te[i].y[1] = ft_cpy(tab, t_te[i].x[0] + 1, t_te[i].y[0] + (i * 5), i);
		t_te[i].x[2] = ft_cpx(tab, t_te[i].x[1] + 1, t_te[i].y[1] + (i * 5), i);
		t_te[i].y[2] = ft_cpy(tab, t_te[i].x[1] + 1, t_te[i].y[1] + (i * 5), i);
		t_te[i].x[3] = ft_cpx(tab, t_te[i].x[2] + 1, t_te[i].y[2] + (i * 5), i);
		t_te[i].y[3] = ft_cpy(tab, t_te[i].x[2] + 1, t_te[i].y[2] + (i * 5), i);
		x = 0;
		y = (i + 1) * 5;
		i++;
	}
	return (t_te);
}
