/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:50:35 by jthillar          #+#    #+#             */
/*   Updated: 2017/01/06 12:47:41 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_count_max(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (i > 525)
		return (0);
	else
		return (1);
}

int	ft_check_square(char *s, int i)
{
	int diese;
	int ligne;
	int j;

	ligne = 0;
	diese = 0;
	while (s[i] || ligne < 5)
	{
		j = 0;
		while (s[i + j] == '.' || s[i + j] == '#')
			if (s[i + j++] == '#')
				diese++;
		if (ligne == 4 && diese == 4)
			return (1);
		if (s[i + j] == '\n' && j == 4)
		{
			ligne++;
			i = i + 5;
		}
		else
			return (0);
	}
	return (0);
}

int	ft_check_input(char *s, int i)
{
	if (ft_count_max(s) == 0)
		return (0);
	while (s[i])
	{
		if (ft_check_square(s, i) == 0)
			return (0);
		else
		{
			if (s[i + 19] == '\n' && s[i + 20] == '\n')
				i = i + 21;
			else
				i = i + 20;
		}
	}
	if (s[i - 2] == '.' || s[i - 2] == '#')
		return (1);
	return (0);
}
