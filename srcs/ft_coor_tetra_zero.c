/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor_tetra_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:02:42 by jthillar          #+#    #+#             */
/*   Updated: 2017/01/06 14:06:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_baze_zero(int *coor)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (coor[j] == 0)
			return (1);
		j++;
	}
	return (0);
}

t_tetra	*ft_coor_tetra_zero_x(t_tetra *tetra, int nbtetra, int i)
{
	int j;

	while (i < nbtetra)
	{
		if (ft_baze_zero(tetra[i].x) == 0)
		{
			while (ft_baze_zero(tetra[i].x) != 1)
			{
				j = 0;
				while (j < 4)
				{
					tetra[i].x[j] = tetra[i].x[j] - 1;
					j++;
				}
			}
		}
		i++;
	}
	return (tetra);
}

t_tetra	*ft_coor_tetra_zero_xy(t_tetra *tetra, int nbtetra, int i)
{
	int j;

	tetra = ft_coor_tetra_zero_x(tetra, nbtetra, i);
	while (i < nbtetra)
	{
		if (ft_baze_zero((tetra[i]).y) == 0)
		{
			while (ft_baze_zero((tetra[i]).y) != 1)
			{
				j = 0;
				while (j < 4)
				{
					(tetra[i]).y[j] = (tetra[i]).y[j] - 1;
					j++;
				}
			}
		}
		i++;
	}
	return (tetra);
}
