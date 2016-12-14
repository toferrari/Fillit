/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:31:05 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/13 17:41:47 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		ft_check_coor_x(t_tetra *coor, int len, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (coor[i].x[j] + 1 > len)
			return (0);
		j++;
	}
	return (1);
}

int		ft_check_coor_y(t_tetra *coor, int len, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (coor[i].y[j] + 1 >= len)
			return (0);
		j++;
	}
	return (1);
}
