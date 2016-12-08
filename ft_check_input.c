/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:50:35 by jthillar          #+#    #+#             */
/*   Updated: 2016/12/01 14:27:41 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h" 
#include <stdio.h>
int	ft_check_input(char *s, int i)
{
	int count;
	int j;
	int ligne;
	int diese;

	count = 0;
	ligne = 0;
	diese = 0;
	while (s[count])
		count++;
	if (count > 525)
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i + j] == '.' || s[i + j] == '#')
		{		
			if (s[i + j] == '#')
				diese++;
			j++;
		}
		if (s[i + j] == '\n' && j == 4)
			ligne++;
		else 
			return (0);
		if (ligne == 4 && s[i + j] == '\n' && s[i + j + 1] == '\n')
		{
			ligne = 0;
			if (diese != 4)
				return (0);
			diese = 0;
			i = i + j + 2;
		}
		else if (ligne == 4 && s[i + j] == '\n' && s[i + j + 1] == '\0')
		{
			if (diese != 4)
				return (0);
			i = i + j + 1;
		}
		else
			i = i + j + 1;
	}
	if (s[i - 2] == '.' || s[i - 2] == '#')
		return (1);
	else
		return (0);
}
