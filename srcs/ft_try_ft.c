/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:15:19 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/06 14:07:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_end(char **solu)
{
	int x;
	int y;
	int len;

	y = 0;
	len = ft_strlen(solu[0]) - 1;
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

int		*ft_nb(int *nb)
{
	nb[0] -= 1;
	return (nb);
}

int		*ft_nb2(int *nb)
{
	nb[0] += 1;
	return (nb);
}

t_tetra	*ft_modif_cr(t_tetra *cr, int i, int *xy, int nb)
{
	cr[i - 1] = ft_cr(cr[i - 1], xy[0], xy[1]);
	cr = ft_coor_tetra_zero_xy(cr, nb, i);
	return (cr);
}
