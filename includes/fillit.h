/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:04:04 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/19 18:12:36 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 4096

typedef	struct	s_tetra
{
	int			x[4];
	int			y[4];
}				t_tetra;

int				ft_check_tetra(char **tetra, int i, int nbtetra);
char			**ft_fill_tab(char *s, char **tetra, int j, int k);
int				ft_count_tetra(char *c);
int				ft_count_char(char *s, char c);
int				ft_check_input(char *s, int i);
int				ft_check_piece(char **tetra, int x, int y, int c);
int				ft_cpx(char **tab, int x, int y, int i);
int				ft_cpy(char **tab, int x, int y, int i);
t_tetra			*ft_coor_tetra(char **tab, int nbtetra);
int				ft_baze_zero(int *coor);
t_tetra			*ft_coor_tetra_zero_x(t_tetra *t_te, int nbtetra, int i);
t_tetra			*ft_coor_tetra_zero_xy(t_tetra *t_te, int nbtetra, int i);
int				ft_try_tetra(int nbtetra, char **solu, int i, t_tetra *coor);
int				ft_resolution(t_tetra *tetra, int nbtetras, int len,
				char **tab);
int				ft_sqrt_up(int nb_square, int nb);
int				ft_check_xy(int *coor_x, int *coor_y, char **solu, t_tetra *coor);
void			ft_display(char **solution, int len);
void			ft_check_xy2(int *coor_x, int *coor_y, char **solu, t_tetra *coor);

#endif
