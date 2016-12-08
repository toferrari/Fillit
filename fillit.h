/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:04:04 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/07 16:55:26 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#define BUF_SIZE 4096

typedef	struct	s_tetra
{
	int coorx[4];
	int coory[4];
}				t_tetra;

int		ft_check_tetra(char **tetra, int i, int nbtetra);
char	**ft_fill_tab(char *s, char **tetra, int j, int k);
int		ft_count_tetra(char *c);
int		ft_count_char(char *s, char c);
int		ft_check_input(char *s, int i);
int		ft_check_piece(char **tetra, int x, int y, int c);
t_tetra	*ft_coor_tetra(char **tab, int nbtetra);

#endif
