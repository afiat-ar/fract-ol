/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:52:46 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/28 10:14:39 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	ft_set_new_color(int keycode, t_img_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (keycode == NUM_1)
		data->color = 1;
	if (keycode == NUM_2)
		data->color = 2;
	if (keycode == NUM_3)
		data->color = 3;
	if (keycode == NUM_4)
		data->color = 4;
	if (keycode == NUM_5)
		data->color = 5;
	if (keycode == NUM_6)
		data->color = 6;
	ft_start_fract(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	ft_move_pos(int keycode, t_img_data *data)
{
	data->abs_x = (data->max_x - data->min_x) / 500;
	data->abs_y = (data->max_y - data->min_y) / 500;
	mlx_clear_window(data->mlx, data->win);
	if (keycode == ARROW_UP)
	{
		data->max_y += data->abs_y * 24;
		data->min_y += data->abs_y * 24;
	}
	if (keycode == ARROW_DOWN)
	{
		data->max_y -= data->abs_y * 24;
		data->min_y -= data->abs_y * 24;
	}
	if (keycode == ARROW_RIGHT)
	{
		data->max_x -= data->abs_x * 24;
		data->min_x -= data->abs_x * 24;
	}
	if (keycode == ARROW_LEFT)
	{
		data->max_x += data->abs_x * 24;
		data->min_x += data->abs_x * 24;
	}
	ft_start_fract(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
