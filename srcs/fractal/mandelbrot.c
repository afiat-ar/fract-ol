/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:34:06 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/19 16:41:54 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	ft_resolve_mandelbrot(t_img_data data, t_fract *fract)
{
	int	max_iter;

	max_iter = 50;
	fract->i = 0;
	fract->a = ft_scale(data.size, fract->x, data.max_x, data.min_x);
	fract->b = ft_scale(data.size, fract->y, data.max_y, data.min_y);
	fract->aa = fract->a;
	fract->bb = fract->b;
	while (fract->aa * fract->aa + fract->bb * fract->bb < 4 && fract->i < max_iter)
	{
		fract->tmp_a = fract->aa * fract->aa - fract->bb * fract->bb + fract->a;
		fract->bb = 2*fract->aa * fract->bb + fract->b;
		fract->aa = fract->tmp_a;
		fract->i++;
	}
}

void	ft_mandelbrot(t_img_data data)
{
	t_fract	fract;

	fract.i = 0;
	fract.x = 0;
	fract.y = 0;
	fract.a = 1.0;
	fract.aa = 0.0;
	fract.b = 1.0;
	fract.bb = 0.0;

	while (fract.x < data.size)
	{
		fract.y = 0;
		while (fract.y < data.size)
		{
			ft_resolve_mandelbrot(data, &fract);
			ft_solve_color(data, fract);
			fract.y++;
		}
		fract.x++;
	}
}