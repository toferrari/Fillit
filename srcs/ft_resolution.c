/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:01:37 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/14 14:12:12 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	**ft_init(char **solution, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			solution[i][j] = '.';
			j++;
		}
		solution[i][j] = '\n';
		solution[i][j + 1] = '\0';
		i++;
	}
	return (solution);
}

int			ft_resolution(t_tetra *tetra, int nbtetra, int len, char **tab)
{
	char	**solution;
	int		i;

	i = 0;
	if (!(solution = (char**)malloc((len) * sizeof(char*))))
		return (0);
	while (i <= len)
	{
		if (!(solution[i] = (char *)malloc((len + 2) * sizeof(char))))
			return (0);
		i++;
	}
	solution = ft_init(solution, len);
	if (ft_try_tetra(nbtetra, solution, 0, tetra) == 0)
	{
		len++;
		tetra = ft_coor_tetra_zero_xy(ft_coor_tetra(tab, nbtetra), nbtetra, 0);
		ft_resolution(tetra, nbtetra, len, tab);
	}
	else
		ft_display(solution, len);
	return (1);
}
