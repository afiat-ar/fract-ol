/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:17:54 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/28 09:49:13 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	ft_purple(void)
{
	printf("\033[0;35m");
}

void	ft_white(void)
{
	printf("\033[0;37m");
}

void	ft_red(void)
{
	printf("\033[0;31m");
}

void	ft_green(void)
{
	printf("\033[0;32m");
}
