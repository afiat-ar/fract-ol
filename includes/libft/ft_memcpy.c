/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:10:13 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/06/01 10:49:11 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c;

	c = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		c[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (c);
}
