/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:04:24 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/22 15:07:20 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

int		ft_check_tetra(char **tetra, int i, int nbtetra)
{
	int		y;
	int		k;

	y = 0;
	k = 0;
	while (i < nbtetra)
	{
		while (tetra[y][k] != '#' && tetra[y][k])
			k++;
		if (tetra[y][k] == '\0')
		{
			k = 0;
			y++;
		}
		if (tetra[y][k] == '#')
		{
			if (ft_check_piece(tetra, k, y, i) < 4)
				return (0);
			i++;
		}
	}
	return (1);
}
