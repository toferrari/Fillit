/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:23:35 by jthillar          #+#    #+#             */
/*   Updated: 2016/12/13 16:50:57 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetra(char *c)
{
	int count_i;
	int count;

	count_i = 0;
	while (c[count_i])
		count_i++;
	count = (count_i + 1) / 21;
	return (count);
}
