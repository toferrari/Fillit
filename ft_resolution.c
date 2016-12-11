/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:01:37 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/09 16:05:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

void		*ft_putstr( char *c);

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
		i++;
	}
	return (solution);
}

void		*ft_resolution(t_tetra *tetra, int nbtetra, int len)
{
	char	**solution;
	int		i;

	ft_putstr("i\n");
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
	ft_putstr("j\n");
	if (ft_try_tetra(nbtetra, solution, 0, tetra) == 0)
		ft_resolution(tetra, nbtetra, len++);
	return(0);
	//ft_display_solution(solution);
}
