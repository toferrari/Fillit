/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:21:21 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/06 14:07:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static char	**ft_wri(t_tetra coor, char **solution, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		solution[coor.y[j]][coor.x[j]] = 'A' + i;
		j++;
	}
	return (solution);
}

static char	**ft_delete_tetra(char **solution, int i)
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

static int	ft_empty(t_tetra coor, char **solution, int *nb)
{
	int nb_coor;
	int len;

	nb_coor = 0;
	len = ft_strlen(solution[0]) - 1;
	while (nb_coor < 4)
	{
		if (coor.x[nb_coor] < 0 || coor.y[nb_coor] < 0
		|| coor.x[nb_coor] > len || coor.y[nb_coor] > len)
		{
			return (0);
		}
		else if (solution[coor.y[nb_coor]][coor.x[nb_coor]] != '.')
		{
			return (0);
		}
		nb_coor++;
	}
	*nb -= 1;
	return (1);
}

t_tetra		ft_cr(t_tetra coor, int x, int y)
{
	int j;

	j = 0;
	while (j < 4)
	{
		coor.x[j] += x;
		coor.y[j] += y;
		j++;
	}
	return (coor);
}

int			ft_try(int *nb, char **solu, int i, t_tetra *cr)
{
	int xy[2];

	xy[0] = 0;
	xy[1] = 0;
	if (nb[0] > 0 && i < nb[2])
	{
		if (i == 0 && ft_xy(&xy[0], &xy[1], solu, &cr[i]) == 0)
			return (0);
		if (i < nb[2] && ft_xy(&xy[0], &xy[1], solu, &cr[i]) == 0)
			return (1);
		if (i < nb[2] - 1 && nb[0] > 0 && ft_empty(cr[i], solu, &nb[0]) == 1)
			i += ft_try(nb, ft_wri(cr[i], solu, i), i + 1, cr);
		if (i < nb[2] && nb[0] > 0 && ft_xy(&xy[0], &xy[1], solu, &cr[i]) == 1)
			i += ft_try(ft_nb(nb),
			ft_wri(ft_cr(cr[i], xy[0], xy[1]), solu, i), i + 1, cr);
		if (i < nb[2] && nb[0] > 0 && ft_xy(&xy[0], &xy[1], solu, &cr[i]) == 0)
		{
			solu = ft_delete_tetra(solu, i - 1);
			ft_check_xy2(&xy[0], &xy[1], solu, &cr[i - 1]);
			ft_try(ft_nb2(nb), solu, i - 1, ft_modif_cr(cr, i, xy, nb[2]));
			if (ft_end(solu) == 0)
				return (0);
		}
	}
	return (1);
}
