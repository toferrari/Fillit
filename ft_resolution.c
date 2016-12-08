/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:01:37 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/07 16:22:09 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_putstr( char *c);

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
		solution[i][j+1] = '\0';
		ft_putstr(solution[i]);
		i++;
	}
	return (solution);
}

char	**ft_resolution(/*char **tetra, int nbtetra,*/ int len)
{
	char	**solution;
	int		i;

	i = 0;
	if (!(solution = (char**)malloc((len) * sizeof(char*))))
		return (NULL);
	while (i <= len)
	{
		if (!(solution[i] = (char*)malloc((len + 2) * sizeof(char))))
			return (NULL);
		i++;
	}
	solution[i] = NULL;
	solution = ft_init(solution, len);
	//if (ft_try_tetra(tetra, solution) == 0)
	//	ft_resolution(tetra, nbtetra, len++);
//	ft_display_solution(solution);
	return (solution);
}
