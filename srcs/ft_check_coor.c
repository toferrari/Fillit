/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:31:05 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/19 19:48:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "libft.h"

/*int		ft_check_coor_x(t_tetra *coor, int len)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (coor->x[j] + 1 > len)
			return (0);
		j++;
	}
	return (1);
}

int		ft_check_coor_y(t_tetra *coor, int len)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (coor->y[j] + 1 >= len)
			return (0);
		j++;
	}
	return (1);
}

int		ft_check_xy_plus1(int *coor_x, int *coor_y, char **solu, t_tetra *coor)
{
	int cmp;
	int len;

	cmp = 0;
	len = ft_strlen(solu[0]) - 1;
	while(*coor_y < len && *coor_x < len &&solu[*coor_y])
	{
		*coor_x = 0;
		while (solu[*coor_y][*coor_x])
		{
			if (solu[*coor_y + coor->y[cmp]][*coor_x + coor->x[cmp]] == '.')
			{
				ft_putstr(" abcisse :");
				ft_putnbr(*coor_x);
				ft_putchar('\n');
				ft_putstr(" ordonner :");
				ft_putnbr(*coor_y);
				ft_putchar('\n');
				cmp = 0;
				while (cmp < 4 && solu[*coor_y + coor->y[cmp]][*coor_x + coor->x[cmp]] == '.' )
				{ft_putstr(" x :");
				ft_putnbr(coor->x[cmp] + *coor_x);
				ft_putchar('\n');
				ft_putstr(" y :");
				ft_putnbr(coor->y[cmp] + *coor_y);
				ft_putchar('\n');
					cmp++;
				}
				ft_putendl("sorti de boucle");
				if (cmp == 4)
					return (1);
			}
			*coor_x += 1;
		}
		*coor_y += 1;
	}
	return (0);
}*/

int		ft_check_xy(int *coor_x, int *coor_y, char **solu, t_tetra *coor)
{
	int cmp;
	int len;
	int x;
	int y;

	x = 0;
	y = 0;
	cmp = 0;
	len = ft_strlen(solu[0]) - 1;
	/*ft_putstr("len : ");
	ft_putnbr(len - 1);
	ft_putchar('\n');*/
	while((y < len || x < len) && solu[y])
	{
		x = 0;
		while (x < len  && solu[y][x])
		{
			if ((x + coor->x[cmp] < len  && y + coor->y[cmp] < len)
			&& solu[y + coor->y[cmp]][x + coor->x[cmp]] == '.')
			{
				while ((x + coor->x[cmp] < len  && y + coor->y[cmp] < len) &&
				cmp < 4 && solu[y + coor->y[cmp]][x + coor->x[cmp]] == '.' )
				{
				ft_putstr(" coor tetra x :");
				ft_putnbr(coor->x[cmp]);
				ft_putchar('\n');
				ft_putstr("coor tetra y : :");
				ft_putnbr(coor->y[cmp]);
				ft_putchar('\n');
					ft_putstr("solution x :");
					ft_putnbr(coor->x[cmp] + x);
					ft_putchar('\n');
					ft_putstr("solution y :");
					ft_putnbr(coor->y[cmp] + y);
					ft_putchar('\n');
					cmp++;
					ft_putstr("valeur compteur :");
					ft_putnbr(cmp);
					ft_putchar('\n');
					if (x + coor->x[cmp] >= len && y + coor->y[cmp] >= len)
						cmp = 5;
				}
				if (cmp == 4)
				{
					*coor_x = x;
					*coor_y = y;
					return (1);
				}
				cmp = 0;
			}
			x++;
		}
		y++;
	}
	return (0);
}

void		ft_check_xy2(int *coor_x, int *coor_y, char **solu, t_tetra *coor)
{
	int cmp;
	int len;
	int x;
	int y;

	x = coor->x[0] + 1;
	y = coor->y[0];
	cmp = 0;
	len = ft_strlen(solu[0]) - 1;
	/*ft_putstr("len : ");
	ft_putnbr(len - 1);
	ft_putchar('\n');*/
	while((y < len && x < len) && solu[y])
	{
		while (x < len  && solu[y][x])
		{ft_putstr("y :");
		ft_putnbr(y);
		ft_putchar('\n');
			if ((x < len  && y< len)
			&& solu[y][x] == '.')
			{
				ft_putstr("x2 : ");
				ft_putnbr(x + coor->x[cmp]);
				ft_putchar('\n');
				while ((x + coor->x[cmp] < len  && y + coor->y[cmp] < len) &&
				cmp < 4 && solu[y + coor->y[cmp]][x + coor->x[cmp]] == '.' )
				{
					cmp++;
					if (x + coor->x[cmp] >= len && y + coor->y[cmp] >= len)
						cmp = 5;
				}
				if (cmp == 4)
				{
					*coor_x = x;
					*coor_y = y;
				}
				cmp = 0;
			}
			x++;
		}
		y++;
		x = 0 - len;
	}
	*coor_x = len;
	*coor_y = len;
}
