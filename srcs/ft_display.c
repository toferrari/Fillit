/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:15:42 by jthillar          #+#    #+#             */
/*   Updated: 2016/12/14 14:03:03 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_display(char **solution, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putstr(solution[i]);
		i++;
	}
}
