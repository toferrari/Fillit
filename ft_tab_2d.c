/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:00:55 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/01 17:40:43 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
void ft_putchar(char c);
int	ft_putnbr(int j);

static char	**ft_malloc_tab(int i, char **tetra, size_t len)
{
	if (!(tetra = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	while ((size_t)i < len + 1)
	{
		if (!(tetra[i] = (char *)malloc(6 * sizeof(char))))
			return (NULL);
		i++;
	}
	tetra[i] = NULL;
	return (tetra);
}

char	**ft_fill_tab(char *s, char **tetra, int j, int k)
{
	int i;

	i = 0;
	if (!(tetra = ft_malloc_tab(0, tetra, ft_count_char(s, '\n'))))
		return (NULL);
	while (s[i])
	{
		tetra[j][k] = s[i];
		if (s[i] == '\n')
		{
			k++;
			tetra[j][k] = '\0';
			j++;
			k = -1;
		}
		k++;
		i++;
	}
	return (tetra);
}
/*static char	**ft_malloc_tab(int i, char *s, char **tetra, size_t len)
{
	if (!(tetra = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	while ((size_t)i < len)
	{
		if (!(tetra[i] = (char *)malloc(6 * sizeof(char))))
			return (NULL);
		i++;
		printf("i = %d\n", i);
	}
	tetra[i] = NULL;
	return (tetra);
}

char	**ft_fill_tab(char *s, char **tetra, int j, int k)
{
	int i;

	i = 0;
	if (!(tetra = ft_malloc_tab(0, s, tetra, ft_count_char(s, '\n'))))
		return (NULL);
	while (s[i])
	{
		tetra[j][k] = s[i];
		if (s[i] == '\n')
		{
			k++;
			tetra[j][k] = '\0';
			j++;
			k = -1;
		}
		k++;
		i++;
	}

	return (tetra);
}*/
