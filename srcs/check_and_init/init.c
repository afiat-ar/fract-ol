/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:02:19 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/27 12:21:01 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	ft_init(t_img_data *data)
{
	data->size = 750;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->size, data->size, data->type);
	data->img = mlx_new_image(data->mlx, data->size, data->size);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	data->max_x = 2;
	data->min_x = -2;
	data->max_y = 2;
	data->min_y = -2;
	data->color = 1;
}
