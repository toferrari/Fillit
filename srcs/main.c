/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:03:10 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/13 18:40:54 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int	ft_error_us(void)
{
	ft_putstr("usage : ./fillit source_file\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	char	**tetra;

	tetra = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd == -1)
		return (ft_error_us());
	ret = read(fd, buf, BUF_SIZE);
	tetra = ft_fill_tab(buf, tetra, 0, 0);
	if (ft_check_input(buf, 0) == 0 ||
	ft_check_tetra(tetra, 0, ft_count_tetra(buf)) == 0)
		return (ft_error());
	if (ft_resolution(ft_coor_tetra_zero_xy(ft_coor_tetra(tetra,
	ft_count_tetra(buf)), ft_count_tetra(buf), 0), ft_count_tetra(buf),
				ft_sqrt_up(ft_count_tetra(buf) * 4, 2), tetra) == 0)
		return (ft_error());
	return (0);
}
