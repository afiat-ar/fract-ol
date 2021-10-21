/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:52:46 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/20 13:31:56 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	ft_set_new_color(int keycode, t_img_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (keycode == NUM_1)
		data->color = 4096;
	if (keycode == NUM_2)
		data->color = 14048738;
	if (keycode == NUM_3)
		data->color = 14848861;
	if (keycode == NUM_4)
		data->color = 1501403;
	if (keycode == NUM_5)
		data->color = 15210178;
	if (keycode == NUM_6)
		data->color = 11274505;
	ft_start_fract(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	ft_move_pos(int keycode, t_img_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (keycode == ARROW_UP)
	{
		data->max_y += (data->max_y - data->min_y) / data->size * 100;
		data->min_y += (data->max_y - data->min_y) / data->size * 100;
	}
	if (keycode == ARROW_DOWN)
	{
		data->max_y -= (data->max_y - data->min_y) / data->size * 100;
		data->min_y -= (data->max_y - data->min_y) / data->size * 100;
	}
	if (keycode == ARROW_RIGHT)
	{
		data->max_x -= (data->max_x - data->min_x) / data->size * 100;
		data->min_x -= (data->max_x - data->min_x) / data->size * 100;
	}
	if (keycode == ARROW_LEFT)
	{
		data->max_x += (data->max_x - data->min_x) / data->size * 100;
		data->min_x += (data->max_x - data->min_x) / data->size * 100;
	}
	ft_start_fract(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
