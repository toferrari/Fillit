/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chech_coor_ft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:42:23 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/06 14:05:29 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_is_l(t_tetra *coor)
{
	if (coor->x[0] > 0)
		return (1);
	return (0);
}

void	ft_value(int x, int y, int *cx, int *cy)
{
	*cx = x;
	*cy = y;
}
