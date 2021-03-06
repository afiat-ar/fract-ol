/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:34:08 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/28 12:20:32 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

static void	ft_check_julia(t_img_data data, t_fract *fract)
{
	if (data.argv[2] && data.argv[3])
	{
		fract->tmp_a = ft_atof(data.argv[2]);
		fract->tmp_b = ft_atof(data.argv[3]);
	}
	if (!fract->tmp_a)
		fract->tmp_a = 0.835;
	if (!fract->tmp_b)
		fract->tmp_b = -0.2321;
}

void	ft_resolve_julia(t_img_data data, t_fract *fract)
{
	int	max_iter;

	max_iter = 50;
	fract->i = 0;
	fract->a = ft_scale(data.size, fract->x, data.max_x, data.min_x);
	fract->b = -ft_scale(data.size, fract->y, data.max_y, data.min_y);
	fract->aa = 0.0;
	fract->bb = 0.0;
	ft_check_julia(data, fract);
	while (fract->i < max_iter)
	{
		fract->aa = (fract->a * fract->a) - (fract->b * fract->b);
		fract->bb = 2 * fract->a * fract->b;
		fract->a = fract->aa - fract->tmp_a;
		fract->b = fract->bb - fract->tmp_b;
		if (fract->aa + fract->bb > 16.0 || fract->aa + fract->bb < -16.0)
			break ;
		fract->i++;
	}
}

void	ft_julia(t_img_data data)
{
	t_fract	fract;

	fract.i = 0;
	fract.x = 0;
	fract.y = 0;
	fract.a = 1.0;
	fract.aa = 0.0;
	fract.b = 1.0;
	fract.bb = 0.0;
	fract.tmp_a = 0;
	fract.tmp_b = 0;
	while (fract.x < data.size)
	{
		fract.y = 0;
		while (fract.y < data.size)
		{
			ft_resolve_julia(data, &fract);
			ft_solve_color(data, fract);
			fract.y++;
		}
		fract.x++;
	}
}
