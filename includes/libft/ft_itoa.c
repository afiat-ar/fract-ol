/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:40:06 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/06/03 13:39:07 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
		size = 1;
	while (1)
	{
		n /= 10;
		size++;
		if (n == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	long	number;

	number = n;
	i = ft_len(n);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	str[i] = '\0';
	while (1)
	{
		str[i - 1] = (number % 10) + '0';
		number /= 10;
		i--;
		if (number == 0)
			break ;
	}
	return (str);
}
