/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:48:51 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/06 14:06:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	ft_sqrt_up(int nb_square, int nb)
{
	if (nb * nb >= nb_square)
		return (nb);
	else
		nb = ft_sqrt_up(nb_square, ++nb);
	return (nb);
}
