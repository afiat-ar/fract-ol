/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:01:11 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/20 12:48:09 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	key_hook(int keycode, t_img_data *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode >= 18 && keycode <= 23)
		ft_set_new_color(keycode, data);
	if (keycode >= 123 && keycode <= 126)
		ft_move_pos(keycode, data);
	return (0);
}
