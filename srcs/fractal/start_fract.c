/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andoni <andoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:22:29 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/22 10:14:56 by andoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	ft_start_fract(t_img_data data)
{
	if (!ft_strncmp(data.type, "mandelbrot", ft_strlen(data.type) + 1))
		ft_mandelbrot(data);
	if (!ft_strncmp(data.type, "mandelbar", ft_strlen(data.type) + 1))
		ft_mandelbar(data);
	if (!ft_strncmp(data.type, "burning ship", ft_strlen(data.type) + 1))
		ft_burning_ship(data);
	if (!ft_strncmp(data.type, "perpendicular buffalo", ft_strlen(data.type) + 1))
		ft_buffalo(data);
	if (!ft_strncmp(data.type, "julia", ft_strlen(data.type) + 1))
		ft_julia(data);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_solve_color(t_img_data data, t_fract fract)
{
	if (fract.i == 100)
		my_mlx_pixel_put(&data, fract.x, fract.y, 0x000000);
	else if (fract.i < 100 && fract.i >= 50)
		my_mlx_pixel_put(&data, fract.x, fract.y, data.color * fract.i * 1.5);
	else if (fract.i < 50)
		my_mlx_pixel_put(&data, fract.x, fract.y, data.color * fract.i * 2);
	else if (fract.i < 20)
		my_mlx_pixel_put(&data, fract.x, fract.y, data.color + fract.i);
}

double	ft_scale(int size, int point, double max, double min)
{
	double	abs_scale;
	double	result;

	abs_scale = max - min;
	max *= -1;
	result = max + ((abs_scale / size) * point);
	return (result);
}