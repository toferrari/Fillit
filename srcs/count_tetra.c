/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:23:35 by jthillar          #+#    #+#             */
/*   Updated: 2016/12/13 16:47:18 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_tetra(char *c)
{
	int count_i;
	int count;

	count_i = 0;
	while (c[count_i])
		count_i++;
	count = (count_i + 1) / 21;
	return (count);
}
