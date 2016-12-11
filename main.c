/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:03:10 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/09 18:02:37 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

static int	ft_write_error(int i)
{
	ft_putchar('A' + i);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	char	**tetra;
	t_tetra	*coor;

	tetra = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd == -1)
		return(ft_write_error(0));
	ft_putstr("a\n");
	ret = read(fd, buf, BUF_SIZE);
	ft_putstr("b\n");
	tetra = ft_fill_tab(buf, tetra, 0, 0);
	ft_putstr("c\n");
	if (ft_check_input(buf, 0) == 0)
		return (ft_write_error(1));
	ft_putstr("d\n");
	if (ft_check_tetra(tetra, 0, ft_count_tetra(buf)) == 0)
		return (ft_write_error(2));
	ft_putstr("e\n");
	coor = ft_coor_tetra_zero_xy(ft_coor_tetra(tetra, ft_count_tetra(buf)), ft_count_tetra(buf));
	ft_putstr("f\n");
	printf("x = %d\n", coor[1].x[0]);
	printf("y = %d\n", coor[1].y[0]);
	printf("x = %d\n", coor[1].x[1]);
	printf("y = %d\n", coor[1].y[1]);
	if (ft_resolution(coor, ft_count_tetra(buf), ft_sqrt_up(ft_count_tetra(buf) * 4, 2)) == NULL)
		return (ft_write_error(3));
	ft_putstr("g\n");
	return (0);
}
