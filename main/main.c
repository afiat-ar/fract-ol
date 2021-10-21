/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:19:34 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/14 11:10:36 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	main(int argc, char *argv[])
{
	t_img_data	data;

	ft_launch_header();
	if (argc > 1)
	{
		data.type = ft_check_input(argv[1]);
		data.argv = argv;
		if (!data.type)
			return (0);
		ft_init(&data);
		ft_start_fract(data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_mouse_hook(data.win, zoom, &data);
		mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
		mlx_loop(data.mlx);
	}
	else
		ft_initials_errors();
	return (0);
}
