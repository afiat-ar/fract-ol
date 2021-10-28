/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:34:45 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/28 12:21:24 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./minilibx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "printf_colors.h" 
# include "keys.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_img_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*type;
	int		size;
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	pos_a;
	double	pos_b;
	double	abs_x;
	double	abs_y;
	int		color;
	char	**argv;
}	t_img_data;

typedef struct s_fract
{
	int		i;
	int		x;
	int		y;
	double	a;
	double	aa;
	double	b;
	double	bb;
	double	tmp_a;
	double	tmp_b;
	double	tmp;
}	t_fract;

char	*ft_check_input(char *argv);
void	ft_launch_header(void);
void	ft_initials_errors(void);
void	ft_init(t_img_data *data);
void	ft_start_fract(t_img_data data);
void	ft_mandelbrot(t_img_data data);
void	ft_mandelbar(t_img_data data);
void	ft_julia(t_img_data data);
void	ft_burning_ship(t_img_data data);
void	ft_buffalo(t_img_data data);
int		key_hook(int keycode, t_img_data *data);
double	ft_scale(int size, int point, double max, double min);
void	ft_resolve_mandelbrot(t_img_data data, t_fract *fract);
void	ft_resolve_mandelbar(t_img_data data, t_fract *fract);
void	ft_resolve_julia(t_img_data data, t_fract *fract);
void	ft_resolve_burning_ship(t_img_data data, t_fract *fract);
void	ft_resolve_buffalo(t_img_data data, t_fract *fract);
void	ft_set_new_color(int keycode, t_img_data *data);
void	ft_solve_color(t_img_data data, t_fract fract);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
char	*ft_clear_str(char *fract);
int		zoom(int keycode, int x, int y, t_img_data *data);
void	ft_move_pos(int keycode, t_img_data *data);
double	ft_fabs(double num);
double ft_atof(const char *s);

#endif