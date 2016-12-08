/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:20:32 by jthillar          #+#    #+#             */
/*   Updated: 2016/12/07 17:05:35 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>



static int	ft_coor_point_x(char **tab, int x, int y)
{
	int coor_x;

	coor_x = 0;
	while (tab[y])
	{
		while (tab[y][x] != '#' && tab[y][x])
		x++;
		if (tab[y][x] == '#')
		{
			coor_x = x;
			return (coor_x);
		}
		if (tab[y][x] =='\0')
		{
			x = 0;
			y++;
		}
	}
	return (0);
}
static int	ft_coor_point_y(char **tab, int x, int y)
{
	int coor_y;

	coor_y = 0;
	while (tab[y])
	{
		while (tab[y][x] != '#' && tab[y][x])
			x++;
		if (tab[y][x] == '#')
		{
			coor_y = y;
			return (coor_y);
		}
		if (tab[y][x] =='\0')
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
	t_tetra *t_tetra;

	i = 0;
	y = 0;
	x = 0;
	if(!(t_tetra = (struct s_tetra*)malloc(sizeof(t_tetra) * nbtetra)))
		return (NULL);
	while (i < nbtetra && tab[y][x])
	{
		t_tetra[i].coor1[0] = ft_coor_point_x(tab, x, y);
		t_tetra[i].coor1[1] = ft_coor_point_y(tab, x, y);
		x = t_tetra[i].coor1[0] + 1;
		y = t_tetra[i].coor1[1];
		printf("%d %d\n", t_tetra[i].coor1[0], t_tetra[i].coor1[1]);

		t_tetra[i].coor2[0] = ft_coor_point_x(tab, x, y);
		t_tetra[i].coor2[1] = ft_coor_point_y(tab, x, y);
		x = t_tetra[i].coor2[0] + 1;
		y = t_tetra[i].coor2[1];

		printf("%d %d\n", t_tetra[i].coor2[0], t_tetra[i].coor2[1]);

		t_tetra[i].coor3[0] = ft_coor_point_x(tab, x, y);
		t_tetra[i].coor3[1] = ft_coor_point_y(tab, x, y);
		x = t_tetra[i].coor3[0] + 1;
		y = t_tetra[i].coor3[1];

		printf("%d %d\n", t_tetra[i].coor3[0], t_tetra[i].coor3[1]);

		t_tetra[i].coor4[0] = ft_coor_point_x(tab, x, y);
		t_tetra[i].coor4[1] = ft_coor_point_y(tab, x, y);

		printf("%d %d\n", t_tetra[i].coor4[0], t_tetra[i].coor4[1]);

		x = 0;
		y = (i + 1) * 5;
		i++;
	}
	return (t_tetra);
}
