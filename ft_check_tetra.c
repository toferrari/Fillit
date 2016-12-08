/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:04:24 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/07 14:47:32 by tferrari         ###   ########.fr       */
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

/*int		ft_check_tetra(char **tetra, int i, int nbtetra);
char	**ft_fill_tab(char *s, char **tetra, int j, int k);
int		ft_count_tetra(char *c);
int		ft_count_char(char *s, char c);
int		ft_check_input(char *s, int i);
int		ft_check_piece(char **tetra, int x, int y, int c);
void	ft_coor_tetra(char **tab, char *c);
int	ft_putnbr(int j);

void ft_putchar(char c)
{
	write(1, &c, 1);
}

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
			ft_putnbr(y);
			ft_putchar(' ');
			ft_putnbr(k);
			ft_putchar(' ');
			ft_putnbr(i);
			ft_putchar('\n');
			if (ft_check_piece(tetra, k, y, i) < 4)
			{
				return (0);
			}
			i++;
		}
	}
	return (1);
}*/
/*
int main(void)
{
	char a[100] = "####\n....\n....\n....\n\n#...\n#...\n##..\n....\n\n....\n....\n..##\n..##\n";
	char **b;
	int i = 0;

	b = (ft_fill_tab(a, b, 0, 0));
	ft_putchar('a');
	printf("result :%d\n", ft_check_tetra(b, 0, 3));
	while (b[i] != NULL)
	{
		printf("%s", b[i]);
		i++;
	}
	printf("%s", b[i]);
	return(0);
}*/
