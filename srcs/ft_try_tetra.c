/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:21:21 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/22 18:20:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static char		**ft_write_tetra(t_tetra coor, char **solution, int i)
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

static int		ft_empty(t_tetra coor, char **solution, int len)
{
	int nb_coor;

	nb_coor = 0;
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
	return (1);
}

t_tetra	ft_new_coor(t_tetra coor, int x, int y)
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

static int ft_end(char **solu, int len)
{
	int x;
	int y;

	y = 0;
	while (y < len)
	{
		x = 0;
		while (x < len)
		{
			if (solu[y][x] == 'A')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int				ft_try_tetra(int *nbtetra, char **solu, int i, t_tetra *coor)
{
	int len;
	int x;
	int y;

	len = ft_strlen(solu[0]) - 1;
	x = 0;
	y = 0;
	/*int j = 0;
	while (j < len)
	{
		ft_putstr(solu[j]);
		j++;
	}
	ft_putchar('\n');

	ft_putstr("nbtetra : ");
	ft_putnbr(nbtetra[0]);
	ft_putchar('\n');
	ft_putstr("i = ");
	ft_putnbr(i);
	ft_putchar('\n');*/
	if (nbtetra[0] > 0 && i < nbtetra[2])
	{
		if (i < nbtetra[2] && ft_check_xy(&x, &y, solu, &coor[i]) == 0)
			return (1);
		/*ft_putstr("j'essai de placer la piece ");
		ft_putchar('A' + i);
		ft_putstr(" : ");
		ft_putchar('\n');*/
		/*ft_putnbr(i);
		ft_putchar('\n');*/

		if (i < nbtetra[2] - 1 && nbtetra[0] > 0 && ft_empty(coor[i], solu, len) == 1)
		{
			nbtetra[0] -= 1;
			i += ft_try_tetra(nbtetra, ft_write_tetra(coor[i], solu, i), i + 1, coor);
		}
		if (i < nbtetra[2] && nbtetra[0] > 0  && ft_check_xy(&x, &y, solu, &coor[i]) == 1)
		{
			coor[i] = ft_new_coor(coor[i], x, y);
			nbtetra[0] -= 1;
			i += ft_try_tetra(nbtetra, ft_write_tetra(coor[i], solu, i), i + 1, coor);
		}
		if (i < nbtetra[2] && nbtetra[0] > 0  && ft_check_xy(&x, &y, solu, &coor[i]) == 0)
		{
			solu = ft_delete_tetra(solu, i - 1);
			/*ft_putstr("je change les cordonne de la piece ");
			ft_putchar('A' + i - 1);
			ft_putstr(" : ");
			ft_putchar('\n');*/
			ft_check_xy2(&x, &y , solu, &coor[i - 1]);
			coor[i - 1] =  ft_new_coor(coor[i - 1], x, y);
			coor = ft_coor_tetra_zero_xy(coor, nbtetra[0], i);
			i--;
			nbtetra[0] += 1;
			ft_try_tetra(nbtetra, solu, i,  coor);

			if (ft_end(solu, len) == 0)
				{return (0);}
		}
	}
	return (1);
}
