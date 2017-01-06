/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:31:05 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/06 14:05:53 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static t_tetra	*ft_modif_coor(t_tetra *coor)
{
	int i;

	i = 0;
	while (coor->x[0] != 0)
	{
		while (i < 4)
		{
			coor->x[i] -= 1;
			i++;
		}
		i = 0;
	}
	return (coor);
}

static int		ft_cut(int x, int y, t_tetra *coor, char **solu)
{
	int cmp;
	int len;

	cmp = 0;
	len = ft_strlen(solu[0]) - 1;
	while ((x + coor->x[cmp] < len && y + coor->y[cmp] < len) &&
	cmp < 4 && solu[y + coor->y[cmp]][x + coor->x[cmp]] == '.')
	{
		cmp++;
		if (x + coor->x[cmp] >= len && y + coor->y[cmp] >= len)
			cmp = 5;
	}
	if (cmp == 4)
		return (cmp);
	return (0);
}

int				ft_xy(int *coor_x, int *coor_y, char **solu, t_tetra *coor)
{
	int len;
	int x;
	int y;

	y = 0;
	len = ft_strlen(solu[0]) - 1;
	while ((y < len || x < len) && solu[y])
	{
		x = 0;
		while (x < len && solu[y][x])
		{
			if ((x + coor->x[0] < len && y + coor->y[0] < len)
			&& solu[y + coor->y[0]][x + coor->x[0]] == '.')
			{
				if (ft_cut(x, y, coor, solu) == 4)
				{
					ft_value(x, y, coor_x, coor_y);
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void		ft_zero(t_tetra *coor, int *x, int *y)
{
	int j;

	*x = coor->x[0] + 1;
	*y = coor->y[0];
	j = 0;
	while (ft_baze_zero(coor->x) != 1)
	{
		j = 0;
		while (j < 4)
		{
			coor->x[j] -= 1;
			j++;
		}
	}
	j = 0;
	while (ft_baze_zero(coor->y) != 1)
	{
		j = 0;
		while (j < 4)
		{
			coor->y[j] -= 1;
			j++;
		}
	}
}

void			*ft_check_xy2(int *cr_x, int *cr_y, char **s, t_tetra *coor)
{
	int tb[3];

	ft_zero(coor, &tb[1], &tb[2]);
	tb[0] = ft_strlen(s[0]) - 1;
	if (ft_is_l(coor) == 1)
		coor = ft_modif_coor(coor);
	while ((tb[2] < tb[0]) && s[tb[2]])
	{
		while (tb[1] <= tb[0] && (s[tb[2]][tb[1]] != '\n' && s[tb[2]][tb[1]]))
		{
			if (s[tb[2]][tb[1]] == '.')
			{
				if (ft_cut(tb[1], tb[2], coor, s) == 4)
				{
					ft_value(tb[1], tb[2], cr_x, cr_y);
					return (NULL);
				}
			}
			tb[1] += 1;
		}
		tb[2] += 1;
		tb[1] = 0;
	}
	ft_value(tb[0] + 1, tb[0] + 1, cr_x, cr_y);
	return (NULL);
}
