/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:03:10 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/07 17:06:06 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	char	**tetra;
	t_tetra	coor;

	i = 0;
	tetra = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd == - 1)
	{
		ft_putendl("error");
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	tetra = ft_fill_tab(buf, tetra, 0, 0);
	printf("ft_check_input : %d\n", ft_check_input(buf, 0));
//	printf("ft_fill_tab : %d", ft_fill_tab(buf, tetra, 0, 0));
	printf("ft_count_tetra : %d\n", ft_count_tetra(buf));
	printf("ft_check_tetra : %d\n", ft_check_tetra(tetra, 0, ft_count_tetra(buf)));

	if (ft_check_input(buf, 0) == 0 && !(tetra = ft_fill_tab(buf, tetra, 0, 0))
	&& ft_check_tetra(tetra, 0, ft_count_tetra(buf)) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	coor = ft_coor_tetra(tetra, ft_count_tetra(buf));
	ft_resolution(tetra, ft_count_tetra(buf), ft_sqrt_up(nbtetra * 4, 0));
	return (0);
}
