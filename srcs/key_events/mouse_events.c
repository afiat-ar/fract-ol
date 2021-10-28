/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:52:30 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/28 10:19:08 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

static void	increase(t_img_data *ptr, int x, int y)
{
	double	x_coord;
	double	y_coord;

	x_coord = -ft_scale(ptr->size, x, ptr->max_x, ptr->min_x);
	y_coord = -ft_scale(ptr->size, y, ptr->max_y, ptr->min_y);
	if (y_coord - (ptr->max_y - (ptr->max_y - ptr->min_y) / 2) >= 0)
	{
		ptr->max_y += ptr->abs_y * 24;
		ptr->min_y += ptr->abs_y * 24;
	}
	else if ((y_coord - ptr->max_y - (ptr->max_y - ptr->min_y) / 2) < 0)
	{
		ptr->max_y -= ptr->abs_y * 24;
		ptr->min_y -= ptr->abs_y * 24;
	}
	if (x_coord - (ptr->max_x - (ptr->max_x - ptr->min_x) / 2) >= 0)
	{
		ptr->max_x += ptr->abs_x * 24;
		ptr->min_x += ptr->abs_x * 24;
	}
	else if ((x_coord - ptr->max_x - (ptr->max_x - ptr->min_x) / 2) < 0)
	{
		ptr->max_x -= ptr->abs_x * 24;
		ptr->min_x -= ptr->abs_x * 24;
	}
}

static void	zoom_2(int button, int x, int y, t_img_data *ptr)
{
	double	x_coord;
	double	y_coord;

	ptr->abs_x = (ptr->max_x - ptr->min_x) / 500;
	ptr->abs_y = (ptr->max_y - ptr->min_y) / 500;
	x_coord = -ft_scale(ptr->size, x, ptr->max_x, ptr->min_x);
	y_coord = -ft_scale(ptr->size, y, ptr->max_y, ptr->min_y);
	if (button == 5)
	{
		ptr->max_x += ptr->abs_x * 24;
		ptr->min_x -= ptr->abs_x * 24;
		ptr->max_y += ptr->abs_y * 24;
		ptr->min_y -= ptr->abs_y * 24;
		increase(ptr, x, y);
	}
}

int	zoom(int button, int x, int y, t_img_data *ptr)
{
	double	x_coord;
	double	y_coord;

	mlx_clear_window(ptr->mlx, ptr->win);
	ptr->abs_x = (ptr->max_x - ptr->min_x) / 500;
	ptr->abs_y = (ptr->max_y - ptr->min_y) / 500;
	x_coord = -ft_scale(ptr->size, x, ptr->max_x, ptr->min_x);
	y_coord = -ft_scale(ptr->size, y, ptr->max_y, ptr->min_y);
	if (button == 4)
	{
		ptr->max_x -= ft_fabs(ptr->abs_x) * 24;
		ptr->min_x += ft_fabs(ptr->abs_x) * 24;
		ptr->max_y -= ft_fabs(ptr->abs_y) * 24;
		ptr->min_y += ft_fabs(ptr->abs_y) * 24;
		increase(ptr, x, y);
	}
	else if (button == 5)
		zoom_2(button, x, y, ptr);
	ft_start_fract(*ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (1);
}
