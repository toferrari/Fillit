/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:17:38 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/01 18:15:56 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_piece(char **tetra, int x, int y, int c)
{
	int nb;

	nb = 1; // AJOUT DE JULIEN
	if (tetra[y][x] != '#')
		return (0);
	nb++;
	tetra[y][x] = c + 'A';
	nb += ft_check_piece(tetra, x + 1, y, c);
	nb += ft_check_piece(tetra, x, y + 1, c);
	if (x > 0)
		nb += ft_check_piece(tetra, x - 1, y , c);
	return (nb);
}

/*int		ft_check_piece(char **tetra, int x, int y, int c)
{
	int nb;

	if (tetra[y][x] != '#')
		return (0);
	nb++;
	tetra[y][x] = c + 'A';
	nb += ft_check_piece(tetra, x + 1, y, c);
	nb += ft_check_piece(tetra, x, y + 1, c);
	if (x > 0)
		nb += ft_check_piece(tetra, x - 1, y , c);
	return (nb);
}*/
