/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:15:27 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/28 12:32:27 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

double	ft_fabs(double num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

static int	ft_isdigit_double(int c)
{
	if (c == '-')
		return (1);
	if ((c < 48 || c > 57) && c != '.')
		return (0);
	return (1);
}

static int	check_neg(int *neg, char c)
{
	if (c == '-')
	{
		*neg = -1;
		return (1);
	}
	return (0);
}

double	ft_atof(const char *str)
{
	double	out;
	int		neg_decimal[2];

	neg_decimal[0] = 0;
	neg_decimal[1] = 1;
	out = 0.0;
	if (check_neg(&neg_decimal[1], *str))
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			str++;
			neg_decimal[0] = 10;
		}
		if (!neg_decimal[0] && ft_isdigit_double(*str))
			out = out * 10 + (*str - '0');
		else if (neg_decimal[0] && ft_isdigit_double(*str))
		{
			out = out + ((double)(*str - '0') / neg_decimal[0]);
			neg_decimal[0] *= 10;
		}
		str++;
	}
	return (out * neg_decimal[1]);
}
