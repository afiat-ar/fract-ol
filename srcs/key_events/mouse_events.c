/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:52:30 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/20 13:03:05 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	zoom(int keycode, int x, int y, t_img_data *data)
{
	/*double		interpolation;
	double		zoom;
	double		mouse_x;
	double		mouse_y;
	double		mid_x;
	double		mid_y;

	if (keycode == 4 || keycode == 5)
	{
		mlx_clear_window(data->mlx, data->win);
		if (keycode == 5)
			{
				printf ("zoom in\n");
				data->max_x -= data->max_x / data->size * 120;
				data->max_y -= data->max_y / data->size * 120;
				data->min_x -= data->min_x / data->size * 120;
				data->min_y -= data->min_y / data->size * 120;
			}
			if (keycode == 4)
			{
				printf ("zoom out\n");
				data->max_x += data->max_x / data->size * 120;
				data->max_y += data->max_y / data->size * 120;
				data->min_x += data->min_x / data->size * 120;
				data->min_y += data->min_y / data->size * 120;
			}
			mouse_x = ft_scale(data->size, x, data->max_x, data->min_x);
			mouse_y = ft_scale(data->size, y, data->max_x, data->min_x);
			mid_x = data->max_x - (data->max_x - data->min_x)/2;
			mid_y = data->max_y - (data->max_y - data->min_y)/2;
			if (mid_y < mouse_y && mid_x > mouse_x)
			{
				printf("up-left\n");
				data->max_y += (data->max_y - data->min_y) / data->size * 60;
				data->min_y += (data->max_y - data->min_y) / data->size * 60;
				data->max_x += (data->max_x - data->min_x) / data->size * 60;
				data->min_x += (data->max_x - data->min_x) / data->size * 60;
			}
			if (mid_x < mouse_x && mid_y < mouse_y)
			{
				printf("down-right\n");
				data->max_y += (data->max_y - data->min_y) / data->size * 60;
				data->min_y += (data->max_y - data->min_y) / data->size * 60;
				data->max_x -= (data->max_x - data->min_x) / data->size * 60;
				data->min_x -= (data->max_x - data->min_x) / data->size * 60;
			}
			if (mid_y > mouse_y && mid_x > mouse_x)
			{
				printf("down-left\n");
				data->max_y -= (data->max_y - data->min_y) / data->size * 60;
				data->min_y -= (data->max_y - data->min_y) / data->size * 60;
				data->max_x += (data->max_x - data->min_x) / data->size * 60;
				data->min_x += (data->max_x - data->min_x) / data->size * 60;
			}
			if (mid_y > mouse_y && mid_x < mouse_x)
			{
				printf("up-right\n");
				data->max_y -= (data->max_y - data->min_y) / data->size * 60;
				data->min_y -= (data->max_y - data->min_y) / data->size * 60;
				data->max_x -= (data->max_x - data->min_x) / data->size * 60;
				data->min_x -= (data->max_x - data->min_x) / data->size * 60;
			}
			ft_start_fract(*data);
			mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}*/
	return (0);
}
